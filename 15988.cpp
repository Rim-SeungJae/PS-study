#include<cstdio>	

int arr[1000010];

int main()
{
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for(int i=4;i<1000001;i++)
	{
		arr[i] = ((arr[i-1] + arr[i-2])%1000000009 + arr[i-3])%1000000009;
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",arr[n]);
	}
}
