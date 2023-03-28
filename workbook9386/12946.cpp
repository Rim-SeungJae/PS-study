#include<cstdio>

const int dirr[6] = {-1,-1,0,1,1,0}, dirc[6] = {0,1,1,0,-1,-1};

int n;
char arr[55][55];
int visited[55][55];
bool oddCycle;

bool inRange(int a)
{
	return a>=0 && a<n;
}

void dfs(int r,int c)
{
	if(inRange(r-1) && inRange(c+1) && arr[r-1][c+1]=='X')
	{
		if(!visited[r-1][c+1])
		{
			visited[r-1][c+1] = visited[r][c]+1;
			dfs(r-1,c+1);
		}
		else if((visited[r][c] - visited[r-1][c+1])%2 == 0){
			oddCycle = true;
		}
	}
	if(inRange(r-1) && arr[r-1][c]=='X')
	{
		if(!visited[r-1][c])
		{
			visited[r-1][c] = visited[r][c]+1;
			dfs(r-1,c);
		}
		else if((visited[r][c] - visited[r-1][c])%2 == 0){
			oddCycle = true;
		}
	}
	if(inRange(c-1) && arr[r][c-1]=='X')
	{
		if(!visited[r][c-1])
		{
			visited[r][c-1] = visited[r][c]+1;
			dfs(r,c-1);
		}
		else if((visited[r][c] - visited[r][c-1])%2 == 0){
			oddCycle = true;
		}
	}
	if(inRange(c+1) && arr[r][c+1]=='X')
	{
		if(!visited[r][c+1])
		{
			visited[r][c+1] = visited[r][c]+1;
			dfs(r,c+1);
		}
		else if((visited[r][c] - visited[r][c+1])%2 == 0){
			oddCycle = true;
		}
	}
	if(inRange(r+1) && inRange(c-1) && arr[r+1][c-1]=='X')
	{
		if(!visited[r+1][c-1])
		{
			visited[r+1][c-1] = visited[r][c]+1;
			dfs(r+1,c-1);
		}
		else if((visited[r][c] - visited[r+1][c-1])%2 == 0){
			oddCycle = true;
		}
	}
	if(inRange(r+1) && arr[r+1][c]=='X')
	{
		if(!visited[r+1][c])
		{
			visited[r+1][c] = visited[r][c]+1;
			dfs(r+1,c);
		}
		else if((visited[r][c] - visited[r+1][c])%2 == 0){
			oddCycle = true;
		}
	}
	return;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("\n");
		for(int j=0;j<n;j++)
		{
			scanf("%c",&arr[i][j]);
		}
	}
	int max_d = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j] == 'X' && !visited[i][j])
			{
				visited[i][j] = 1;
				dfs(i,j);
			}
			if(visited[i][j]>max_d) max_d = visited[i][j];
		}
	}
	switch(max_d)
	{
		case 0:
			printf("0");
			break;
		case 1:
			printf("1");
			break;
		case 2:
			printf("2");
			break;
		default:
			if(oddCycle) printf("3");
			else printf("2");
			break;
	}
}
/*
독특한 그래프 문제
정점의 개수가 홀수인 사이클이 존재한다면 색이 3개 필요하다
*/ 
