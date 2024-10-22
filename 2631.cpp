#include<cstdio>

using namespace std;

int main()
{
    int dp[220]={0,},arr[220];
    int n;
    scanf("%d",&n);
    dp[0] = 1;
    scanf("%d",&arr[0]);
    int M = 0;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&arr[i]);
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                if(dp[j] > dp[i]) dp[i] = dp[j];
            }
        }
        dp[i]++;
        if(M < dp[i]) M = dp[i];
    }
    printf("%d",n - M);
}