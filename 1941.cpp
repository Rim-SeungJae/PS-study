#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

using ii = pair<int,int>;

int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

bool InRange(int a,int b)
{
    return a>=0 && a<5 && b>=0 && b<5;
}

int main()
{
    vector<vector<char>> seat(5,vector<char>(5));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            char tmp;
            scanf("%1c",&tmp);
            seat[i][j] = tmp;
        }
        char tmp;
        scanf("%1c",&tmp);
    }

    vector<bool> per(25,0);
    per[0] = per[1] = per[2] = per[3] = per[4] = per[5] = per[6] = 1;

    int ans = 0;
    do{
        int SCount = 0;
        queue<ii> q;
        vector<vector<bool>> selected(5,vector<bool>(5,false));
        vector<vector<bool>> visited(5,vector<bool>(5,false));
        for(int i=0;i<25;i++)
        {
            if(per[i])
            {
                int x = i/5;
                int y = i%5;
                selected[x][y] = true;
                if(seat[x][y] == 'S') SCount++;
                if(q.empty())
                {
                    q.push(make_pair(x,y));
                    visited[x][y] = true;
                }
            }
        }
        if(SCount < 4) continue;


        while(!q.empty())
        {
            int x,y;
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++)
            {
                if(InRange(x+dx[k],y+dy[k]) && !visited[x+dx[k]][y+dy[k]] && selected[x+dx[k]][y+dy[k]])
                {
                    q.push(make_pair(x+dx[k],y+dy[k]));
                    visited[x+dx[k]][y+dy[k]] = true;
                }
            }
        }
        bool connected = true;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(selected[i][j] && !visited[i][j]) connected = false;
            }
        }
        if(!connected) continue;
        else ans++;
    } while(prev_permutation(per.begin(),per.end()));

    printf("%d",ans);

}