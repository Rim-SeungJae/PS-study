#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int arr[2002];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,&arr[n]);
    int ans=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int target = arr[i] - arr[j];
            int l=0,r=n-1,mid;
            while(l<=r)
            {
                if(l==j || r==i) 
                mid=(l+r)/2;
                if(arr[mid] == target)
                {
                    ans++;
                    break;
                }
                else if(arr[mid] > target)
                {
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            if(l<=r) break;
        }
    }
    printf("%d",ans);
}