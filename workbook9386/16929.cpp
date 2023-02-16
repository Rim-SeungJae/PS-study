#include<cstdio>

int n,m;
char arr[60][60];
bool visited[60][60],result;

void dfs(int dir,int x,int y,int depth)
{
	//printf("%d %d %d\n",x,y,result);
	if(dir!=1 && x-1>=0 && arr[x-1][y] == arr[x][y])
	{
		if(visited[x-1][y])
		{
			if(depth>=3) result=true;
		}
		else{
			visited[x-1][y] = true;
			dfs(0,x-1,y,depth+1);
		}
	}
	if(dir!=0 && x+1<n && arr[x+1][y] == arr[x][y])
	{
		if(visited[x+1][y])
		{
			if(depth>=3) result=true;
		}
		else{
			visited[x+1][y] = true;
			dfs(1,x+1,y,depth+1);
		}
	}
	if(dir!=3 && y-1>=0 && arr[x][y-1] == arr[x][y])
	{
		if(visited[x][y-1])
		{
			if(depth>=3) result=true;
		}
		else{
			visited[x][y-1] = true;
			dfs(2,x,y-1,depth+1);
		}
	}
	if(dir!=2 && y+1<m && arr[x][y+1] == arr[x][y])
	{
		if(visited[x][y+1])
		{
			if(depth>=3) result=true;
		}
		else{
			visited[x][y+1] = true;
			dfs(3,x,y+1,depth+1);
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("\n");
		for(int j=0;j<m;j++)
		{
			scanf("%1c",&arr[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visited[i][j]) dfs(-1,i,j,1);
		}
	}
	result?printf("Yes"):printf("No");
}
/*
기본적인 dfs 변형
사이클 탐지 알고리즘에 대해 공부해보아도 좋다 
*/ 
