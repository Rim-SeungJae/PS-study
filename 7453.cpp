#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using ii = pair<int,int>;

int sum[16000001];

int main()
{
    int n;
    int a[4001],b[4001],c[4001],d[4001];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum[i*n+j] = c[i] + d[j];
        }
    }
    sort(sum,sum + n*n);;
    long long int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans += upper_bound(sum,sum+n*n,-a[i]-b[j]) - lower_bound(sum,sum+n*n,-a[i]-b[j]);
        }
    }
    printf("%lld",ans);
}