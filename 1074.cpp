#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

int cnt,r,c;

void zSearch(int ax,int ay,int bx,int by)
{
    static bool found = false;
    if(ax == bx)
    {
        if(ax == r && ay == c)
        {
            printf("%d",cnt);
            found = true;
        }
        cnt++;
        return;
    }
    if(!(r>=ax && r<=bx && c>=ay && c<=by))
    {
        cnt += (bx-ax+1) * (by-ay+1);
        return;
    }
    if(found) return;
    int midx = (ax+bx)/2, midy = (ay+by)/2;
    zSearch(ax,ay,midx,midy);
    zSearch(ax,midy+1,midx,by);
    zSearch(midx+1,ay,bx,midy);
    zSearch(midx+1,midy+1,bx,by);
}

int main()
{
    int n;
    scanf("%d %d %d",&n,&r,&c);
    zSearch(0,0,pow(2,n)-1,pow(2,n)-1);   
}