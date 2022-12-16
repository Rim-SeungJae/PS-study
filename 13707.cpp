#include<cstdio>
int sum[5005][5005]; 

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	//arr[n][k] = arr[n][k-1] + arr[n-1][k-1] + arr[n-2][k-1] + ... + arr[0][k-1]
	sum[0][1] = 1;
	for(int i=1;i<=5000;i++)
	{
		sum[i][1] = sum[i-1][1] + 1;
		sum[0][i] = 1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=k;j++)
		{
			
			sum[i][j] = (sum[i-1][j]%1000000000 + sum[i][j-1]%1000000000)%1000000000;
			/*
			for(int k=0;k<=i;k++)
			{
				arr[i][j]+=arr[k][j-1]%1000000000;
				arr[i][j]%=1000000000;
			}
			*/
		}
	}
	printf("%d",sum[n][k-1]%1000000000);
} 
/*
기본적인 다이나믹 
누적합은 미리 sum[i][j]에 계산해놓는게 빠르다. 
*/ 
