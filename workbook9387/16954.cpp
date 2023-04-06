#include<cstdio>
#include<queue>

using namespace std;

using ii = pair<int,int>;
char arr[10][10];
int d;

bool inRange(int a)
{
	return a>=0 && a<8;
}
bool inRange2(int a)
{
	return a>=0 && a<8-d;
}

bool bfs()
{
	queue<ii> q;
	bool visited[10][10]={0,};
	q.push(make_pair(7,0));
	q.push(make_pair(10,10));
	while(!q.empty())
	{
		int r,c;
		r = q.front().first;
		c = q.front().second;
		//printf("%d %d:%d\n",r,c,d);
		q.pop();
		if(r == 10 && d<8)
		{
			d++;
			q.push(make_pair(10,10));
			continue;
		}
		if(r<0) return true;
		if(arr[r][c] == '#') continue;
		if(r==0) return true;
		if(!visited[r][c])
		{
			visited[r][c] = true;
			q.push(make_pair(r-1,c));
		}
		if(inRange2(r-1) && !visited[r-1][c] && arr[r-1][c] != '#')
		{
			visited[r-1][c] = true;
			q.push(make_pair(r-2,c));
		}
		if(inRange2(r-1) && inRange(c-1) && !visited[r-1][c-1] && arr[r-1][c-1] != '#')
		{
			visited[r-1][c-1] = true;
			q.push(make_pair(r-2,c-1));
		}
		if(inRange2(r-1) && inRange(c+1) && !visited[r-1][c+1] && arr[r-1][c+1] != '#')
		{
			visited[r-1][c+1] = true;
			q.push(make_pair(r-2,c+1));
		}
		if( inRange(c-1) && !visited[r][c-1] && arr[r][c-1] != '#')
		{
			visited[r][c-1] = true;
			q.push(make_pair(r-1,c-1));
		}
		if( inRange(c+1) && !visited[r][c+1] && arr[r][c+1] != '#')
		{
			visited[r][c+1] = true;
			q.push(make_pair(r-1,c+1));
		}
		if(inRange2(r+1) && !visited[r+1][c] && arr[r+1][c] != '#')
		{
			visited[r+1][c] = true;
			q.push(make_pair(r,c));
		}
		if(inRange2(r+1) && inRange(c-1) && !visited[r+1][c-1] && arr[r+1][c-1] != '#')
		{
			visited[r+1][c-1] = true;
			q.push(make_pair(r,c-1));
		}
		if(inRange2(r+1) && inRange(c+1) && !visited[r+1][c+1] && arr[r+1][c+1] != '#')
		{
			visited[r+1][c+1] = true;
			q.push(make_pair(r,c+1));
		}
	}
	return false;
}

int main()
{
	for(int i=0;i<8;i++)
	{
		scanf("\n");
		for(int j=0;j<8;j++)
		{
			scanf("%1c",&arr[i][j]);
		}
	}
	printf("%d",bfs());
}
/*
문제 조건을 잘 확인할것
제자리에 서있는것도 가능하다
*/ 
