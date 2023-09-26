#include<cstdio>
#include<cmath>

using namespace std;


int main()
{
	int n,l,r,res = 2000000001,l_mem,r_mem;
	int arr[100010];
	scanf("%d",&n);
	l = l_mem = 0;
	r = r_mem = n-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	while(r>l)
	{
		int tmp = abs(arr[l] + arr[r]);
		if(tmp < res)
		{
			res = tmp;
			l_mem = l;
			r_mem = r;
		}
		if(res == 0) break;
		if(arr[l] + arr[r] > 0) r--;
		else l++;
	}
	printf("%d %d",arr[l_mem],arr[r_mem]);
}
/*
ดÜผ๘วั two-pointer
*/ 
