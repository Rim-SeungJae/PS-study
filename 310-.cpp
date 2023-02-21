#include<cstdio>

int arr[110][110], headx=0, heady=0, tailx=0, taily=0, cnt, n;
int dirx[4] = {-1,0,1,0}, diry[4] = {0,1,0,-1};
bool bstop = false;

void move(int dir, int sec)
{
	while(true)
	{
		if(cnt>=sec) return;
		headx+=dirx[dir];
		heady+=diry[dir];
		if(headx < 0 || headx > n-1 || heady < 0 || heady > n-1 || arr[headx][heady] == 1)
		{
			bstop = true;
			return;
		}
		else if(arr[headx][heady] == 2)
		{
			arr[headx][heady] = 1;
			printf("%d %d\n",headx,heady);
		}
		else
		{
			arr[headx][heady] = 1;
			printf("%d %d\n",headx,heady);
			arr[tailx][taily] = 0;
			if(arr[tailx+1][taily] == 1) tailx+=1;
			else if(arr[tailx-1][taily] == 1) tailx-=1;
			else if(arr[tailx][taily+1] == 1) taily+=1;
			else if(arr[tailx][taily-1] == 1) taily-=1;
		}
		cnt++;
	}
}

int main()
{
	int k,l;
	scanf("%d\n%d",&n,&k);
	for(int i=0;i<k;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		arr[x-1][y-1] = 2;
	}
	arr[0][0] = 1;
	scanf("%d",&l);
	int dir_cur = 1;
	for(int i=0;i<l;i++)
	{
		int x,c;
		scanf("%d %c",&x,&c);
		printf("dir:%d\n",dir_cur);
		move(dir_cur,x);
		if(bstop) break;
		if(c=='L')
		{
			dir_cur=(dir_cur+3)%4;
		}
		else
		{
			dir_cur=(dir_cur+1)%4;
		}

	}
	printf("%d\n",cnt);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
