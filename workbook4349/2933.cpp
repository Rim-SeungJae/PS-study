#include<cstdio>
#include<algorithm>
using namespace std;

int dx[4] = {0,-1,0,1}, dy[4] = {1,0,-1,0},thr[2] = {1,-1},low[110] = {0,};
int r,c,n,dir;
char arr[110][110],tmp_arr[110][110];
bool visited[110][110], isStable;

void dfs(int x,int y)
{
	if(x<0 || y<0 || x>=r || y>=c) return;
	if(x > low[y]) low[y] = x;
	if(low[y] == r-1) isStable = true;
	for(int i=0;i<4;i++)
	{
		if(!visited[x+dx[i]][y+dy[i]] && arr[x+dx[i]][y+dy[i]] == 'x')
		{
			visited[x+dx[i]][y+dy[i]] = true;
			dfs(x+dx[i],y+dy[i]);
		}
	}
	return;
}

void tmp_fall(int x,int y,int gap)
{
	if(x<0 || y<0 || x>=r || y>=c) return;
	tmp_arr[x+gap][y] = 'x';
	arr[x][y] = '.';
	for(int i=0;i<4;i++)
	{
		if(!visited[x+dx[i]][y+dy[i]] && arr[x+dx[i]][y+dy[i]] == 'x')
		{
			visited[x+dx[i]][y+dy[i]] = true;
			tmp_fall(x+dx[i],y+dy[i],gap);
		}
	}
	return;
}

void fall(int x,int y,int gap)
{
	fill(&tmp_arr[0][0],&tmp_arr[109][110],'.');
	tmp_fall(x,y,gap);
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(tmp_arr[i][j] == 'x')
			{
				arr[i][j] = 'x';
			}
		}
	}
}

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
		arr[r-h][idx] = '.';
		dir ^= 1;
		fill(&visited[0][0],&visited[109][110],0);
		for(int j=0;j<4;j++)
		{
			if(r-h+dx[j]<0 || r-h+dx[j]>=r || idx+dy[j]<0 || idx+dy[j]>=c) continue;
			if(arr[r-h+dx[j]][idx+dy[j]] == '.') continue;
			if(visited[r-h+dx[j]][idx+dy[j]]) continue;
			visited[r-h+dx[j]][idx+dy[j]] = true;
			fill(&low[0],&low[110],-1);
			isStable = false;
			dfs(r-h+dx[j],idx+dy[j]);
			/*
			printf("%d %d:",r-h+dx[j],idx+dy[j]);
			for(int k=0;k<c;k++)
			{
				printf("%d ",low[k]);
			}
			printf("\n");
			*/
			if(!isStable)
			{
				int gap = 110;
				for(int k=0;k<c;k++)
				{
					if(low[k]>=0)
					{
						int l;
						for(l=1;low[k]+l<r;l++)
						{
							if(arr[low[k]+l][k]=='x') break;
						}
						if(l-1<gap) gap = l-1;
					}
				}
				fill(&visited[0][0],&visited[109][110],0);
				fall(r-h+dx[j],idx+dy[j],gap);
				break;
			}
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
/*
구현 시뮬레이션
*/ 
