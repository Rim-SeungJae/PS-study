#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n,arr[5050];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(&arr[0],&arr[n]);
	int sum,l,r,m,close,close_idx,zero = 2000000001,zero_idx[3];
	l = 0;
	r = n-1;
	while(r>l+1)
	{
		sum = arr[l] + arr[r];
		int tmpl = l+1,tmpr = r-1;
		close = 2000000001;
		close_idx = -1;
		while(tmpl<=tmpr)
		{
			m = (tmpl+tmpr)/2;
			if(arr[m]+sum == 0)
			{
				close = arr[m];
				close_idx = m;
				break;
			}
			if(abs(((double)sum+close)/(sum+arr[m])) > 1)
			{
				close = arr[m];
				close_idx = m;
			}
			if(sum+arr[m]>0) tmpr = m-1;
			else tmpl = m+1;
		}
		//printf("%d %d %d\n",arr[l],arr[r],close);
		if(sum+close == 0)
		{
			zero = 0;
			zero_idx[0] = l;
			zero_idx[1] = close_idx;
			zero_idx[2] = r;
			break;
		}
		if(abs((double)zero/(sum+close)) > 1)
		{
			zero = sum+close;
			zero_idx[0] = l;
			zero_idx[1] = close_idx;
			zero_idx[2] = r;
		}
		if(sum+close>0) r--;
		else l++;
	}
	printf("%d %d %d",arr[zero_idx[0]],arr[zero_idx[1]],arr[zero_idx[2]]);
}
//
