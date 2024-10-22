#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int k;
        scanf("%d",&k);
        int dp[550][550] = {0,},arr[550],sum[550];
        for(int i=0;i<k;i++)
        {
            scanf("%d",&arr[i]);
            if(i>0) sum[i] = sum[i-1] + arr[i];
            else sum[i] = arr[i];
        }
        for(int i=1;i<k;i++)
        {
            for(int j=0;j<k-i;j++)
            {
                dp[j][i+j] = 2000000000;
                for(int k=j;k<i+j;k++)
                {
                    int val = dp[j][k] + dp[k+1][i+j] + sum[i+j] - (j>0?sum[j-1]:0);
                    if(dp[j][i+j] > val) dp[j][i+j] = val;
                }
            }
        }

        printf("%d\n",dp[0][k-1]);
    }
}