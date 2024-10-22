#include<cstdio>

using namespace std;

int main()
{
    int dp[101],arr[101][2];
    bool cross[101][101] = {0,};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == j) continue;
            if((arr[i][0] - arr[j][0]) * (arr[i][1] - arr[j][1]) < 0) cross[i][j] = true;
        }
    }
    dp[0] = 0;
    for(int i=1;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<i;j++)
        {
            cnt += cross[i][j];
        }
        if(cnt > dp[i-1]) dp[i] = cnt;
        else dp[i] = dp[i-1];
    }
    printf("%d",dp[n-1]);
}