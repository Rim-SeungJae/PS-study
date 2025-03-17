#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<int>> graph(n+1,vector<int>());
    vector<int> in(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        in[b]++;
    }
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i] == 0) q.push(-i);
    }
    while(!q.empty())
    {
        int cur = -q.top();
        q.pop();
        printf("%d ",cur);
        for(int j=0;j<graph[cur].size();j++)
        {
            int nxt = graph[cur][j];
            in[nxt]--;
            if(!in[nxt])
            {
                q.push(-nxt);
            }
        }
    }
}