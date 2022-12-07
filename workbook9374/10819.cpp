#include<cstdio>
#include<cmath>

int arr[10],sn[100],max = 0;
bool used[10];

void bt(int n,int cnt)
{
	if(n == cnt)
	{
		int sum=0;
		for(int i=0;i<n-1;i++)
		{
			sum+=abs(sn[i] - sn[i+1]);
		}
		if(max<sum) max = sum;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!used[i])
		{
			used[i] = true;
			sn[cnt] = arr[i];
			bt(n,cnt+1);
			used[i] = false;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bt(n,0);
	printf("%d",max);
} 
/*
브루트포스
기본적인 백트래킹
*/ 
