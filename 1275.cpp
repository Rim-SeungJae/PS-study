#include<cstdio>
#include<algorithm>

using namespace std;

long long int seg[400004],arr[100001];

long long int init(int l,int r,int idx)
{
    if(l == r) return seg[idx] = arr[l];
    int mid = l + (r - l)/2;
    long long int a = init(l,mid,idx*2);
    long long int b = init(mid+1,r,idx*2+1);
    return seg[idx] = (a + b);
}

long long int query(int l,int r,int ql,int qr,int idx)
{
    if(r<ql || l>qr) return 0;
    if(ql<=l && r<=qr) return seg[idx];
    int mid = l + (r - l)/2;
    long long int a = query(l,mid,ql,qr,idx*2);
    long long int b = query(mid+1,r,ql,qr,idx*2+1);
    return a+b;
}

void update(int l,int r,int q,int idx,long long int val)
{
    if(l>q || r<q) return;
    seg[idx] += val;
    if(l == r) return;
    int mid = l + (r - l)/2;
    update(l,mid,q,idx*2,val);
    update(mid+1,r,q,idx*2+1,val);
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    init(1,n,1);
    for(int i=0;i<m;i++)
    {
        int x,y,a,b;
        scanf("%d %d %d %d",&x,&y,&a,&b);
        if(x>y) swap(x,y);
        printf("%lld\n",query(1,n,x,y,1));
        long long int val = (long long int)b - arr[a];
        arr[a] = b;
        update(1,n,a,1,val);
    }
}