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
        int coins[22];
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&coins[i]);
        int m;
        scanf("%d",&m);
        int dp[10001]={0,};
        for(int i=0;i<n;i++)
        {
            dp[coins[i]] += 1;
            for(int j=0;j<=m;j++)
            {
                if(j>=coins[i]) dp[j] = dp[j-coins[i]] + dp[j];
            }
        }
        printf("%d\n",dp[m]);
    }
}