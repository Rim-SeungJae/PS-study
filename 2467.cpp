#include<cstdio>
#include<cmath>

using namespace std;

int arr[100010];

int main()
{
	int n,l,r,res = 2000000001,l_mem,r_mem;
	scanf("%d",&n);
	l = l_mem = 0;
	r = r_mem = n-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	while(r>l)
	{
		if(abs(arr[l] + arr[r]) < res)
		{
			res = abs(arr[l] + arr[r]);
			l_mem = l;
			r_mem = r;
		}
		if(arr[l] + arr[r] > 0) r--;
		else l++;
	}
	printf("%d %d",arr[l_mem],arr[r_mem]);
}
