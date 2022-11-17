#include<cstdio>
int arr[1000100];
long long int sum[1000100];
int main()
{
	int t,n;
	for(int i=1;i<=1000000;i++)
	{
		for(int j=1;i*j<=1000000;j++)
		{
			arr[i*j] += i;
		}
	}
	for(int i=1;i<=1000000;i++)
	{
	    sum[i] = arr[i] + sum[i-1];
	}
	scanf("%d",&n);
	printf("%lld\n",sum[n]);
}
/*
백준 17427
에라토스테네스의 채 응용 
*/ 
