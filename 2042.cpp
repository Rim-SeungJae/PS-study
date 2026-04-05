#include<cstdio>

using namespace std;

long long int arr[1000001],seg[4000004];

void init(int idx,int l,int r)
{
    if(l == r)
    {
        seg[idx] = arr[l];
        return;
    }
    int mid = (r-l)/2 + l;
    init(idx*2,l,mid);
    init(idx*2+1,mid+1,r);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

void update(int idx,int l,int r,int tidx,long long val)
{
    if(r<tidx || l>tidx) return;
    if(l == r && l == tidx)
    {
        seg[idx] = val;
        return;
    }
    int mid = (r-l)/2 + l;
    update(idx*2,l,mid,tidx,val);
    update(idx*2+1,mid+1,r,tidx,val);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

long long int query(int idx,int l,int r,int ql,int qr)
{
    if(r<ql || l>qr) return 0;
    if(r<=qr && l>=ql) return seg[idx];
    int mid = (r-l)/2 + l;
    long long int a = query(idx*2,l,mid,ql,qr);
    long long int b = query(idx*2+1,mid+1,r,ql,qr);
    return a+b;
}

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }
    init(1,0,n);
    for(int i=0;i<m+k;i++)
    {
        long long int a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==1)
        {
            update(1,0,n,b-1,c);
        }
        else{
            printf("%lld\n",query(1,0,n,b-1,c-1));
        }
    }
}