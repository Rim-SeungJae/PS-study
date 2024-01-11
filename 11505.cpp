#include<cstdio>

using namespace std;

long long seg[4000010];
long long tmp[1000010];

long long init(int start,int end,int idx)
{
    if(start == end)
    {
        seg[idx] = tmp[start];
        return seg[idx];
    }
    int mid = (start+end)/2;
    return seg[idx] = (init(start,mid,idx*2) * init(mid+1,end,idx*2+1))%1000000007;
}

long long change(int start,int end,int idx,int target,long long div,long long mul)
{
    if(start>target || end<target) return seg[idx];
    if(start==end) return seg[idx] = mul;
    int mid = (start+end)/2;
    return seg[idx] = (change(start,mid,idx*2,target,div,mul)*change(mid+1,end,idx*2+1,target,div,mul))%1000000007;
}

long long mult(int start,int end,int idx,int l,int r)
{
    if(start>r || end<l) return 1;
    if(l<=start && end<=r) return seg[idx];
    else{
        int mid = (start+end)/2;
        return (mult(start,mid,idx*2,l,r) * mult(mid+1,end,idx*2+1,l,r))%1000000007;
    }
}

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&tmp[i]);
    }
    init(0,n-1,1);

    for(int i=0;i<m+k;i++)
    {
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a==1)
        {
            change(0,n-1,1,b-1,tmp[b-1],c);
            tmp[b-1] = c;
        }
        else{
            printf("%lld\n",mult(0,n-1,1,b-1,c-1));
        }
    }
}
/*
세그먼트 트리
*/