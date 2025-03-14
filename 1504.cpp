#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<pair<int,int>>> graph;
priority_queue<pair<int,int>> pq;
int dist[801];

int getDistance(int from, int to)
{
    while(!pq.empty()) pq.pop();
    fill(dist,&dist[801],2000000000);
    pq.push(make_pair(0,from));
    dist[from] = 0;
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        if(distance != dist[cur]) continue;
        for(int i=0;i<graph[cur].size();i++)
        {
            int nxt = graph[cur][i].first;
            int w = graph[cur][i].second;
            if(dist[nxt] > distance + w)
            {
                dist[nxt] = distance + w;
                pq.push(make_pair(-dist[nxt],nxt));
            }
        }
    }
    return dist[to];
}

int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    graph = vector<vector<pair<int,int>>>(n+1,vector<pair<int,int>>());
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    int mid1,mid2;
    scanf("%d %d",&mid1,&mid2);
    int toMid1,toMid2,fromMid1,fromMid2,mid1ToMid2;
    toMid1 = getDistance(1,mid1);
    toMid2 = getDistance(1,mid2);
    fromMid1 = getDistance(mid1,n);
    fromMid2 = getDistance(mid2,n);
    mid1ToMid2 = getDistance(mid1,mid2);

    if(min((long long)toMid2 + mid1ToMid2 + fromMid1, (long long)toMid1 + mid1ToMid2 + fromMid2) >= 2000000000) printf("-1");
    else printf("%d",min((long long)toMid2 + mid1ToMid2 + fromMid1, (long long)toMid1 + mid1ToMid2 + fromMid2));
}