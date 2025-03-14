#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int arr[601];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int ans= 2000000000;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int l=0,r=n-1,target=arr[i] + arr[j];
            while(l<r)
            {
                if(l == i || l == j)
                {
                    l++;
                    continue;
                }
                if(r == i || r == j)
                {
                    r--;
                    continue;
                }
                if(arr[r] + arr[l] == target)
                {
                    ans = 0;
                    break;
                }
                else if(arr[r] + arr[l] > target)
                {
                    if(arr[r] + arr[l] - target < ans) ans = arr[r]+arr[l] - target;
                    r--;
                }
                else
                {
                    if(target - arr[r] - arr[l] < ans) ans = target - arr[r] - arr[l];
                    l++;
                }
            }
            if(ans == 0) break;
        }
        if(ans == 0) break;
    }
    printf("%d",ans);
}