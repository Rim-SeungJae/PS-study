#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int w[33];
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    reverse(w+1,w+n+1);
    int m;
    scanf("%d",&m);
    bool dp[31][50001] = {0,};

    for(int i=1;i<=n;i++)
    {
        dp[i][w[i]] = true;
        for(int j=40000;j>=0;j--)
        {
            dp[i][j] |= dp[i-1][abs(j - w[i])] || dp[i-1][j+w[i]] || dp[i-1][j];
        }
    }

    for(int i=0;i<m;i++)
    {
        int marble;
        scanf("%d",&marble);
        if(dp[n][marble]) printf("Y ");
        else printf("N ");
    }
}