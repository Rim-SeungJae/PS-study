#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

bool inRange(int a,int b)
{
    return a>=0 && b>=0 && a<6 && b<12;
}

bool bfs(int x,int y,vector<vector<bool>> &visited,vector<vector<char>> &field)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;

    int cnt = 1;

    vector<pair<int,int>> target;
    target.push_back(make_pair(x,y));

    while(!q.empty())
    {
        int r,c;
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nr,nc;
            nr = r+dx[i];
            nc = c+dy[i];
            if(inRange(nr,nc) && !visited[nr][nc] && field[r][c] == field[nr][nc])
            {
                visited[nr][nc] = true;
                q.push(make_pair(nr,nc));
                target.push_back(make_pair(nr,nc));
                cnt++;
            }
        }

    }
    //printf("%d\n",cnt);
    if(cnt >= 4)
    {
        for(pair<int,int> p : target)
        {
            field[p.first][p.second] = '.';
        }
        return true;
    }
    return false;
    
}

int main()
{
    char tmp[12][6];
    for(int i=0;i<12;i++)
    {
        scanf("\n");
        for(int j=0;j<6;j++) scanf("%c",&tmp[i][j]);
    }
    
    vector<vector<char>> field(6,vector<char>(12,'.'));
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<12;j++)
        {
            field[i][j] = tmp[11-j][i];
        }
    }

    bool puyo = false;
    int cnt = 0;
    do
    {

        vector<vector<bool>> visited(6,vector<bool>(12,0));
        if(puyo)
        {
            puyo = false;
            cnt++;
        }

        for(int i=0;i<6;i++)
        {
            for(int j=0;j<12;j++)
            {
                if(field[i][j]!= '.' && !visited[i][j])
                {
                    if(bfs(i,j,visited,field))
                    {
                        puyo = true;
                    }
                }
            }
        }

        for(int i=0;i<6;i++)
        {
            
            fill(remove(field[i].begin(),field[i].end(),'.'),field[i].end(),'.');
        }


    } while (puyo);
    printf("%d",cnt);
}