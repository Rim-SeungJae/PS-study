#include<cstdio>

int arr[10010];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int coin;
		scanf("%d",&coin);
		if(coin>k) continue;
		arr[coin] += 1;
		for(int j=coin+1;j<=k;j++)
		{
			arr[j] += arr[j-coin];
		}
	}
	printf("%d",arr[k]);
}
