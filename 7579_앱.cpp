#include<cstdio>
#include<algorithm>

using namespace std;

int N,M,m[110],c[110],dp[110][10010];

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&m[i]);
	}
	int S=0;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&c[i]);
		S+=c[i];
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<=S;j++)
		{
			if(j-c[i]>=0) dp[i][j] = max(dp[i-1][j-c[i]] + m[i],dp[i-1][j]);
			else dp[i][j] = dp[i-1][j];
			//printf("%d ",dp[i][j]);
		}
		//printf("\n");
	}
	for(int i=0;i<=S;i++)
	{
		if(dp[N][i]>=M)
		{
			printf("%d",i);
			break;
		}
	}
}
/*
´ÙÀÌ³ª¹Í - ¹è³¶ ¹®Á¦
*/ 
