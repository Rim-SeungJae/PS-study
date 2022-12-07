#include<cstdio>
#include<algorithm>

using namespace std;
int arr[10];
bool used[10];

void bt(int n,int cnt)
{
	if(cnt == n)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			used[i] = true;
			arr[cnt] = i;
			bt(n,cnt+1);
			used[i] = false;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	bt(n,0);
}
/*
브루트포스
기본적인 백트래킹
*/ 
