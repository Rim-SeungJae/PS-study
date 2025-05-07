#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int arr[100001];
pair<int,int> seg[400004];

pair<int,int> init(int l,int r,int idx)
{
    if(l == r)
    {
        return seg[idx] = make_pair(arr[l],l);
    }
    int mid = l + (r-l)/2;
    pair<int,int> a = init(l,mid,idx*2);
    pair<int,int> b = init(mid+1,r,2*idx+1);
    return seg[idx] = min(a,b);
}

pair<int,int> query(int l,int r,int ql,int qr,int idx)
{
    if(qr<l || ql>r) return make_pair(2000000000,-1);
    if(l>=ql && r<=qr) return seg[idx];
    int mid = l + (r-l)/2;
    pair<int,int> a = query(l,mid,ql,qr,idx*2);
    pair<int,int> b = query(mid+1,r,ql,qr,idx*2+1);
    return min(a,b);
}

pair<int,int> update(int l,int r,int u,int idx,int val)
{
    if(u<l || u>r) return seg[idx];
    if(l == r)
    {
        return seg[idx] = make_pair(val,l);
    }
    int mid = l + (r-l)/2;
    pair<int,int> a = update(l,mid,u,idx*2,val);
    pair<int,int> b = update(mid+1,r,u,idx*2+1,val);
    return seg[idx] = min(a,b);
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
            printf("%d\n",query(1,n,1,n,1).second);
        }
    }
}