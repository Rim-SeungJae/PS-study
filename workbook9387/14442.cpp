#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n,m,k;
int visited[1010][1010];
bool arr[1010][1010];

typedef struct node{
	int r,c,broke,d;
}Node;


int bfs()
{
	queue<Node> q;
	Node nd;
	nd.r = 0;
	nd.c = 0;
	nd.broke = 1;
	nd.d = 1;
	q.push(nd);
	visited[0][0] = 1;
	while(!q.empty())
	{
		int r,c,broke,d;
		r = q.front().r;
		c = q.front().c;
		broke = q.front().broke;
		d = q.front().d;
		printf("%d %d %d %d\n",r,c,broke,d);
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
			if(arr[r-1][c] && broke <=k && (visited[r-1][c] == 0 || visited[r-1][c] > broke))
			{
				visited[r-1][c] = broke+1;
				tmp.broke = (broke+1);
				tmp.d = (d+1);
				q.push(tmp);
			}
			else if(!arr[r-1][c] && (visited[r-1][c] == 0 || visited[r-1][c] > broke))
			{
				visited[r-1][c] = broke;
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
			if(arr[r+1][c] && broke<=k && (visited[r+1][c]==0||visited[r+1][c]>broke))
			{
				visited[r+1][c] = broke+1;
				tmp.broke=(broke+1);
				tmp.d=(d+1);
				q.push(tmp);
			}
			else if(!arr[r+1][c] && (visited[r+1][c]==0||visited[r+1][c]>broke)){
				visited[r+1][c] = broke;
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
			if(arr[r][c-1] && broke<=k && (visited[r][c-1]==0||visited[r][c-1]>broke))
			{
				visited[r][c-1] = broke+1;
				tmp.broke=(broke+1);
				tmp.d=(d+1);
				q.push(tmp);
			}
			else if(!arr[r][c-1]&& (visited[r][c-1]==0||visited[r][c-1]>broke)){
				visited[r][c-1] = broke;
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
			if(arr[r][c+1] && broke<=k && (visited[r][c+1]==0||visited[r][c+1]>broke))
			{
				visited[r][c+1] = broke+1;
				tmp.broke=(broke+1);
				tmp.d=(d+1);
				q.push(tmp);
			}
			else if(!arr[r][c+1] && (visited[r][c+1]==0||visited[r][c+1]>broke)){
				visited[r][c+1] = broke;
				tmp.broke=(broke);
				tmp.d=(d+1);
				q.push(tmp);
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d",&n,&m);
	k=1; 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	printf("%d",bfs());
}
/*
queue에 vector를 사용하면 시간초과가 난다.
vector의 복사에는 엄청난 시간이 걸린다는 사실을 항상 인지할것
*/ 
