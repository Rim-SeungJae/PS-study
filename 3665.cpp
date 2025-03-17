#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        scanf("%d",&n);
        vector<vector<int>> graph(n+1,vector<int>());
        vector<int> in(n+1,0);
        int arr[505];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                graph[arr[i]].push_back(arr[j]);
                in[arr[j]]++;
            }
        }
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            bool flg = false;
            for(int j=0;j<graph[a].size();j++)
            {
                if(graph[a][j] == b)
                {
                    graph[a].erase(graph[a].begin()+j);
                    graph[b].push_back(a);
                    in[b]--;
                    in[a]++;
                    flg = true;
                    break;
                }
            }
            for(int j=0;j<graph[b].size();j++)
            {
                if(flg) break;
                if(graph[b][j] == a)
                {
                    graph[b].erase(graph[b].begin()+j);
                    graph[a].push_back(b);
                    in[a]--;
                    in[b]++;
                    break;
                }
            }
        }

        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(!in[i])
            {
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty())
        {
            if(q.size()>1)
            {
                printf("?\n");
                break;
            }
            int cur = q.front();
            q.pop();
            result.push_back(cur);
            for(int i=0;i<graph[cur].size();i++)
            {
                int nxt = graph[cur][i];
                in[nxt]--;
                if(!in[nxt])
                {
                    q.push(nxt);
                }
            }
        }
        if(result.size() != n) printf("IMPOSSIBLE\n");
        else if(!q.size())
        {
            for(int i=0;i<result.size();i++)
            {
                printf("%d ",result[i]);
            }
            printf("\n");
        }
    }
}