#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void dfs(vector<vector<int>> &g, int cur, vector<bool> &visited)
{
    printf("%d ",cur);
    for(int i=0;i<g[cur].size();i++)
    {
        int nxt = g[cur][i];
        if(!visited[nxt])
        {
            visited[nxt] = true;
            dfs(g,nxt,visited);
        }
    }
}

void bfs(vector<vector<int>> &g, int cur, vector<bool> &visited)
{
    queue<int> q;
    q.push(cur);
    visited[cur] = true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        printf("%d ",node);
        for(int i=0;i<g[node].size();i++)
        {
            int nxt = g[node][i];
            if(!visited[nxt])
            {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
}

int main()
{
    int n,m,v;
    scanf("%d %d %d",&n,&m,&v);
    vector<vector<int>> g(n+1,vector<int>());
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> visited(n+1,false);
    visited[v] = true;
    dfs(g,v,visited);
    fill(visited.begin(),visited.end(),0);
    printf("\n");
    bfs(g,v,visited);
}