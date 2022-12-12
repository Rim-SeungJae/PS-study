#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n,arr[1010],dp[1010][2],max_len;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j] < arr[i] && dp[i][0] < dp[j][0] + 1)
			{
				dp[i][0] = dp[j][0]+1;
			}
			else if(arr[j] > arr[i] && dp[i][1] < max(dp[j][0],dp[j][1]) + 1)
			{
				dp[i][1] = max(dp[j][1],dp[j][0]) + 1;
			}
		}
		if(dp[i][0] > max_len) max_len = dp[i][0];
		else if(dp[i][1] > max_len) max_len = dp[i][1];
		//printf("%d %d\n",dp[i][0],dp[i][1]);
	}
	printf("%d",max_len+1);
}
/*
다이나믹
dp[i][0]에는 가장 긴 증가하는 부분수열의 길이가,
dp[i][1]에는 가장 긴 바이토닉 부분수열의 길이가 저장된다.
*/ 
