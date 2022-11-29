#include<cstdio>
int main()
{
	int e,s,m;
	scanf("%d %d %d",&e,&s,&m);
	int x=0,y=0,z=0,cnt=0;
	while(true)
	{
		cnt++;
		x++;
		y++;
		z++;
		if(x>15) x=1;
		if(y>28) y=1;
		if(z>19) z=1;
		if(e==x && y==s && z==m) break;
	}
	printf("%d",cnt);
 } 
 /*
 브루트포스.
 x=y=z=0 부터 입력된 값이 될때까지 한해씩 더해간다.
 */ 
