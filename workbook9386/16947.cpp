#include<cstdio>
#include<vector>

using namespace std;

int n,dist[3030];
vector<vector<int>> graph;
bool visited[3030], is_cycle[3030];

int FindCycle(int cur,int prv)
{
	int cycle_origin = 0;
	for(int i=0;i<graph[cur].size();i++)
	{
		if(graph[cur][i]!=prv)
		{
			if(visited[graph[cur][i]])
			{
				is_cycle[cur] = true;
				return graph[cur][i];
			}
			else{
				visited[graph[cur][i]] = true;
				cycle_origin = FindCycle(graph[cur][i],cur);
				if(cur == cycle_origin)
				{
					is_cycle[cur] = true;
					return 0;
				}
				else if(cycle_origin != 0)
				{
					is_cycle[cur] = true;
					return cycle_origin;
				}
			}
		}
	}
	return 0;
}

void dfs(int cur,int prv,int depth)
{
	dist[cur] = depth;
	for(int i=0;i<graph[cur].size();i++)
	{
		if(graph[cur][i]!=prv)
		{
			if(!visited[graph[cur][i]] && !is_cycle[graph[cur][i]])
			{
				visited[graph[cur][i]] = true;
				dfs(graph[cur][i],cur,depth+1);
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	graph.assign(n+1,vector<int>());
	for(int i=0;i<n;i++)
	{
		int src,dst;
		scanf("%d %d",&src,&dst);
		graph[src].push_back(dst);
		graph[dst].push_back(src);
	}
	visited[1] = true;
	FindCycle(1,0);
	fill(visited,visited+3001,0);
	for(int i=1;i<=n;i++)
	{
		if(is_cycle[i])
		{
			for(int j=0;j<graph[i].size();j++)
			{
				if(!is_cycle[graph[i][j]])
				{
					dfs(graph[i][j],i,1);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",dist[i]);
	}
}
/*
그래프 탐색 응용
사이클 탐지 및 거리재기
*/ 
