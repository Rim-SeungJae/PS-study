#include<cstdio>

int arr[1000010];

int main()
{
	int n,b,c;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	scanf("%d %d",&b,&c);
	long long int total = 0;
	for(int i=0;i<n;i++)
	{
		total+=1;
		arr[i]-=b;
		if(arr[i]>0) total+=arr[i]/c+(arr[i]%c!=0);
	}
	printf("%lld",total);
}
/*
오버플로우에 주의
*/ 
