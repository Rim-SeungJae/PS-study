#include<cstdio>

using namespace std;

int main()
{
	long long a,b,c,res = 1;
	scanf("%lld %lld %lld",&a,&b,&c);
	while(b)
	{
		if(b&1 !=0)
		{
			res *= a;
			res %= c;
		}
		a *= a;
		a %= c;
		b >>= 1;
	}
	printf("%d",res);
}
/*
제곱의 분할정복
*/ 
