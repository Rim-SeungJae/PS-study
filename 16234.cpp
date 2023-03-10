#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int n,l,r,arr[55][55],sum,cnt,idx=1,visited[55][55];
bool border_v[55][55] = {0,},border_h[55][55] = {0,};
int mem[3000];

bool inRange(int a)
{
	if(a>=0 && a<n) return true;
	else return false;
}

void DFS(int x,int y)
{
	if(visited[x][y]) return;
	visited[x][y] = idx;
	sum+=arr[x][y];
	cnt++;
	if(inRange(x+1) && border_h[x][y]) DFS(x+1,y);
	if(inRange(y+1) && border_v[x][y]) DFS(x,y+1);
	if(inRange(x-1) && border_h[x-1][y]) DFS(x-1,y);
	if(inRange(y-1) && border_v[x][y-1]) DFS(x,y-1);
}

int main()
{
	scanf("%d %d %d",&n,&l,&r);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int answer = 0;
	while(true)
	{
		bool continue_flag = false;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(inRange(j+1) && abs(arr[i][j] - arr[i][j+1]) >= l && abs(arr[i][j] - arr[i][j+1]) <= r)
				{
					border_v[i][j] = true;
					continue_flag = true;
				}
				else border_v[i][j] = false;
				if(inRange(i+1) && abs(arr[i][j] - arr[i+1][j]) >= l && abs(arr[i][j] - arr[i+1][j]) <= r)
				{
					border_h[i][j] = true;
					continue_flag = true;
				}
				else border_h[i][j] = false;
			}
		}
		fill(&visited[0][0],&visited[54][55],0);
		idx = 1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visited[i][j])
				{
					sum = 0;
					cnt = 0;
					DFS(i,j);
					mem[idx++] = sum/cnt;
				}
				if(visited[i][j]!=0) arr[i][j] = mem[visited[i][j]];
			}
		}
		if(!continue_flag) break;
		answer++;
	}
	printf("%d",answer);
}
/*
구현, 그래프 탐색
*/ 
