#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n;
	int arr[100010];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n,less<int>());
	int l=0,r=n-1;
	long long close_zero = 2000000010;
	int close_l,close_r;
	while(l<r)
	{
		long long sum = arr[l]+arr[r];
		if(abs(close_zero)>abs(sum))
		{
			close_zero=sum;
			close_l = l;
			close_r = r;
		}
		if(sum == 0) break;
		else if(sum > 0) r--;
		else l++;
	}
	printf("%d %d",arr[close_l],arr[close_r]);
}
/*
기초적인 투포인터
*/ 
