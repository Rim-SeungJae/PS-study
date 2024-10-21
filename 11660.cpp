#include<cstdio>

using namespace std;

int seg[4196][4196],arr[1024][1024];

int init(int l1, int r1, int l2,int r2,int idx1,int idx2)
{
	if(l1==r1) 
	{
		if(l2==r2) return seg[idx1][idx2] = arr[l1][l2];
		int mid = (l2+r2)/2;
		int a = init(l1,r1,l2,mid,idx1,idx2*2);
		int b = init(l1,r1,mid+1,r2,idx1,idx*2+1);
		return seg[idx1][idx2] = a+b;
	}
	if(l2==r2)
	{
		int mid = (l1+r1)/2;
		int a = init(l1,mid,l2,r2,idx1*2,idx2);
		int b = init(mid+1,r1,l2,r2,idx1*2+1,idx2);
		return seg[idx1][idx2] = a+b;
	}
	int mid = (l1+r1)/2;
	int a = init(l1,mid,l2,r2,idx1*2,idx2);
	int b = init(mid+1,r,l2,r2,idx1*2+1,idx2);
	return seg[idx1][idx2] = a + b;
}

int query(int l1, int r1,int l2,int r2,int x1, int y1,int x2,int y2, int idx1,int idx2)
{
	if(y1<l1 || x1>r1 || y2<l2 || x2>r2) return 0;
	if(l>=x && r<=y) return seg[idx];
	int mid = (l+r)/2;
	int a = query(l,mid,x,y,idx*2);
	int b = query(mid+1,r,x,y,idx*2+1);
	return a+b;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n*n;i++)
	{
		for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
	}
	init(0,n*n-1,1);
	for(int i=0;i<m;i++)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int x,y;
		x = x1*n+y1;
		y = x2*n+y2;
		printf("%d\n",query(0,n*n-1,x,y,1));
	}
}
