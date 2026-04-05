#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 2000000000

using namespace std;

int main()
{
    int v,e,k;
    scanf("%d %d",&v,&e);
    scanf("%d",&k);
    vector<vector<pair<int,int>>> g(v+1,vector<pair<int,int>>());
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
    }
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,k));
    vector<int> d(v+1,0);
    fill(d.begin(),d.end(),INF);
    d[k] = 0;

    while(!pq.empty())
    {
        int dist,cur;
        dist = -pq.top().first;
        cur = pq.top().second;
        pq.pop();
        for(int i=0;i<g[cur].size();i++)
        {
            int nxt = g[cur][i].first;
            int w = g[cur][i].second;
            if(d[nxt] > dist + w)
            {
                d[nxt] = dist+w;
                pq.push({-d[nxt],nxt});
            }
        }
    }

    for(int i=1;i<=v;i++)
    {
        if(d[i] == INF) printf("INF\n");
        else printf("%d\n",d[i]);
    }
}