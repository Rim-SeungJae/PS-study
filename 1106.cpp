#include<cstdio>
#include<vector>

using namespace std;

int dp[100001] = {0,};

int main()
{
    int c,n;
    int w[22],v[22];
    scanf("%d %d",&c,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&w[i],&v[i]);
        dp[w[i]] = v[i];
    }
    for(int i=0;i<100001;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i+w[j]] = max(dp[i] + v[j],dp[i+w[j]]);
        }
        if(dp[i] >= c)
        {
            printf("%d",i);
            return 0;
        }
    }
}