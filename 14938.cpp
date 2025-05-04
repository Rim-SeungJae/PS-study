#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
using ii=pair<int,int>;

int main()
{
    int n,m,r;
    scanf("%d %d %d",&n,&m,&r);
    int items[101];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&items[i]);
    }
    vector<vector<ii>> graph(n,vector<ii>());
    for(int i=0;i<r;i++)
    {
        int a,b,l;
        scanf("%d %d %d",&a,&b,&l);
        a--;
        b--;
        graph[a].push_back(make_pair(b,l));
        graph[b].push_back(make_pair(a,l));
    }

    int max = 0;
    for(int i=0;i<n;i++)
    {
        int dist[101];
        fill(dist,dist+101,2000000000);
        dist[i] = 0;
        priority_queue<ii> pq;
        pq.push(make_pair(0,i));
        while(!pq.empty())
        {
            int cur = pq.top().second;
            int path = -pq.top().first;
            pq.pop();
            if(path!=dist[cur]) continue;
            for(int j=0;j<graph[cur].size();j++)
            {
                int nxt = graph[cur][j].first;
                int w = graph[cur][j].second;
                if(dist[nxt] > path+w)
                {
                    dist[nxt] = path+w;
                    pq.push(make_pair(-(path+w),nxt));
                }
            }
        }
        
        int sum = 0;
        for(int j=0;j<n;j++)
        {
            if(dist[j] <= m) sum+=items[j];
        }
        if(max<sum) max = sum;
    }

    printf("%d",max);

}