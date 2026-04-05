#include<cstdio>

int main()
{
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++)
    {    int dp[10010] = {0,};
        dp[0] = 1;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=3;i++)
        {
            for(int j=i;j<=n;j++)
            {
                dp[j] += dp[j-i];
            }
        }
        printf("%d",dp[n]);}
}