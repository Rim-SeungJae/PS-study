#include<cstdio>
#include<vector>
#include<queue>

#define ii pair<int,int>

using namespace std;

int main()
{
    int n,m;
    scanf("%d\n%d",&n,&m);
    vector<vector<ii>> graph(n+1,vector<ii>());
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        graph[a].push_back(make_pair(b,w));
    }
    int src,dst;
    scanf("%d %d",&src,&dst);
    priority_queue<ii> pq;
    vector<int> dist(n+1,1000000000);
    pq.push(make_pair(0,src));
    dist[src] = 0;
    while(!pq.empty())
    {
        int cur,d;
        d = -pq.top().first;
        cur = pq.top().second;
        pq.pop();
        if(d != dist[cur]) continue;
        for(int i=0;i<graph[cur].size();i++)
        {
            int w = graph[cur][i].second;
            int nxt = graph[cur][i].first;
            if(dist[nxt] > d + w)
            {
                dist[nxt] = d+w;
                pq.push(make_pair(-(d+w),nxt));
            }
        }
    }
    printf("%d",dist[dst]);
}