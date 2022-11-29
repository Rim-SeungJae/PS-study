#include<cstdio>
#include<algorithm> 

using namespace std;
int main()
{
	int n,arr[55];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	printf("%d",arr[0] * arr[n-1]);
}
/*
약수들을 이용해서 원래의 수 N을 구하는 문제.
N = 가장 큰 약수 * 가장 작은 약수
임을 이용하자
*/ 
