#include<cstdio>


int arr[14];
bool selected[14];

void bt(int len,int k,int cur)
{
	if(len == 6)
	{
		for(int i=0;i<k;i++)
		{
			if(selected[i]) printf("%d ",arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i=cur;i<k;i++)
	{
		if(!selected[i])
		{
			selected[i] = true;
			bt(len+1,k,i);
			selected[i] = false;
		}
	}
}

int main()
{
	while(true)
	{
		int k;
		scanf("%d",&k);
		if(k==0) break;
		for(int i=0;i<k;i++)
		{
			scanf("%d",&arr[i]);
		}
		bt(0,k,0);
		printf("\n");
	}
} 
/*
브루트포스
기본적인 백트래킹
*/ 
