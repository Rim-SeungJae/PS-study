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
���Ʈ����
�ش� �ڵ�� n���� ���ڸ���, ���ڸ���, ..., x�ڸ��� ���� ��ִ��� ī�����ϴ� ���.
 #include<cstdio>
int n, r;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i *= 10) 
		r += n - i + 1;
    printf("%d", r);
    return 0;
}
�� �ڵ�ó�� �����ڸ�, �����ڸ�, ..., x���ڸ��� �� ��� �����ϴ��� ī�����ϴ� ���ٵ� ����.
*/ 
