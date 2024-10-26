#include<cstdio>
#include<algorithm>

using namespace std;

int v[21][301],dp[21][301],cnt[21][301][21];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&v[j][i]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = dp[i-1][j];
            for(int k=1;k<=m;k++) cnt[i][j][k] = cnt[i-1][j][k];
            for(int k=1;k<=j;k++)
            {
                if(dp[i-1][j-k] + v[i][k] > dp[i][j])
                {
                    for(int l=1;l<=m;l++) cnt[i][j][l] = cnt[i-1][j-k][l];
                    cnt[i][j][i] = k;
                    dp[i][j] = dp[i-1][j-k] + v[i][k];
                }
            }
        }
    }
    printf("%d\n",dp[m][n]);
    for(int k=1;k<=m;k++)
    {
        printf("%d ",cnt[m][n][k]);
    }
}