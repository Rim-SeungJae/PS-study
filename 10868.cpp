#include<cstdio>
#include<algorithm>

using namespace std;

int seg[400004],arr[100001];

int init(int l,int r,int idx)
{
    if(l == r) return seg[idx] = arr[l];
    int mid = l + (r - l)/2;
    int a = init(l,mid,idx*2);
    int b = init(mid+1,r,idx*2+1);
    return seg[idx] = min(a,b);
}

int query(int l,int r,int ql,int qr,int idx)
{
    if(r<ql || l>qr) return 2000000000;
    if(ql<=l && r<=qr) return seg[idx];
    int mid = l + (r - l)/2;
    int a = query(l,mid,ql,qr,idx*2);
    int b = query(mid+1,r,ql,qr,idx*2+1);
    return min(a,b);
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    init(1,n,1);
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",query(1,n,l,r,1));
    }
}