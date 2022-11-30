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
 해당 알고리즘으로 찾은 값과 100-n의 절대값을 비교하여 더 작은 것을 선택하면 된다.
 본 코드는 이 논리를 복잡하게 해석하였기 때문에 코드도 복잡해진것. 
 함수를 잘 이용하여 코드를 명료하게 작성함으로써 반례 없이 작동하도록 하는 것이 중점. 
 */ 
