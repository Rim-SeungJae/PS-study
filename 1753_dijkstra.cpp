#include<cstdio>
#include<queue>

using namespace std;

int main()
{
    int v,e;
    scanf("%d %d",&v,&e);
    int k;
    scanf("%d",&k);
    vector<vector<pair<int,int>>> g(v+1,vector<pair<int,int>>());
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        g[a].push_back({b,c});
    }
    
    priority_queue<pair<int,int>> pq;
    vector<int> d(v+1,2000000000);
    pq.push({0,k});
    d[k] = 0;

    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        for(int i=0;i<g[cur].size();i++)
        {
            int nxt = g[cur][i].first;
            int w = g[cur][i].second;
            if(dist + w < d[nxt])
            {
                d[nxt] = dist + w;
                pq.push({-d[nxt],nxt});
            }
        }
    }

    for(int i=1;i<=v;i++)
    {
        if(d[i] == 2000000000) printf("INF\n");
        else printf("%d\n",d[i]);
    }
}