#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int arr[101],n;
    long long int dp[101][21]={0,};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    dp[0][arr[0]] = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=20;j++)
        {
            if(j+arr[i]<=20) dp[i][j+arr[i]] += dp[i-1][j];
            if(j-arr[i]>=0) dp[i][j-arr[i]] += dp[i-1][j];
        }
    }
    printf("%lld",dp[n-2][arr[n-1]]);
}