#include<cstdio>
#include<queue>

using namespace std;

int g[110],visited[110];

void bfs()
{
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int i=1;i<=6 && cur+i<=100;i++)
		{
			int next = cur+i;
			if(g[cur+i]!=0)
			{
				next = g[cur+i];
			}
			if(visited[next] == 0 || visited[next] > visited[cur]+1)
			{
				visited[next] = visited[cur]+1;
				q.push(next);
			}
		}
		//printf("%d\n",cur);
	}
	
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		g[a] = b;
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		g[a] = b;
	}
	bfs();
	printf("%d",visited[100]-1);
}
/*
°£´ÜÇÑ bfs
*/ 
