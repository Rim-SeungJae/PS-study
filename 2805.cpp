#include<cstdio>

using namespace std;

int tree[1000010];

int main()
{
	int n,m,max=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tree[i]);
		if(tree[i]>max) max = tree[i];
	}
	int l=0,r=max,ans = 0;
	while(r>=l)
	{
		int mid = l + (r-l)/2;
		long long int sum = 0;
		for(int i=0;i<n;i++)
		{
			if(tree[i]-mid>0)sum += tree[i] - mid;
			if(sum >= m) break;
		}
		if(sum>=m)
		{
			//printf("%d\n",mid);
			l = mid+1;
			ans = mid;
		}
		else
		{
			r = mid-1;
		}
	}
	printf("%d",ans);
}
