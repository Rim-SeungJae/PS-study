#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool arr[1001][1001];
int dp[1001][1001];

int main()
{
    int n,m,maxLen = 0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%1d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j])
            {
                dp[i][j] = 1;
                if (i-1>=0 && j-1>=0)
                {
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
                }
                if(dp[i][j] > maxLen) maxLen = dp[i][j];
            }
        }
    }
    printf("%d",maxLen * maxLen);
}