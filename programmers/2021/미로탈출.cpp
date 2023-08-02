#include <string>
#include <vector>
#include <queue>

using namespace std;
using ii = pair<int,int>;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    int g[1010][1010] = {0,};
    bool isTrap[1010] = {0,};
    queue<int> = q;
    for(int i=0;i<roads.size();i++)
    {
        if(g[roads[i][0]][roads[i][1]] == 0 || g[roads[i][0]][roads[i][1]] > roads[i][2]) g[roads[i][0]][roads[i][1]] = roads[i][2];
    }
    for(int i=0;i<traps.size();i++)
    {
        isTrap[traps[i]] = true;
    }
    q.push(start);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(isTrap[cur])
        {
            for(int i=1;i<=n;i++)
            {
                int tmp1=g[i][cur],tmp2=g[cur][i];
                g[i][cur] = tmp2;
                g[cur][i] = tmp1;
            }
        }
    }
    return answer;
}
