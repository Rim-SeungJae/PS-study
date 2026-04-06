#include<cstdio>
#include<vector>

using namespace std;

const int dx[4] = {-1,0,1,1}, dy[4] = {1,1,1,0};

bool inRange(int x,int y)
{
    return x>=0 && y>=0 && x<19 && y<19;
}

bool validate(int x,int y,vector<vector<int>> &badook)
{
    for(int i=0;i<4;i++)
    {
        bool isWin = false;
        for(int j=1;j<=4;j++)
        {
            if(j == 1)
            {
                int px,py;
                px = x-dx[i];
                py = y-dy[i];
                if(inRange(px,py) && badook[px][py] == badook[x][y]) break;
            }
            int nx,ny;
            nx = x+dx[i] * j;
            ny = y+dy[i] * j;
            //printf("%d %d\n",nx,ny);
            if(!inRange(nx,ny) || badook[nx][ny] != badook[x][y])
            {
                break;
            }
            if(j==4)
            {
                int nnx,nny;
                nnx = nx+dx[i];
                nny = ny+dy[i];
                if(inRange(nnx,nny) && badook[nnx][nny] == badook[nx][ny]) break;
                isWin = true;
            }
        }
        if(isWin) return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> badook(19,vector<int>(19,0));
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++) scanf("%d",&badook[i][j]);
    }

    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(badook[j][i]!=0 && validate(j,i,badook))
            {
                printf("%d\n%d %d",badook[j][i],j+1,i+1);
                return 0;
            }
        }
    }

    printf("0");

}