#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int arr[100001];
    int check[100001]={0,};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    long long int ans=0;
    int l=0,r=0;
    while(r<n)
    {
        if(check[arr[r]] && l<r)
        {
            check[arr[l]]--;
            l++;
            continue;
        }
        check[arr[r]]++;
        ans += r - l + 1;
        r++;
    }
    printf("%lld",ans);
}