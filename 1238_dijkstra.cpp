#include<cstdio>
#include<vector>
#include<queue>

#define ii pair<int,int>

using namespace std;

int main()
{
    int n,m,x;
    scanf("%d %d %d",&n,&m,&x);
    vector<vector<ii>> graph(n+1,vector<ii>());
    vector<vector<ii>> rgraph(n+1,vector<ii>());
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        graph[a].push_back(make_pair(b,w));
        rgraph[b].push_back(make_pair(a,w));
    }
    priority_queue<ii> pq;
    vector<int> dist(n+1,1000000000);
    pq.push(make_pair(0,x));
    dist[x] = 0;
    while(!pq.empty())
    {
        int cur,d;
        d = -pq.top().first;
        cur = pq.top().second;
        pq.pop();
        if(d!=dist[cur]) continue;
        for(int i=0;i<graph[cur].size();i++)
        {
            int nxt,w;
            nxt = graph[cur][i].first;
            w = graph[cur][i].second;
            if(dist[nxt] > d + w)
            {
                dist[nxt] = d+w;
                pq.push(make_pair(-(d+w),nxt));
            }
        }
    }
    vector<int> rdist(n+1,1000000000);
    pq.push(make_pair(0,x));
    rdist[x] = 0;
    while(!pq.empty())
    {
        int cur,d;
        d = -pq.top().first;
        cur = pq.top().second;
        pq.pop();
        if(d!=rdist[cur]) continue;
        for(int i=0;i<rgraph[cur].size();i++)
        {
            int nxt,w;
            nxt = rgraph[cur][i].first;
            w = rgraph[cur][i].second;
            if(rdist[nxt] > d + w)
            {
                rdist[nxt] = d+w;
                pq.push(make_pair(-(d+w),nxt));
            }
        }
    }
    int max = 0;
    for(int i=1;i<=n;i++)
    {
        if(max < dist[i] + rdist[i]) max = dist[i] + rdist[i];
    }
    printf("%d",max);
}