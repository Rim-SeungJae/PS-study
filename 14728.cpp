#include<cstdio>
#include<algorithm>

using namespace std;

int dp[101][10001];

int main()
{
    int n,t;
    scanf("%d %d",&n,&t);
    int w[101],v[101];
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&w[i],&v[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            if(j-w[i]>=0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d",dp[n][t]);
}