#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int maxDist,n,m;

const int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

bool inRange(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<m;
}

void bfs(int r,int c,vector<vector<char>> &v)
{
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    q.push(make_pair(r,c));
    visited[r][c] = true;

    int dist = 0;

    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            int x,y;
            x = q.front().first;
            y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nx,ny;
                nx = x + dx[i];
                ny = y + dy[i];
                if(inRange(nx,ny) && !visited[nx][ny] && v[nx][ny] == 'L')
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                    if(dist+1>maxDist) maxDist = dist+1;
                }
            }
        }
        dist++;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    vector<vector<char>> v(n,vector<char>(m,0));
    for(int i=0;i<n;i++)
    {
        scanf("\n");
        for(int j=0;j<m;j++)
        {
            scanf("%1c",&v[i][j]);
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j] == 'L')
            {
                bfs(i,j,v);
            }
        }
    }

    printf("%d",maxDist);
}