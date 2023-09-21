#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int v,e,dist[10010];
	bool visited[10010]={0,};
	scanf("%d %d",&v,&e);
	fill(&dist[0],&dist[v],1000100);
	vector<vector<pair<int,int>>> g;
	g = vector<vector<pair<int,int>>>(v,vector<pair<int,int>>());
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		g[a-1].push_back(make_pair(b-1,c));
		g[b-1].push_back(make_pair(a-1,c));
	}
	long long res = 0;
	visited[0] = true;
	for(int j=0;j<g[0].size();j++)
	{
		int dst = g[0][j].first, cost = g[0][j].second;
		if(dist[dst] > cost) dist[dst] = cost;
	}
	for(int i=1;i<v;i++)
	{
		int min = 1000100,idx = -1;
		for(int j=0;j<v;j++)
		{
			if(visited[j]==false && dist[j]<min)
			{
				min = dist[j];
				idx = j;
			}
		}
		if(idx != -1)
		{
			res += dist[idx];
			visited[idx] = true;
			for(int j=0;j<g[idx].size();j++)
			{
				int dst = g[idx][j].first, cost = g[idx][j].second;
				if(dist[dst] > cost) dist[dst] = cost;
			}
		}
	}
	printf("%lld",res);
}
/*
minimum spanning tree
*/ 
