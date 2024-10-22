#include<cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int dp[20][20][3] = {0,};
    dp[0][1][0] = 1;
    int arr[20][20];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=1)
            {
                if(j-1>=0) dp[i][j][0] += dp[i][j-1][2] + dp[i][j-1][0];
                if(i-1>=0) dp[i][j][1] += dp[i-1][j][2] + dp[i-1][j][1];
            }
            if(arr[i-1][j]!=1 && arr[i][j-1]!=1 && arr[i][j]!=1)
            {
                if(i-1>=0 && j-1>=0) dp[i][j][2] += dp[i-1][j-1][0] + dp[i-1][j-1][1] +dp[i-1][j-1][2];
            }
        }
        
    }
    printf("%d",dp[n-1][n-1][0] + dp[n-1][n-1][1] + dp[n-1][n-1][2]);
}