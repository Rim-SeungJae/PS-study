#include<cstdio>
#include<algorithm>

using namespace std;

int dp[1500051],arr[1500000][2];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    dp[0] = 0;
    int Max = 0;
    for(int i=0;i<n;i++)
    {
        if(i!=0) dp[i] = max(dp[i-1],dp[i]);
        dp[i+arr[i][0]] = max(dp[i] + arr[i][1],dp[i+arr[i][0]]);
        if(Max < dp[i+arr[i][0]] && i+arr[i][0]<=n) Max = dp[i+arr[i][0]];
    }
    printf("%d",Max);
}