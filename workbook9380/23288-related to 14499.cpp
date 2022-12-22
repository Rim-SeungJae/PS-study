#include<cstdio>
#include<vector>

using namespace std;

int arr[30][30],score[30][30],cnt;
bool visited[30][30];
vector<pair<int,int>> linked;

void dfs(int x,int y,int n,int m,int num)
{
	if(x<0 || y<0 || x>=n || y >=m || visited[x][y] || arr[x][y]!= num)
	{
		return;
	}
	visited[x][y] = true;
	cnt++;
	linked.push_back(make_pair(x,y));
	dfs(x-1,y,n,m,num);
	dfs(x,y-1,n,m,num);
	dfs(x+1,y,n,m,num);
	dfs(x,y+1,n,m,num);
	return;	
}
 
int main()
{
	int n,m,k,x=0,y=0;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visited[i][j]) dfs(i,j,n,m,arr[i][j]);
			for(int k=0;k<linked.size();k++)
			{
				score[linked[k].first][linked[k].second] = arr[i][j] * cnt;
			}
			linked.clear();
			cnt=0;
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",score[i][j]);
		}
		printf("\n");
	}
	*/
	int up = 2,down = 5, left = 4, right = 3, top = 1, bottom = 6,cmd = 0,total = 0;
	for(int i=0;i<k;i++)
	{
		int tmp;
		switch(cmd)
		{
			case 0:
				if(y+1 >= m)
				{
					cmd = (cmd+2)%4;
					i--;
					break;
				}
				y+=1;
				tmp = right;
				right = top;
				top = left;
				left = bottom;
				bottom = tmp;
				if(bottom > arr[x][y]) cmd = (cmd + 1)%4;
				else if(bottom < arr[x][y]) cmd = (cmd+3)%4;
				total += score[x][y];
				break;
			case 1:
				if(x+1 >= n)
				{
					cmd = (cmd+2)%4;
					i--;
					break;
				}
				x+=1;
				tmp = top;
				top = up;
				up = bottom;
				bottom = down;
				down = tmp;
				if(bottom > arr[x][y]) cmd = (cmd + 1)%4;
				else if(bottom < arr[x][y]) cmd = (cmd+3)%4;
				total += score[x][y];
				break;
			case 2:
				if(y-1 < 0)
				{
					cmd = (cmd+2)%4;
					i--;
					break;
				}
				y-=1;
				tmp = right;
				right = bottom;
				bottom = left;
				left = top;
				top = tmp;
				if(bottom > arr[x][y]) cmd = (cmd + 1)%4;
				else if(bottom < arr[x][y]) cmd = (cmd+3)%4;
				total += score[x][y];
				break;
			case 3:
				if(x-1 < 0)
				{
					cmd = (cmd+2)%4;
					i--;
					break;
				}
				x-=1;
				tmp = top;
				top = down;
				down = bottom;
				bottom = up;
				up = tmp;
				if(bottom > arr[x][y]) cmd = (cmd + 1)%4;
				else if(bottom < arr[x][y]) cmd = (cmd+3)%4;
				total += score[x][y];
				break;
		}
		//printf("%d %d %d\n",total,x,y);
	}
	
	printf("%d",total);
}
/*
14499번 주사위  굴리기  문제의  다른 버전
복잡하지만 어렵진 않다 
*/ 
