#include<cstdio>
int main()
{
	int x = 9,n,cnt=0,digit=1;
	scanf("%d",&n);
	while(n)
	{
		if(n < x)
		{
			cnt += n*digit;
			break;
		} 
		n-=x;
		cnt += x * digit;
		x*=10;
		digit++;
	}
	printf("%d",cnt);
}
/*
브루트포스
해당 코드는 n까지 한자리수, 두자리수, ..., x자리수 들이 몇개있는지 카운팅하는 방식.
 #include<cstdio>
int n, r;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i *= 10) 
		r += n - i + 1;
    printf("%d", r);
    return 0;
}
위 코드처럼 일의자리, 십의자리, ..., x의자리가 총 몇번 등장하는지 카운팅하는 접근도 좋다.
*/ 
