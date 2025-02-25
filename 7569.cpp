#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int m,n,h;

bool inRange(int a,int b,int c)
{
    return a>=0 && a<h && b>=0 && b<n && c>=0 && c<m;
}

int main()
{
    char tomato[101][101][101];
    const int dx[6] = {1,0,0,-1,0,0}, dy[6] = {0,1,0,0,-1,0}, dz[6] = {0,0,1,0,0,-1};

    scanf("%d %d %d",&m,&n,&h);
    queue<vector<int>> ripe;
    int zeroCount = 0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                scanf("%d",&tomato[i][j][k]);
                if(tomato[i][j][k] == 1)
                {
                    ripe.push(vector<int>({i,j,k}));
                }
                else if(tomato[i][j][k] == 0) zeroCount++;
            }
        }
    }
    int dayCount = 0;
    while(!ripe.empty() && zeroCount)
    {
        int len = ripe.size();
        for(int i=0;i<len;i++)
        {
            vector<int> tmp = ripe.front();
            ripe.pop();
            int x,y,z;
            x = tmp[0];
            y = tmp[1];
            z = tmp[2];
            for(int j=0;j<6;j++)
            {
                if(inRange(x+dx[j],y+dy[j],z+dz[j]) && tomato[x+dx[j]][y+dy[j]][z+dz[j]] == 0)
                {
                    tomato[x+dx[j]][y+dy[j]][z+dz[j]] = 1;
                    ripe.push(vector<int>({x+dx[j],y+dy[j],z+dz[j]}));
                    zeroCount--;
                }
                
            }
        }
        dayCount++;
    }
    if(zeroCount) printf("-1");
    else printf("%d",dayCount);
}