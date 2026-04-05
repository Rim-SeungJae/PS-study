#include<cstdio>

using namespace std;

int arr[100001],seg[400004];

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

int query(int idx,int l,int r,int ql,int qr)
{
    if(r<ql || l>qr) return 0;
    if(r<=qr && l>=ql) return seg[idx];
    int mid = (r-l)/2 + l;
    int a = query(idx*2,l,mid,ql,qr);
    int b = query(idx*2+1,mid+1,r,ql,qr);
    return a+b;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int m;
    scanf("%d",&m);
    init(1,0,n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",query(1,0,n,a-1,b-1));
    }

}