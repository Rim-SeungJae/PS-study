#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using ii = pair<int,int>;

int arr[100001];
ii seg[400004];

ii init(int idx,int l,int r)
{
    if(l == r) return seg[idx] = make_pair(arr[l],l);
    int mid = l + (r - l) / 2;
    ii a = init(idx * 2,l,mid);
    ii b = init(idx * 2 + 1, mid+1,r);
    return seg[idx] = min(a,b);
}

ii query(int idx,int l,int r,int ql, int qr)
{
    if(r<ql || l>qr) return make_pair(2000000000,100001);
    if(l>=ql && r<=qr) return seg[idx];
    int mid = l + (r - l) / 2;
    ii a = query(idx * 2,l,mid,ql,qr);
    ii b = query(idx * 2 + 1, mid+1,r,ql,qr);
    return min(a,b);
}

ii update(int idx,int l,int r,int uidx, int uval)
{
    if(r<uidx || l>uidx) return seg[idx];
    if(l == r)
    {
        return seg[idx] = make_pair(uval,uidx);
    }
    int mid = l + (r - l) / 2;
    ii a = update(idx * 2,l,mid,uidx,uval);
    ii b = update(idx * 2 + 1, mid+1,r,uidx,uval);
    return seg[idx] = min(a,b);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    init(1,0,n-1);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int cmd,a,b;
        scanf("%d %d %d",&cmd,&a,&b);
        if(cmd == 1) update(1,0,n-1,a-1,b);
        else printf("%d\n",query(1,0,n-1,a-1,b-1).second + 1);
    }

}