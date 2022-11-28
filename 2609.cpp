#include<cstdio>

int gcd(int a,int b)
{
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(b>a)
	{
		int tmp=a;
		a=b;
		b=tmp;
	}
	printf("%d\n%d",gcd(a,b),a/gcd(a,b)*b);
} 
/*
기본적인 유클리드 호제법 활용
*/ 
