#include<cstdio>

using namespace std;

int b[9][9];
bool r[9][10],c[9][10],s[9][10],flag = false;

void bt(int x,int y)
{
	//printf("%d %d %d\n",x,y,b[x][y]);
	if(flag) return;
	if(x>=9)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				printf("%d",b[i][j]);
			}
			printf("\n");
		}
		flag = true;
		return;
	}
	int xf=x,yf=y;
	do
	{
		yf++;
		xf += yf/9;
		yf %= 9;
	}while(b[xf][yf]!=0 && xf<9);
	for(int i=1;i<=9;i++)
	{
		if(!flag && !r[x][i] && !c[y][i] && !s[x/3*3 + y/3][i])
		{
			b[x][y] = i;
			r[x][i] = true;
			c[y][i] = true;
			s[x/3*3 + y/3][i] = true;
			bt(xf,yf);
			b[x][y] = 0;
			r[x][i] = false;
			c[y][i] = false;
			s[x/3*3 + y/3][i] = false;
		}
	}
}

int main()
{
	int x=-1,y;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			scanf("%1d",&b[i][j]);
			if(x==-1 && b[i][j] == 0)
			{
				x = i;
				y = j;
			}
			//printf("%d ",i/3*3 + j/3);
			r[i][b[i][j]] = true;
			c[j][b[i][j]] = true;
			s[i/3*3 + j/3][b[i][j]] = true;
		}
	}
	bt(x,y);
}
/*
간단 백트래킹
*/ 
