#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using ii = pair<int,int>;

int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int>> graph(n+1,vector<int>());
    vector<int> time(n+1,0),in(n+1,0),result(n+1,0);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&time[i]);
        int prv;
        scanf("%d",&prv);
        while(prv != -1)
        {
            graph[prv].push_back(i);
            in[i]++;
            scanf("%d",&prv);
        }
    }

    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
            result[i] = time[i];
        }
    }
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int i=0;i<graph[cur].size();i++)
        {
            int nxt = graph[cur][i];
            in[nxt]--;
            if(result[cur] + time[nxt] > result[nxt]) result[nxt] = result[cur] + time[nxt];
            if(in[nxt] == 0) q.push(nxt);
        }
    }

    for(int i=1;i<=n;i++) printf("%d\n",result[i]);
}