#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int m,n,min_break[110][110];
bool arr[110][110],visited[110][110];

void bfs()
{
	deque<pair<char,char>> q;
	q.push_front(make_pair(0,0));
	min_break[0][0]= 0;
	visited[0][0] = true;
	
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		int cur_break=min_break[x][y];
		//printf("%d %d %d\n",x,y,cur_break);
		q.pop_front();
		if(x+1<n && min_break[x+1][y]>cur_break && !visited[x+1][y])
		{
			visited[x+1][y] = true;
			if(arr[x+1][y])
			{
				min_break[x+1][y] = cur_break+1;
				q.push_back(make_pair(x+1,y));
			}
			else
			{
				min_break[x+1][y] = cur_break;
				q.push_front(make_pair(x+1,y));
			}
		}
		if(y+1<m && min_break[x][y+1]>cur_break && !visited[x][y+1])
		{
			visited[x][y+1] = true;
			if(arr[x][y+1])
			{
				min_break[x][y+1] = cur_break+1;
				q.push_back(make_pair(x,y+1));
			}
			else
			{
				min_break[x][y+1] = cur_break;
				q.push_front(make_pair(x,y+1));
			}
		}
		if(x-1>=0 && min_break[x-1][y]>cur_break && !visited[x-1][y])
		{
			visited[x-1][y] = true;
			if(arr[x-1][y])
			{
				min_break[x-1][y] = cur_break+1;
				q.push_back(make_pair(x-1,y));
			}
			else
			{
				min_break[x-1][y] = cur_break;
				q.push_front(make_pair(x-1,y));
			}
		}
		if(y-1>=0 && min_break[x][y-1]>cur_break && !visited[x][y-1])
		{
			visited[x][y-1] = true;
			if(arr[x][y-1])
			{
				min_break[x][y-1] = cur_break+1;
				q.push_back(make_pair(x,y-1));
			}
			else
			{
				min_break[x][y-1] = cur_break;
				q.push_front(make_pair(x,y-1));
			}
		}
	}
	
}

int main()
{
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	fill(&min_break[0][0],&min_break[n-1][m],100000000);
	bfs();
	printf("%d",min_break[n-1][m-1]);
}
/*
0-1 bfs
특수한 경우 다익스트라를 대체할 수 있는 알고리즘
해당 알고리즘에서 deque의 사용방법을 잘 파악하자
또한, deque의 메모리 초과가 나지 않도록 visited를 잘 활용해야 한다. 
*/ 
