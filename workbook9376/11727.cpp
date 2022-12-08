#include<cstdio>

int arr[220][220];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	//arr[n][k] = arr[n][k-1] + arr[n-1][k-1] + arr[n-2][k-1] + ... + arr[0][k-1]
	for(int i=0;i<=200;i++)
	{
		arr[i][1] = 1;
	}
	for(int i=0;i<=200;i++)
	{
		for(int j=2;j<=200;j++)
		{
			for(int k=0;k<=i;k++)
			{
				arr[i][j]+=arr[k][j-1]%1000000000;
				arr[i][j]%=1000000000;
			}
		}
	}
	printf("%d",arr[n][k]);
} 
/*
기본적인 다이나믹
% 연산으로 변수의 크기를 줄이는 점에 주의할것. 
*/ 
