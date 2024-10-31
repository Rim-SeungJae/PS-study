#include<cstdio>
#include<vector>
#include<queue>

using namespace std;


int count(int cur,vector<vector<int>> & tree,vector<int> & cnt)
{
    if(tree[cur].size() == 0) return cnt[cur] = 1;
    int ans = 1;
    for(int i=0;i<tree[cur].size();i++)
    {
        ans += count(tree[cur][i],tree,cnt);
    }
    return cnt[cur] = ans;
}

int main()
{
    int n,r,q;
    scanf("%d %d %d",&n,&r,&q);
    vector<vector<int>> graph(n+1,vector<int>());
    for(int i=0;i<n-1;i++)
    {
        int src,dst;
        scanf("%d %d",&src,&dst);
        graph[src].push_back(dst);
        graph[dst].push_back(src);
    }
    vector<vector<int>> tree(n+1,vector<int>());
    queue<int> que;
    vector<bool> visited(n+1,0);
    que.push(r);
    visited[r] = true;
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        for(int i=0;i<graph[cur].size();i++)
        {
            if(!visited[graph[cur][i]])
            {
                visited[graph[cur][i]] = true;
                tree[cur].push_back(graph[cur][i]);
                que.push(graph[cur][i]);
            }
        }
    }
    vector<int> cnt(n+1,0);
    count(r,tree,cnt);
    for(int i=0;i<q;i++)
    {
        int u;
        scanf("%d",&u);
        printf("%d\n",cnt[u]);
    }
}