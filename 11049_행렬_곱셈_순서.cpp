#include<cstdio>
#include<vector>
#include<list>

using namespace std;

int dp[550][550];

int main()
{
	int n,res = 0;
	vector<int> len;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		len.push_back(N);
		if(i==n-1)
		{
			len.push_back(M);
		}
	}
	for(int i=0;i<n-1;i++)
	{
		dp[i][i+1] = len[i] * len[i+1] * len[i+2];
	}
	for(int gap=2;gap<n;gap++)
	{
		for(int i=0;gap+i<n;i++)
		{
			for(int j=i+1;j<=gap+i;j++)
			{
				int tmp = dp[i][j-1] + dp[j][gap+i] + len[i]*len[j]*len[gap+i+1];
				if(dp[i][gap+i]==0 || dp[i][gap+i]>tmp) dp[i][gap+i] = tmp; 
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d",dp[0][n-1]);
}
/*
´ÙÀÌ³ª¹Í
*/ 
