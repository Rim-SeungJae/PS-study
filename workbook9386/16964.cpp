#include<cstdio>
#include<vector>
#include<set>

using namespace std;

vector<set<int>> graph;
vector<int> trav;
int n,idx,visited[100010];

void dfs(int cur)
{
	if(graph[cur].find(trav[idx]) != graph[cur].end())
	{
		int target = trav[idx];
		visited[target] = true;
		idx++;
		dfs(target);
		dfs(cur);
	}
	/*
	for(int i=0;i<graph[cur].size();i++)
	{
		int target = graph[cur][i];
		if(!visited[target] && trav[idx] == target)
		{
			visited[target] = true;
			idx++;
			dfs(target);
			if(idx == n) return;
			i=-1;
			continue;
		}
	}
	*/
}

int main()
{
	scanf("%d",&n);
	graph.assign(n+1,set<int>());
	for(int i=0;i<n-1;i++)
	{
		int src,dst;
		scanf("%d %d",&src,&dst);
		graph[src].insert(dst);
		graph[dst].insert(src);
	}
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		trav.push_back(tmp);
	}
	visited[1] = true;
	idx = 1;
	dfs(1);
	if(idx == n) printf("1");
	else printf("0");
}
