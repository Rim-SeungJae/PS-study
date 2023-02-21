#include<cstdio>
#include<vector>
#include<set>
#include<queue>

using namespace std;

vector<set<int>> graph;
vector<int> trav;
queue<int> q;
int n,idx,visited[100010];

void bfs()
{
	q.push(trav[0]);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		while(graph[cur].find(trav[idx]) != graph[cur].end())
		{
			int target = trav[idx];
			idx++;
			q.push(target);
		}
	}
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
	idx = 1;
	bfs();
	if(trav[0]!=1) printf("0");
	else if(idx == n) printf("1");
	else printf("0");
}
/*
bfs º¯Çü
*/ 
