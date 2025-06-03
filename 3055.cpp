#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    vector<vector<char>> arr(r,vector<char>(c));
    pair<int,int> D_pos,S_pos;
    vector<pair<int,int>> water_pos;
    for(int i=0;i<r;i++)
    {
        scanf("\n");
        for(int j=0;j<c;j++)
        {
            scanf("%1c",&arr[i][j]);
            if(arr[i][j] == 'D') D_pos = {i,j};
            if(arr[i][j] == 'S') S_pos = {i,j};
            if(arr[i][j] == '*') water_pos.push_back({i,j});
        }
    }

    queue<pair<int,int>> water_q,move_q;
    vector<vector<bool>> visited(r,vector<bool>(c,false));
    for(int i=0;i<water_pos.size();i++)
    {
        water_q.push(water_pos[i]);
        visited[water_pos[i].first][water_pos[i].second] = true;
    }
    move_q.push(S_pos);
    visited[S_pos.first][S_pos.second] = true;
    for(int cnt=0;!move_q.empty();cnt++)
    {
        int len = water_q.size();
        for(int i=0;i<len;i++)
        {
            int x,y;
            x = water_q.front().first;
            y = water_q.front().second;
            water_q.pop();
            for(int j=0;j<4;j++)
            {
                int nx = x+dx[j],ny = y+dy[j];
                if(nx>=0 && nx < r && ny>=0 && ny<c && arr[nx][ny]!='D' && arr[nx][ny]!='*' && arr[nx][ny]!='X')
                {
                    arr[nx][ny] = '*';
                    water_q.push({nx,ny});
                }
            }
        }
        len = move_q.size();
        for(int i=0;i<len;i++)
        {
            int x,y;
            x = move_q.front().first;
            y = move_q.front().second;
            move_q.pop();
            if(arr[x][y] == 'D')
            {
                printf("%d",cnt);
                return 0;
            }
            for(int j=0;j<4;j++)
            {
                int nx = x+dx[j],ny = y+dy[j];
                if(nx>=0 && nx < r && ny>=0 && ny<c && !visited[nx][ny] && arr[nx][ny]!='*' && arr[nx][ny]!='X')
                {
                    visited[nx][ny] = true;
                    move_q.push({nx,ny});
                }
            }
        }
    }
    printf("KAKTUS");
}