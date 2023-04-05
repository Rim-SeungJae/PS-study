#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n,m,k;
int visited[1010][1010][2];
bool arr[1010][1010];

typedef struct node{
	int r,c,broke,d;
	bool isDay;
}Node;


int bfs()
{
	queue<Node> q;
	Node nd;
	nd.r = 0;
	nd.c = 0;
	nd.broke = 1;
	nd.d = 1;
	nd.isDay = true;
	q.push(nd);
	visited[0][0][1] = 1;
	while(!q.empty())
	{
		int r,c,broke,d;
		r = q.front().r;
		c = q.front().c;
		broke = q.front().broke;
		d = q.front().d;
		bool isDay = q.front().isDay;
		//printf("%d %d %d %d\n",r,c,broke,d);
		if(r==n-1 && c==m-1)
		{
			return d;
		}
		q.pop();
		if(r-1>=0)
		{
			Node tmp;
			tmp.r = (r-1);
			tmp.c = (c);
			tmp.isDay = !isDay;
			if(isDay && arr[r-1][c] && broke <=k && (visited[r-1][c][!isDay] == 0 || visited[r-1][c][!isDay] > broke))
			{
				visited[r-1][c][!isDay] = broke+1;
				tmp.broke = (broke+1);
				tmp.d = (d+1);
				q.push(tmp);
			}
			else if(!arr[r-1][c] && (visited[r-1][c][!isDay] == 0 || visited[r-1][c][!isDay] > broke))
			{
				visited[r-1][c][!isDay] = broke;
				tmp.broke=(broke);
				tmp.d=(d+1);
				q.push(tmp);
			}
		}
		if(r+1<n)
		{
			Node tmp;
			tmp.r=(r+1);
			tmp.c=(c);
			tmp.isDay = !isDay;
			if(isDay&&arr[r+1][c] && broke<=k && (visited[r+1][c][!isDay]==0||visited[r+1][c][!isDay]>broke))
			{
				visited[r+1][c][!isDay] = broke+1;
				tmp.broke=(broke+1);
				tmp.d=(d+1);
				q.push(tmp);
			}
			else if(!arr[r+1][c] && (visited[r+1][c][!isDay]==0||visited[r+1][c][!isDay]>broke)){
				visited[r+1][c][!isDay] = broke;
				tmp.broke=(broke);
				tmp.d=(d+1);
				q.push(tmp);
			}
		}
		if(c-1>=0)
		{
			Node tmp;
			tmp.r=(r);
			tmp.c=(c-1);
			tmp.isDay = !isDay;
			if(isDay&&arr[r][c-1] && broke<=k && (visited[r][c-1][!isDay]==0||visited[r][c-1][!isDay]>broke))
			{
				visited[r][c-1][!isDay] = broke+1;
				tmp.broke=(broke+1);
				tmp.d=(d+1);
				q.push(tmp);
			}
			else if(!arr[r][c-1]&& (visited[r][c-1][!isDay]==0||visited[r][c-1][!isDay]>broke)){
				visited[r][c-1][!isDay] = broke;
				tmp.broke=(broke);
				tmp.d=(d+1);
				q.push(tmp);
			}
		}
		if(c+1<m)
		{
			Node tmp;
			tmp.r=(r);
			tmp.c=(c+1);
			tmp.isDay = !isDay;
			if(isDay&&arr[r][c+1] && broke<=k && (visited[r][c+1][!isDay]==0||visited[r][c+1][!isDay]>broke))
			{
				visited[r][c+1][!isDay] = broke+1;
				tmp.broke=(broke+1);
				tmp.d=(d+1);
				q.push(tmp);
			}
			else if(!arr[r][c+1] && (visited[r][c+1][!isDay]==0||visited[r][c+1][!isDay]>broke)){
				visited[r][c+1][!isDay] = broke;
				tmp.broke=(broke);
				tmp.d=(d+1);
				q.push(tmp);
			}
		}
		if(visited[r][c][!isDay] == 0||visited[r][c][!isDay]>broke)
		{
			Node tmp;
			tmp.r=(r);
			tmp.c=(c);
			tmp.isDay = !isDay;
			visited[r][c][!isDay] = broke;
			tmp.broke=(broke);
			tmp.d=(d+1);
			q.push(tmp);
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	printf("%d",bfs());
}

