#include<cstdio>

int main()
{
	int n,dp[40] = {0,};
	dp[0] = 1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		dp[i] += dp[i-2] * 3;
		for(int j=i-4;j>=0;j-=2)
		{
			dp[i] += dp[j] * 2;
		}
	}
	printf("%d",dp[n]);
}
/*
다이나믹
타일 배열의 규칙에 대해서 잘 생각해보자.
다이나믹을 짤 때 배열의 범위 바깥에 접근하지 않도록 유의할것.
*/ 
