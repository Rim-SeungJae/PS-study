#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int seg[400004],arr[100001];

int Init(int idx,int l,int r)
{
    if(l == r) return seg[idx] = arr[l];
    int mid = l + (r-l)/2;
    return seg[idx] = min(Init(2*idx,l,mid),Init(2*idx+1,mid+1,r));
}

int Query(int idx,int l,int r,int ql,int qr)
{
    if(l>qr || r<ql) return 2000000000;
    if(l>=ql && r<=qr) return seg[idx];
    int mid = l + (r-l)/2;
    return min(Query(2*idx,l,mid,ql,qr),Query(2*idx+1,mid+1,r,ql,qr));
}

int Update(int idx,int l,int r,int uidx,int uval)
{
    if(l == uidx && l == r) return seg[idx] = uval;
    if(l>uidx || r<uidx) return seg[idx];
    int mid = l + (r-l)/2;
    return seg[idx] = min(Update(2*idx,l,mid,uidx,uval),Update(2*idx+1,mid+1,r,uidx,uval));

}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Init(1,0,n-1);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int q,a,b;
        scanf("%d %d %d",&q,&a,&b);
        if(q == 1)
        {
            Update(1,0,n-1,a-1,b);
        }
        else{
            printf("%d\n",Query(1,0,n-1,a-1,b-1));
        }
    }
}