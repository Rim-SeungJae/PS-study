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
���Ʈ����.
�ܼ��� ��� ��츦 �˻����� ���� x�� m�� ���ذ��鼭
������ ����� ���� Ž���Ѵ�.
*/ 
