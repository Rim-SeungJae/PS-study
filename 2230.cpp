#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[100001];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int l=0,r=1;
    sort(arr,&arr[n]);
    int ans=2000000001;
    while(r<n)
    {
        if(arr[r] - arr[l]>=m)
        {
            if(arr[r] - arr[l]<ans) ans = arr[r]-arr[l];
            l++;
        }
        else{
            r++;
        }
    }
    printf("%d",ans);
}