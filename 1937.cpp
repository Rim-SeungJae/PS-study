#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    vector<vector<int>> arr(m, vector<int>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    priority_queue<tuple<int,int,int>> pq;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    visited[0][0] = 1;
    pq.push(make_tuple(arr[0][0], 0, 0));
    while(!pq.empty())
    {
        auto [val, x, y] = pq.top();
        pq.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && arr[nx][ny] < arr[x][y])
            {
                if(visited[nx][ny] == 0) pq.push(make_tuple(arr[nx][ny], nx, ny));
                visited[nx][ny] += visited[x][y];
            }
        }

    }
    printf("%d\n", visited[m-1][n-1]);
    return 0;

}