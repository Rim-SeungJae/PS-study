#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int arr[501][501];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    int dp[501][501] = {0,};
    dp[1][1] = arr[1][1];

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j] = dp[i-1][j] + arr[i][j];
            if(j>=1) dp[i][j] = max(dp[i-1][j-1] + arr[i][j], dp[i-1][j] + arr[i][j]);
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[n][i] > ans) ans = dp[n][i];
    }
    printf("%d",ans);
}