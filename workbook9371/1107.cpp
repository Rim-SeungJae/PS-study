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
 ���Ʈ����
 ��� ������ ���� 1�� ����,���ҽ��Ѱ��鼭 �Ǵ� ���� �ִ��� ã�� ���.
 �ش� �˰������� ã�� ���� 100-n�� ���밪�� ���Ͽ� �� ���� ���� �����ϸ� �ȴ�.
 �� �ڵ�� �� ���� �����ϰ� �ؼ��Ͽ��� ������ �ڵ嵵 ����������. 
 �Լ��� �� �̿��Ͽ� �ڵ带 ����ϰ� �ۼ������ν� �ݷ� ���� �۵��ϵ��� �ϴ� ���� ����. 
 */ 
