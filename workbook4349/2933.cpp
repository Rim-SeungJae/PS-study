#include<cstdio>
using namespace std;

int dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0},thr[2] = {1,-1};
int r,c,n,dir;
char arr[110][110];

int main()
{
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++)
	{
		scanf("\n");
		for(int j=0;j<c;j++)
		{
			scanf("%1c",&arr[i][j]);
		}
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int h;
		scanf("%d",&h);
		int idx;
		for(idx=dir * c;idx!=c - dir*c;idx+=thr[dir])
		{
			if(arr[r-h][idx] == 'x') break;
		}
		printf("%d\n",idx);
		arr[r-h][idx] = '.';
		dir ^= 1;
		for(int j=0;j<3;j++)
		{
			
		}
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}

}
