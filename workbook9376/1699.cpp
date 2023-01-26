#include<cstdio>

int arr[100010];

int main()
{
	arr[1] = 1;
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(j*j==i) arr[i] = 1;
			if(arr[i] == 0 || arr[i]>arr[j] + arr[i-j]) arr[i] = arr[j] + arr[i-j];
		}
	}
	printf("%d",arr[n]);
}
