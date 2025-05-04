#include<cstdio>

using namespace std;

long long int seg[4000001];

void update(int idx,int l,int r,int targetIdx,int value)
{
    int mid = l+(r-l)/2;
    if(targetIdx<l || targetIdx>r) return;
    if(l == r)
    {
        seg[idx] += value;
        return;
    }
    update(2*idx,l,mid,targetIdx,value);
    update(2*idx+1,mid+1,r,targetIdx,value);
    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

long long int query(int idx,int l,int r,int ql,int qr)
{
    int mid = l+(r-l)/2;
    if(ql>r || qr<l) return 0;
    if(l>=ql && r<=qr) return seg[idx];
    long long int a = query(idx*2,l,mid,ql,qr);
    long long int b = query(idx*2+1,mid+1,r,ql,qr);
    return a+b;
}

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0;i<q;i++)
    {
        int qtype,a,b;
        scanf("%d %d %d",&qtype,&a,&b);
        if(qtype == 1)
        {
            update(1,0,n-1,a-1,b);
        }
        else{
            printf("%lld\n",query(1,0,n-1,a-1,b-1));
        }
    }
}