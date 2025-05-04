#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

bool InRange(int x,int y,int n,int m)
{
    return x>=0 && y>=0 && x<n && y<m;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<bool>> board(n,vector<bool>(m));
    int cheeseCnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            board[i][j] = tmp;
            if(board[i][j]) cheeseCnt++;
        }
    }
    int prvCnt = cheeseCnt;
    int hours = 0;
    while(cheeseCnt)
    {
        prvCnt = cheeseCnt;
        hours++;
        queue<pair<int,int>> q;
        int visited[100][100] = {0,};
        q.push(make_pair(0,0));
        visited[0][0] = true;
        while(!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i], ny = y+dy[i];
                if(InRange(nx,ny,n,m) && (!visited[nx][ny] || board[nx][ny]))
                {
                    if(board[nx][ny])
                    {
                        visited[nx][ny]++;
                        if(visited[nx][ny] >=2) {
                            board[nx][ny] = 0;
                            cheeseCnt--;
                        }
                    }
                    else
                    {
                        visited[nx][ny] = true;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    printf("%d",hours);
}