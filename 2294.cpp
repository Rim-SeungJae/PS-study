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
		arr[coin] = 1;
		for(int j=coin+1;j<=k;j++)
		{
			if(arr[j-coin] != 0 && (arr[j] == 0 || arr[j] > arr[j-coin]+1))
			{
				arr[j] = arr[j-coin] + 1;
			}
		}
	}
	if(arr[k] == 0) printf("-1");
	else printf("%d",arr[k]);
}
/*
´ÙÀÌ³ª¹Í
*/ 
