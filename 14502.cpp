#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> virus;
int arr[10][10];
int n,m,max_cnt;

void dfs(int tmp[][10],bool visited[][10],int x,int y)
{
	if(x<0 || x>=n || y<0 || y>=m || visited[x][y] || tmp[x][y] == 1) return;
	visited[x][y] = true;
	tmp[x][y] = 2;
	dfs(tmp,visited,x+1,y);
	dfs(tmp,visited,x-1,y);
	dfs(tmp,visited,x,y+1);
	dfs(tmp,visited,x,y-1);
}

void bt(pair<int,int> wall[],int depth)
{
	if(depth==2)
	{
		int tmp[10][10];
		copy(&arr[0][0],&arr[9][10],&tmp[0][0]);
		tmp[wall[0].first][wall[0].second] = 1;
		tmp[wall[1].first][wall[1].second] = 1;
		tmp[wall[2].first][wall[2].second] = 1;
		bool visited[10][10] = {0,};
		for(int i=0;i<virus.size();i++)
		{
			dfs(tmp,visited,virus[i].first,virus[i].second);
		}
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				//printf("%d ",tmp[i][j]);
				if(tmp[i][j] == 0) cnt++;
			}
			//printf("\n");
		}
		//printf("\n");
		if(cnt>max_cnt)
		{
			max_cnt=cnt;
		}
		return;
	}
	int prev_x = wall[depth].first;
	int prev_y = wall[depth].second;
	for(int i=prev_x;i<n;i++)
	{
		for(int j = (i == prev_x ?prev_y+1:0);j<m;j++)
		{
			if(arr[i][j]!=0) continue;
			wall[depth+1] = make_pair(i,j);
			bt(wall,depth+1);
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]== 2)
			{
				virus.push_back(make_pair(i,j));
			}
		}
	}
	pair<int,int> wall[5];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]!=0) continue;
			wall[0] = make_pair(i,j);
			bt(wall,0);
		}
	}
	printf("%d",max_cnt);
}
/*
기본적인 백트래킹
n,m의 값이 커져도 해결할 수 잇는 문제인가?
*/ 
