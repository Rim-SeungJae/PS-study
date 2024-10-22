#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        scanf("%d",&n);
        int coin[22],m;
        int dp[22][10010] = {0,};
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&coin[i]);
            dp[i][0] = 1;
        }
        scanf("%d",&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(j-coin[i]>=0) dp[i][j] += dp[i][j-coin[i]];
                dp[i][j] += dp[i-1][j];
            }
        }
        printf("%d\n",dp[n][m]);
    }
}