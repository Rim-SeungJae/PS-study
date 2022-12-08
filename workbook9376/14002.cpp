#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,arr[1010],dp[1010][2];
	vector<int> v;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	dp[0][0] = 0;
	dp[0][1] = 1;
	for(int i=1;i<n;i++)
	{
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		int max_len = 1;
		dp[i][1] = 1;
		for(int j=0;j<i;j++)
		{
			if(arr[j] < arr[i] && max_len < dp[j][1]+1)
			{
				max_len = dp[j][1];
				dp[i][1] = dp[j][1] + 1;
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		printf("%d %d\n",dp[i][0],dp[i][1]);
	}
	printf("%d",max(dp[n-1][0],dp[n-1][1]));
}
