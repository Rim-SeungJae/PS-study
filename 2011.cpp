#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int arr[5001],idx=0,dp[5001]={0,};
    dp[0] = 1;
    while(scanf("%1d",&arr[++idx]) != -1)
    {
        if(arr[idx] == 0)
        {
            if(idx-1<1 || arr[idx-1] * 10 + arr[idx]>26 || arr[idx-1] * 10 + arr[idx]==0)
            {
                printf("0");
                return 0;
            }
        }
        if(arr[idx]>0)
        {
            dp[idx]+=dp[idx-1];
        }
        if(idx-2>=0 && arr[idx-1] * 10 + arr[idx]>9 && arr[idx-1] * 10 + arr[idx]<27 )
        {
            dp[idx]+=dp[idx-2];
        }
        dp[idx]%=1000000;
    }
    printf("%d",dp[idx-1]);
}