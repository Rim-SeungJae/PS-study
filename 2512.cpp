#include<cstdio>

using namespace std;

int main()
{
    int n,m;
    scanf("%d",&n);
    int arr[10001];
    int l=0,r=0,sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>r) r = arr[i];
        sum+=arr[i];
    }

    scanf("%d",&m);
    if(sum<=m)
    {
        printf("%d",r);
    }
    else{
        int ans = 0;
        while(l<=r)
        {
            int mid = (r-l)/2+l;
            int sum = 0;
            for(int i=0;i<n;i++)
            {
                if(mid>arr[i]) sum+=arr[i];
                else sum+=mid;
            }
            if(sum <= m)
            {
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        printf("%d",ans);
    }

}