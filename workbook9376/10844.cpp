#include<cstdio>

int arr[100][10];

int main()
{
	int n;
	scanf("%d",&n);
	arr[1][0] = 0;
	arr[1][1] = arr[1][2] = arr[1][3] = arr[1][4] = arr[1][5] = arr[1][6] = arr[1][7] = arr[1][8] = arr[1][9] = 1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<9;j++)
		{
			arr[i][j] = (arr[i-1][j-1]%1000000000 + arr[i-1][j+1]%1000000000)%1000000000;
		}
		arr[i][0] = arr[i-1][1];
		arr[i][9] = arr[i-1][8];
	}
	int sum = 0;
	for(int i=0;i<10;i++)
	{
		sum+=arr[n][i]%1000000000;
		sum%=1000000000;
	}
	printf("%d",sum);
}
/*
기본적인 다이나믹
*/ 
