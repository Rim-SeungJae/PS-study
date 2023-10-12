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
´ÙÀÌ³ª¹Í
*/ 
