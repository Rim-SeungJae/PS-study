#include<cstdio>
#include<vector>
#include<queue>

using namespace std;


const int dx[4] = {0,1,0,-1} , dy[4] = {1,0,-1,0};

bool inRange(int r,int c,int n)
{
    return r>=0 && c>=0 && r<n && c<n;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    vector<vector<int>> v(n,vector<int>(n,0));
    queue<pair<int,int>> q[k+1];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&v[i][j]);
            if(v[i][j] != 0) q[v[i][j]].push(make_pair(i,j));
        }
    }
    int s,x,y;
    scanf("%d %d %d",&s,&x,&y);

    int sec = 0;
    bool isChange = false;
    do
    {

        if(sec == s)
        {
            printf("%d",v[x-1][y-1]);
            break;
        }
        isChange = false;
        for(int i=0;i<=k;i++)
        {
            int size = q[i].size();
            for(int j = 0; j<size;j++)
            {
                int r,c;
                r = q[i].front().first;
                c = q[i].front().second;
                q[i].pop();
                for(int k=0;k<4;k++)
                {
                    int nr,nc;
                    nr = r+dx[k];
                    nc = c+dy[k];
                    if(inRange(nr,nc,n) && v[nr][nc] == 0)
                    {
                        q[i].push(make_pair(nr,nc));
                        v[nr][nc] = i;
                        isChange = true;
                    }
                }
            }
        }
        sec++;
    } while(true);

}