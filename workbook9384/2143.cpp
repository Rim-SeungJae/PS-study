#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int a[1010]={0,},b[1010]={0,},t,n,m,sum=0;
	long long int result=0;
	vector<int> a_sum,b_sum; 
	scanf("%d",&t);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		for(int j=0;j<i;j++)
		{
			sum-=a[j];
			a_sum.push_back(sum);
			sum+=a[j];
		}
		sum-=a[i];
	}
	sum = 0;
	for(int i=1;i<=m;i++)
	{
		sum+=b[i];
		for(int j=0;j<i;j++)
		{
			sum-=b[j];
			b_sum.push_back(sum);
			sum+=b[j];
		}
		sum-=b[i];
	}
	sort(a_sum.begin(),a_sum.end());
	sort(b_sum.begin(),b_sum.end());
	for(int i=0;i<a_sum.size();i++)
	{
		int target = t-a_sum[i];
		result += upper_bound(b_sum.begin(),b_sum.end(),target) - lower_bound(b_sum.begin(),b_sum.end(),target);
	}
	printf("%lld",result);
}
/*
브루트포스 
정렬 및 lower_bound, upper_bound 함수를 활용한 이진탐색으로 코드의 효율성을 높이는 것이 포인트.
result 변수의 오버플로우에 주의하자
*/ 
