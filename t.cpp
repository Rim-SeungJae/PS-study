#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int parent[3003];
bool visited[3003];
vector<int> cycle;
void dfs(int cur,vector<vector<int>> graph)
{
    for(int i=0;i<graph[cur].size();i++)
    {
        int nxt = graph[cur][i];
        if(!visited[nxt])
        {
            parent[nxt] = cur;
            visited[nxt] = true;
            dfs(nxt,graph);
        }
        else
        {
            if(nxt != parent[cur] && parent[cur] != cur)
            {
                int tmp = cur;
                while(tmp != nxt)
                {
                    cycle.push_back(tmp);
                    tmp = parent[tmp];
                }
                cycle.push_back(nxt);
            }
            
        }
    }
}

vector<int> nodeDistance(int s_nodes, vector<int> s_from, vector<int> s_to) {
    vector<vector<int>> graph(s_nodes+2,vector<int>());
    for(int i=0;i<s_from.size();i++)
    {
        graph[s_from[i]].push_back(s_to[i]);
        graph[s_to[i]].push_back(s_from[i]);
    }
    for(int i=1;i<=s_nodes;i++) parent[i] = i;
    visited[1] = true;
    dfs(1,graph);
    for(int i=0;i<cycle.size();i++) printf("%d ",cycle[i]);
    
    vector<int> dist(s_nodes+1,0);
    
    memset(visited,false,sizeof(visited));
    queue<int> q;
    for(int i=0;i<cycle.size();i++)
    {
        q.push(cycle[i]);
        visited[cycle[i]] = true;
    }
    int cnt = 0;
    while(!q.empty())
    {
        int len = q.size();
        for(int i=0;i<len;i++)
        {
            int cur = q.front();
            printf("%d %d\n",cur,cnt);
            q.pop();
            dist[cur] = cnt;
            for(int nxt:graph[cur])
            {
                if(!visited[nxt])
                {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        cnt++;
    }
    
    return dist;
}

int main()
{
    vector<int> s_from(6,0);
    s_from[0] = 1;
    s_from[1] = 3;
    s_from[2] = 6;
    s_from[3] = 2;
    s_from[4] = 1;
    s_from[5] = 3;
    vector<int> s_to(6,0);
    s_to[0] = 2;
    s_to[1] = 4;
    s_to[2] = 4;
    s_to[3] = 3;
    s_to[4] = 3;
    s_to[5] = 5;
    nodeDistance(6, s_from, s_to);
}