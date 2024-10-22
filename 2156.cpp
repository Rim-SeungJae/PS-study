#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main()
{
    int dp[10010][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    dp[1][0] = 0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int w;
        scanf("%d",&w);
        dp[i][2] = dp[i-1][1] + w;
        dp[i][1] = (i>1?max(dp[i-2][0],max(dp[i-2][1],dp[i-2][2])):0) + w;
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        //printf("%d %d %d\n",dp[i][0],dp[i][1],dp[i][2]);
    }
    printf("%d",max(dp[n][0],max(dp[n][1],dp[n][2])));
}