#include<cstdio>

int main()
{
	int a,b,c,n;
	a=1;
	b=2;
	scanf("%d",&n);
	if(n == 1) printf("1");
	else if(n==2) printf("2");
	else
	{
		for(int i=2;i<n;i++)
		{
			c = (a + b)%10007;
			a = b;
			b = c;
		}
		printf("%d",b);
	} 
} 
/*
기본적인 다이나믹 
*/ 
