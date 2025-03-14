#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

using ii = pair<int,int>;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<ii>> graph(n+1,vector<ii>());
    int maxC=0,minC=1000000001;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
        if(c > maxC) maxC = c;
        if(c < minC) minC = c;
    }

    int src,dst;
    scanf("%d %d",&src,&dst);

    int ans = 0;

    while(minC <= maxC)
    {
        int mid = maxC - (maxC - minC)/2;
        queue<int> q;
        q.push(src);
        bool visited[10001] = {0,};
        visited[src] = true;
        bool isConnected = false;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            if(cur == dst)
            {
                isConnected = true;
                break;
            }
            for(int i=0;i<graph[cur].size();i++)
            {
                int nxt = graph[cur][i].first, limit = graph[cur][i].second;
                if(!visited[nxt] && mid <= limit)
                {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        if(isConnected)
        {
            minC = mid + 1;
            if(ans < mid) ans = mid;
        }
        else{
            maxC = mid - 1;
        }
    }
    printf("%d",ans);
}