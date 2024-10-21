#include<cstdio>

using namespace std;

int seg[400040];
int arr[100010];

int init(int l,int r,int idx)
{
	if(l == r) return seg[idx] = arr[l];
	int mid = (l+r)/2;
	int a = init(l,mid,idx*2);
	int b = init(mid+1,r,idx*2+1);
	return seg[idx] = a+b;
}

int query(int l,int r,int x,int y,int idx)
{
	if(x>r || y<l) return 0;
	if(l>=x && r<=y) return seg[idx];
	int mid = (l+r)/2;
	return query(l,mid,x,y,idx*2) + query(mid+1,r,x,y,idx*2+1);
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	init(0,n-1,1);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		x--;
		y--;
		printf("%d\n",query(0,n-1,x,y,1));
	}
}
