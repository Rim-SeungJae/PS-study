#include<cstdio>
#include<algorithm>

using namespace std;

int dp[16][1<<16],n,w[16][16];

int bt(int cur,int visited)
{
	if(visited == (1<<n) - 1)
	{
		if(w[cur][0] > 0)
		{
			return w[cur][0];
		}
		else return 1000000000;
	}
	if(dp[cur][visited]!=0)
	{
		return dp[cur][visited];
	}
	dp[cur][visited] = 1000000000;
	for(int i=0;i<n;i++)
	{
		if(w[cur][i] > 0 && !(visited & (1 << i)) )
		{
			int tmp;
			tmp = bt(i,visited | (1<<i)) + w[cur][i];
			if(tmp < dp[cur][visited]) dp[cur][visited] = tmp;
		}
	}

	return dp[cur][visited];
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}
	printf("%d",bt(0,1));
}
/*
외판원 순회 문제
dp 배열을 INF로 초기화하면 시간초과가 나는 점에 주의하라
*/ 
