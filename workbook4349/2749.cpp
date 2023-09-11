#include<cstdio>

int main()
{
	long long n;
	int fib0 = 0, fib1 = 1, fib2;
	scanf("%lld",&n);
	for(long long i=2;i<=n;i++)
	{
		fib2 = (fib0 + fib1)%1000000;
		fib0 = fib1;
		fib1 = fib2;
	}
	printf("%d",fib2);
}
