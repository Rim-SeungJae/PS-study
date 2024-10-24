#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n,c,house[200001];
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&house[i]);
    }
    sort(house,&house[n]);
    int l = 1,r = house[n-1] - house[0],ans;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        int prv = 0,cnt = 1;
        for(int i=1;i<n;i++)
        {
            if(house[i] - house[prv] >= mid)
            {
                prv = i;
                cnt++;
            }
        }
        if(cnt >= c)
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