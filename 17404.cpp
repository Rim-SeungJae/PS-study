#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int dp[1001][3][3],first[3]={0,1,2},arr[1001][3];
    fill(&dp[0][0][0],&dp[1001][3][3],1001);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
    dp[0][0][0] = arr[0][0];
    dp[0][1][1] = arr[0][1];
    dp[0][2][2] = arr[0][2];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            dp[i][j][0] = min(dp[i-1][(j+1)%3][0], dp[i-1][(j+2)%3][0]) + arr[i][j];
            dp[i][j][1] = min(dp[i-1][(j+1)%3][1], dp[i-1][(j+2)%3][1]) + arr[i][j];
            dp[i][j][2] = min(dp[i-1][(j+1)%3][2], dp[i-1][(j+2)%3][2]) + arr[i][j];
            
        }
    }
    printf("%d",min({dp[n-1][0][1],dp[n-1][0][2],dp[n-1][1][0],dp[n-1][1][2],dp[n-1][2][0],dp[n-1][2][1]}));
}