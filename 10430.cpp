#include <cstdio>

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d\n%d\n%d\n%d",(a+b)%c,((a%c)+(b%c))%c,a*b%c,((a%c)*(b%c))%c);
}
/*
(A+B)%C는 ((A%C) + (B%C))%C?와 같을까?
(A×B)%C는 ((A%C) × (B%C))%C 와 같을까?
의 이해를 위한 단순한 문제
*/ 
