#include <cstdio>

long long gcd(long long a,long long b)
{
	if(b>a)
	{
		int tmp=a;
		a=b;
		b=tmp;
	}
	if(b == 0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long m,n,x,y;
		scanf("%lld %lld %lld %lld",&m,&n,&x,&y);
		long long int j,lcm = m/gcd(m,n)*n;
		for(j=x;j<=lcm;j+=m)
		{
			if(j%n == y%n)
			{
				printf("%lld\n",j);
				break;
			}
		}
		if(j>lcm)
		{
			printf("-1\n");
		}
	}
}
/*
브루트포스.
단순히 모든 경우를 검사하지 말고 x에 m을 더해가면서
가능한 경우의 수만 탐색한다.
*/ 
