#include<cstdio>
#include<vector>

using namespace std;

int dir[6][4] = {
{1,2,3,4},
{5,2,0,4},
{1,5,3,0},
{0,2,5,4},
{1,0,3,5},
{3,2,1,4}
};
int chk[6],arr[6][6];
bool visited[6][6];

void search(int x,int y,int cur,int shift)
{
	chk[cur] = true;
	//printf("%d %d %d %d\n",cur,shift,x,y);
	//printf("1 ");
	if(x-1>=0 && !visited[x-1][y])
	{
		int nxt = dir[cur][shift%4];
		int i;
		for(i=2;dir[nxt][i%4]!=cur;i++);
		visited[x-1][y] = true;
		search(x-1,y,nxt,i-2);
	}
	//printf("2 ");
	if(y+1<6 && !visited[x][y+1])
	{
		int nxt = dir[cur][(shift+1)%4];
		int i;
		for(i=3;dir[nxt][i%4]!=cur;i++);
		visited[x][y+1] = true;
		search(x,y+1,nxt,i-3);
	}
	//printf("3 ");
	if(x+1<6 && !visited[x+1][y])
	{
		int nxt = dir[cur][(shift+2)%4];
		int i;
		for(i=0;dir[nxt][i%4]!=cur;i++);
		visited[x+1][y] = true;
		search(x+1,y,nxt,i);
	}
	//printf("4 ");
	if(y-1>=0 && !visited[x][y-1])
	{
		int nxt = dir[cur][(shift+3)%4];
		int i;
		for(i=1;dir[nxt][i%4]!=cur;i++);
		visited[x][y-1] = true;
		search(x,y-1,nxt,i-1);
	}
	//printf("\n");
}

int main()
{
	for(int t=0;t<3;t++)
	{
		fill(chk,chk+6,0);
		fill(&visited[0][0],&visited[5][6],0);
		int x=-1,y=-1;
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				scanf("%d",&arr[i][j]);
				if(arr[i][j] == 0) visited[i][j] = 1;
				if(arr[i][j] == 1 && x==-1)
				{
					x=i;
					y=j;
				}
			}
		}
		visited[x][y] = true;
		search(x,y,0,0);
		bool result=true;
		for(int i=0;i<6;i++)
		{
			result &= chk[i];
		}
		if(result) printf("yes\n");
		else printf("no\n");
	}
}
/*
구현
골드 1 치고 구현이 쉽다.
*/ 
