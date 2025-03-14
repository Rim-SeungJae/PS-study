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
    for(int i=0;i<n;i++)
    {
        int l=0,r=n-1,mid;
        while(l<r)
        {
            if(l == i)
            {
                l++;
                continue;
            }
            if(r == i)
            {
                r--;
                continue;
            }
            if(arr[l] + arr[r] == arr[i])
            {
                ans++;
                break;
            }
            else if(arr[l] + arr[r] > arr[i])
            {
                r--;
            }
            else{
                l++;
            }
        }
    }
    printf("%d",ans);
}