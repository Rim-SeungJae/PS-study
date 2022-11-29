#include<cstdio>
int main()
{
	int n,m;
	bool btn[10]={0,};
	scanf("%d\n%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		btn[tmp] = 1;
	}
	int cnt = 0,target,digit=0;
	while(true)
	{
		int a=n+cnt,b=n-cnt,a_digit = 0,b_digit=0;
		if(a == 100 || b == 100)
		{
			target = 100;
			break;
		}
		if(a == 99 || b == 99)
		{
			target = 99;
			break;
		}
		if(a == 98 || b == 98)
		{
			target = 98;
			break;
		}
		if(a == 101 || b == 101)
		{
			target = 101;
			break;
		}
		if(a == 102 || b == 102)
		{
			target = 102;
			break;
		}
		if(b == 0)
		{
			if(btn[0])
			{
				cnt++;
				continue;
			}
			else
			{
				target = 0;
				break;
			}
		}
		else if(b>0){
			do
			{
				b_digit++;
				if(btn[b%10]) break;
				else b/=10;
			}while(b);
			if(b==0)
			{
				target = n-cnt;
				break;
			}
		}
		if(a == 0)
		{
			if(btn[0])
			{
				cnt++;
				continue;
			}
			else
			{
				target = 0;
				break;
			}
		}
		do
		{
			a_digit++;
			if(btn[a%10]) break;
			else a/=10;
		}while(a);
		if(a == 0)
		{
			target = n+cnt;
			break;
		}
		cnt++;
	}
	switch(target)
	{
		case 100:
			printf("%d",cnt);
			break;
		case 101:
		case 99:
			printf("%d",1+cnt);
			break;
		case 102:
		case 98:
			printf("%d",2+cnt);
			break;
		default:
			do
			{
				digit++;
				target/=10;
			}while(target);
			printf("%d",digit+cnt);
	}
 } 
 /*
 브루트포스
 대상 숫자의 값을 1씩 증가,감소시켜가면서 되는 값이 있는지 찾는 방식.
 1씩 증가시키기 않고 N - cnt의 자릿수만큼 증가시키는 방법도 있다.
 */ 
