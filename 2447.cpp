#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

char buff[6600][6600];

void blank(int x,int y,int k)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            buff[x+i][y+j] = ' ';
        }
    }
    return;
}

void draw(int x,int y,int k)
{
    if(k==1)
    {
        buff[x][y] = '*';
        return;
    }
    draw(x,y,k/3);
    draw(x,y+k/3,k/3);
    draw(x,y+k*2/3,k/3);
    draw(x+k/3,y,k/3);
    blank(x+k/3,y+k/3,k/3);
    draw(x+k/3,y+k*2/3,k/3);
    draw(x+k*2/3,y,k/3);
    draw(x+k*2/3,y+k/3,k/3);
    draw(x+k*2/3,y+k*2/3,k/3);
}

int main()
{
    int n;
    scanf("%d",&n);
    draw(0,0,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%c",buff[i][j]);
        }
        printf("\n");
    }
}