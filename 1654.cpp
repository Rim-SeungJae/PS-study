#include<cstdio>

using namespace std;

int main()
{
    int k,n,lan[10001],max = 0;
    scanf("%d %d",&k,&n);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&lan[i]);
        if(max<lan[i]) max = lan[i];
    }
    long long int l = 1,r = max,ans;
    while(l<=r)
    {
        long long int mid = l+(r-l)/2;
        long long int cnt=0;
        for(int i=0;i<k;i++)
        {
            cnt+=lan[i]/mid;
            if(cnt>=n) break;
        }
        if(cnt >= n)
        {
            l = mid+1;
            ans = mid;
        }
        else{
            r = mid-1;
        }
    }
    printf("%d",ans);
}