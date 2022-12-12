#include<cstdio>
#include<algorithm>

using namespace std;

int arr[100100],dp[100100][2];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%d",&arr[0]);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	dp[0][1] = arr[0];
	dp[0][0] = dp[1][0] = -1111;
	int M=arr[0];
	for(int i=1;i<n;i++)
	{
		if(i>1)dp[i][0] = max(dp[i-2][1] + arr[i],dp[i-1][0]+arr[i]);
		dp[i][1] = max(arr[i],dp[i-1][1] + arr[i]);
		if(dp[i][0]>M) M = dp[i][0];
		if(dp[i][1] > M) M = dp[i][1];
		//printf("%d %d\n",dp[i][0],dp[i][1]);
	}
	printf("%d",M);
}
/*
다이나믹 
dp[i][0]에는 숫자 하나를 건너뛴 연속된 수열의 최대합이,
dp[i][1]에는 건너뛰지 않고 연속된 수열의 최대합이 저장된다.
(24행에서 else if를 사용하지 않도록 주의할것)
*/ 
