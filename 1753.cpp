#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int v,e;
	scanf("%d %d",&v,&e);
	int k;
	scanf("%d",&k);
	k--;
	vector<vector<pair<int,int>>> g = vector<vector<pair<int,int>>>(v,vector<pair<int,int>>());
	for(int i=0;i<e;i++)
	{
		int u, nxt, w;
		scanf("%d %d %d",&u,&nxt,&w);
		g[u-1].push_back(make_pair(w,nxt-1));
	}
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0,k));
	int dist[20020];
	fill(dist,&dist[20000],1000000000);
	dist[k] = 0;
	while(!pq.empty())
	{
		pair<int,int> tmp = pq.top();
		pq.pop();
		int d = -tmp.first;
		int cur = tmp.second;
		if(dist[cur]!=d) continue;
		for(int i=0;i<g[cur].size();i++)
		{
			int nxt = g[cur][i].second;
			int w = g[cur][i].first;
			if(dist[nxt] > d+w)
			{
				dist[nxt] = d+w;
				pq.push(make_pair(-(d+w),nxt));
			}
		}
	}
	for(int i=0;i<v;i++)
	{
		if(dist[i] == 1000000000) printf("INF\n");
		else printf("%d\n",dist[i]);
	}
}
