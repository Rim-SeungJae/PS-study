#include<cstdio>
#include<algorithm>
using namespace std;

int seg[400004],arr[100001];

int init(int l,int r,int idx)
{
    if(l==r) return seg[idx] = l;
    int mid = l+(r-l)/2;
    int a = init(l,mid,2*idx);
    int b = init(mid+1,r,2*idx+1);
    return seg[idx] = arr[a]<=arr[b]?a:b;
}

int query(int l,int r,int ql,int qr,int idx)
{
    if(r<ql || l>qr) return 0;
    if(l>=ql && r<=qr) return seg[idx];
    int mid = l+(r-l)/2;
    int a = query(l,mid,ql,qr,2*idx);
    int b = query(mid+1,r,ql,qr,2*idx+1);
    return arr[a]<=arr[b]?a:b;
}

int update(int l,int r,int u,int idx,int val)
{
    if(l>u || r<u) return seg[idx];
    if(l == r) return seg[idx];
    int mid = l+(r-l)/2;
    int a = update(l,mid,u,2*idx,val);
    int b = update(mid+1,r,u,2*idx+1,val);
    return seg[idx] = arr[a]<=arr[b]?a:b;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    arr[0] = 1000000001;
    init(1,n,1);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int cmd;
        scanf("%d",&cmd);
        if(cmd == 1)
        {
            int u,val;
            scanf("%d %d",&u,&val);
            arr[u] = val;
            update(1,n,u,1,val);
        }
        else{
            printf("%d\n",query(1,n,1,n,1));
        }
    }
}