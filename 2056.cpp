#include <cstdio>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

vector<int> indegree, weight;

int main()
{
    int n;
    scanf("%d",&n);
    indegree.assign(n+1,0), weight.assign(n+1,0);
    vector<vector<int>> graph(n+1,vector<int>());
    for(int i=1;i<=n;i++)
    {
        int w,k;
        scanf("%d %d",&weight[i],&k);
        indegree[i] = k;
        for(int j=0;j<k;j++)
        {
            int src;
            scanf("%d",&src);
            graph[src].push_back(i);
        }
    }

    queue<int> q;
    vector<int> done_time(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!indegree[i])
        {
            q.push(i);
            done_time[i] = weight[i];
        }
    }

    int total_time = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : graph[cur]) {
            done_time[nxt] = max(done_time[nxt], done_time[cur] + weight[nxt]);
            if(done_time[nxt] > total_time) total_time = done_time[nxt];
            if (--indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    
    printf("%d\n", *max_element(done_time.begin(), done_time.end()));
}