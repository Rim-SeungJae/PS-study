#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int dp[1001][3],first[3]={0,1,2},arr[1001][3];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for(int i=1;i<n;i++)
    {
        if(dp[i-1][1] + arr[(i+1)%n][2] < dp[i-1][2] + arr[(i+1)%n][1]) dp[i][0] = dp[i-1][1] + arr[i][0];
        else dp[i][0] = dp[i-1][2] + arr[i][0];
        if(dp[i-1][0] + arr[(i+1)%n][2] < dp[i-1][2] + arr[(i+1)%n][0]) dp[i][1] = dp[i-1][0] + arr[i][1];
        else dp[i][1] = dp[i-1][2] + arr[i][1];
        if(dp[i-1][1] + arr[(i+1)%n][0] < dp[i-1][0] + arr[(i+1)%n][1]) dp[i][2] = dp[i-1][1] + arr[i][2];
        else dp[i][2] = dp[i-1][2] + arr[i][2];
    }
    printf("%d",min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2])));
}