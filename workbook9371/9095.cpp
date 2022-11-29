#include<cstdio>
int main()
{
	int arr[20] = {0,},t;
	scanf("%d",&t);
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	for(int j=1;j<11;j++)
	{
		arr[j+1] += arr[j];
		arr[j+2] += arr[j];
		arr[j+3] += arr[j];
	}	
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",arr[n]);
	}
}
/*
다이나믹 기초
*/ 
