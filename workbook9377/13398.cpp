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
���̳��� 
dp[i][0]���� ���� �ϳ��� �ǳʶ� ���ӵ� ������ �ִ�����,
dp[i][1]���� �ǳʶ��� �ʰ� ���ӵ� ������ �ִ����� ����ȴ�.
(24�࿡�� else if�� ������� �ʵ��� �����Ұ�)
*/ 
