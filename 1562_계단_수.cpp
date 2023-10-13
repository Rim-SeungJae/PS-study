#include<cstdio>

using namespace std;

int dp[110][11][1<<10];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<10;i++)
	{
		dp[1][i][1<<i] = 1;
		//printf("%d %d\n",i,dp[1][i][1<<i]);
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=(1<<10)-1;k>0;k--)
			{
				if(!(k&(1<<j))) continue;
				if(j-1>=0)
				{
					dp[i][j][k] += dp[i-1][j-1][k] % 1000000000;
					dp[i][j][k] += dp[i-1][j-1][k & ~(1<<j)] % 1000000000;
				}
				if(j+1<10)
				{
					dp[i][j][k] += dp[i-1][j+1][k] % 1000000000;
					dp[i][j][k] += dp[i-1][j+1][k & ~(1<<j)] % 1000000000;
				}
				/*
				if(i==10 && j==0 && dp[i][j][k]>0)
				{
					printf("%d %d %d:%d\n",i,j,k,dp[i][j][k]);
					printf("%d %d %d %d\n",dp[i-1][j-1][k],dp[i-1][j-1][k & ~(1<<j)],dp[i-1][j+1][k],dp[i-1][j+1][k & ~(1<<j)]);
				}
				*/
			}
		}
	}
	long long res=0;
	
	for(int i=0;i<10;i++)
	{
		res += dp[n][i][(1<<10)-1];
		res %= 1000000000;
	}

	printf("%lld",res);
}
/*
다이나믹
비트마스킹을 사용하지 않는 방법로:
dp(a,b)를 숫자 a부터 b까지 사용해서 만드는 길의 n인 계단 수의 개수라 하자.
그러면 우리는 dp(0,9)에서 숫자가 1개 이상 사용되지 않은 경우를 모두 빼면
정답을 구할 수 있다.
계단수의 특성상 숫자가 하나 부족한 경우는 0이나 9가 사용되지 않은 경우밖에 없으므 
이는 dp(0,8) + dp(1,9) - dp(1,8)이다.
따라서 dp(0,9) - dp(0,8) - dp(1,9) + dp(1,8)을 구하면 된다. 
*/ 
