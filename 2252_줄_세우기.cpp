#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n,m;
	vector<vector<int>> graph;
	int in[32010]={0,};
	queue<int> q;
	scanf("%d %d",&n,&m);
	graph.assign(n+1,vector<int>());
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		in[b]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(in[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		int target = q.front();
		printf("%d ",target);
		q.pop();
		for(int i=0;i<graph[target].size();i++)
		{
			in[graph[target][i]] -= 1;
			if(in[graph[target][i]] == 0) q.push(graph[target][i]);
		}
	}
}
/*
위상정렬
*/ 

