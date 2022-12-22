#include<cstdio>

int arr[30][30];
int main()
{
	int n,m,x,y,k;
	scanf("%d %d %d %d %d",&n,&m,&x,&y,&k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int up = 0,down = 0, left = 0, right = 0, top = 0, bottom = 0;
	for(int i=0;i<k;i++)
	{
		int cmd,tmp;
		scanf("%d",&cmd);
		switch(cmd)
		{
			case 1:
				if(y+1 >= m) break;
				y+=1;
				tmp = right;
				right = top;
				top = left;
				left = bottom;
				bottom = tmp;
				if(arr[x][y] == 0)
				{
					arr[x][y] = bottom;
				}
				else{
					bottom = arr[x][y];
					arr[x][y] = 0;
				}
				printf("%d\n",top);
				break;
			case 2:
				if(y-1 < 0) break;
				y-=1;
				tmp = right;
				right = bottom;
				bottom = left;
				left = top;
				top = tmp;
				if(arr[x][y] == 0)
				{
					arr[x][y] = bottom;
				}
				else{
					bottom = arr[x][y];
					arr[x][y] = 0;
				}
				printf("%d\n",top);
				break;
			case 3:
				if(x-1 < 0) break;
				x-=1;
				tmp = top;
				top = down;
				down = bottom;
				bottom = up;
				up = tmp;
				if(arr[x][y] == 0)
				{
					arr[x][y] = bottom;
				}
				else{
					bottom = arr[x][y];
					arr[x][y] = 0;
				}
				printf("%d\n",top);
				break;
			case 4:
				if(x+1 >= n) break;
				x+=1;
				tmp = top;
				top = up;
				up = bottom;
				bottom = down;
				down = tmp;
				if(arr[x][y] == 0)
				{
					arr[x][y] = bottom;
				}
				else{
					bottom = arr[x][y];
					arr[x][y] = 0;
				}
				printf("%d\n",top);
				break;
		}
	}
}
/*
단순 구현 
골드 치고 쉬운 문제
*/ 
