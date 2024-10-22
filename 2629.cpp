#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int marble[33];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&marble[i]);
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int target;
        scanf("%d",&target);
        bool dp[31][40001] = {0,};
        dp[0][target] = true;
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<40001;k++)
            {
                dp[j][k] = dp[j-1][abs(k-marble[j])] || dp[j-1][k+marble[j]] || dp[j-1][k];
            }
        }
        if(dp[n][0]) printf("Y ");
        else printf("N ");
    }
}