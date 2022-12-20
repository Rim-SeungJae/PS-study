#include<cstdio>

char arr[30][30];
int n,m,min = 10;
bool isFound = false;

int move(int x,int y,int dir)
{
	switch(dir)
	{
		case 1:
			if(y-1<0 || arr[x][y-1] == '.') return y-1;
			else return y;
		case 2:
			if(y+1>=m || arr[x][y+1] == '.') return y+1;
			else return y;
		case 3:
			if(x-1<0 || arr[x-1][y] == '.') return x-1;
			else return x;
		case 4:
			if(x+1>=n || arr[x+1][y] == '.') return x+1;
			else return x;
	}
}

bool out(int x,int y)
{
	if(x>=n || x<0 || y>=m || y<0) return true;
	else return false;
}

void bt(int cnt, int coin1_x, int coin1_y, int coin2_x,int coin2_y)
{
	if(cnt > min) return;
	//printf("%d %d %d %d\n",coin1_x,coin1_y,coin2_x,coin2_y);
	if(out(coin1_x,coin1_y) && out(coin2_x,coin2_y)) return;
	if(out(coin1_x,coin1_y) || out(coin2_x,coin2_y)) 
	{
		min = cnt;
		isFound = true;
		return;
	}
	bt(cnt+1,move(coin1_x,coin1_y,3),coin1_y,move(coin2_x,coin2_y,3),coin2_y);
	bt(cnt+1,move(coin1_x,coin1_y,4),coin1_y,move(coin2_x,coin2_y,4),coin2_y);
	bt(cnt+1,coin1_x,move(coin1_x,coin1_y,1),coin2_x,move(coin2_x,coin2_y,1));
	bt(cnt+1,coin1_x,move(coin1_x,coin1_y,2),coin2_x,move(coin2_x,coin2_y,2));
}

int main()
{
	int coin1_x= - 1,coin2_x = -1,coin1_y = -1,coin2_y = -1;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("\n");
		for(int j=0;j<m;j++)
		{
			scanf("%c",&arr[i][j]);
			if(arr[i][j] == 'o')
			{
				if(coin1_x == -1)
				{
					coin1_x = i;
					coin1_y = j;
					arr[i][j] = '.';
				}
				else
				{
					coin2_x = i;
					coin2_y = j;
					arr[i][j] = '.';
				}
			}
			
		}
	}
	bt(0,coin1_x,coin1_y,coin2_x,coin2_y);
	if(isFound) printf("%d",min);
	else printf("-1");
}
/*
백트래킹을 활용한 풀이법
그래프 탐색을 이용해서도 풀 수 있는 듯 하니 참고할것.
*/ 
