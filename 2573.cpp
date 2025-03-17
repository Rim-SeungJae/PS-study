#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

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
    vector<vector<int>> arr(n,vector<int>(m));
    vector<vector<int>> nxtarr(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int cnt=0;
    bool sep = false;
    while(++cnt)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                nxtarr[i][j] = arr[i][j];
                if(arr[i][j])
                {
                    for(int k=0;k<4;k++)
                    {
                        int nx = i+dx[k],ny = j+dy[k];
                        if(InRange(nx,ny,n,m) && !arr[nx][ny] && nxtarr[i][j]) nxtarr[i][j]--;
                    }
                }
            }
        }
        arr = nxtarr;

        bool visited[301][301] = {0,};
        bool flg = false;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j] && !flg)
                {
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                    while(!q.empty())
                    {
                        pair<int,int> cur = q.front();
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int nx = cur.first + dx[k],ny = cur.second + dy[k];
                            if(InRange(nx,ny,n,m) && arr[nx][ny] && !visited[nx][ny])
                            {
                                visited[nx][ny] = true;
                                q.push(make_pair(nx,ny));
                            }
                        }
                    }
                    flg = true;
                }
                if(arr[i][j] && flg && !visited[i][j]) sep = true;
            }
        }

        if(sep || !flg) break;
    }
    if(sep) printf("%d",cnt);
    else printf("0");
}