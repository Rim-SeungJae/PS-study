#include<cstdio>

int cnt,n,s,arr[22];

void bt(int sum,int c)
{
	if(sum == s&&c!=-1) cnt++;
	printf("%d ",sum);
	for(int i=c+1;i<n;i++)
	{
		bt(sum + arr[i],i);
	}
}

int main()
{
	scanf("%d %d",&n,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bt(0,-1);
	printf("%d",cnt);
}
/*
기본적인 백트래킹
*/ 
