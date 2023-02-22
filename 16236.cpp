#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int n,arr[22][22],dist[22][22] = {0,},size = 2, eat = 0, sharkx,sharky,cnt = 0;
	bool bstop = false,visited[22][22] = {0,};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j] == 9){
				sharkx = i;
				sharky = j;
				arr[i][j] = 0;
			}
		}
	}

	queue<pair<int,int>> q;
	visited[sharkx][sharky] = true;
	q.push(make_pair(sharkx,sharky));
	while(!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		if(curx-1 >= 0 && !visited[curx-1][cury] && arr[curx-1][cury]<=size)
		{
			visited[curx-1][cury] = true;
			dist[curx-1][cury] = dist[curx][cury] + 1;
			q.push(make_pair(curx-1,cury));
		}
		if(cury-1 >= 0 && !visited[curx][cury-1] && arr[curx][cury-1]<=size)
		{
			visited[curx][cury-1]=true;
			dist[curx][cury-1] = dist[curx][cury] + 1;
			q.push(make_pair(curx,cury-1));
		}
		if(cury+1 < n && !visited[curx][cury+1] && arr[curx][cury+1]<=size)
		{
			visited[curx][cury+1] = true;
			dist[curx][cury+1] = dist[curx][cury] + 1;
			q.push(make_pair(curx,cury+1));
		}
		if(curx+1 < n && !visited[curx+1][cury] && arr[curx+1][cury]<=size)
		{
			visited[curx+1][cury] = true;
			dist[curx+1][cury] = dist[curx][cury] + 1;
			q.push(make_pair(curx+1,cury));
		}
		if(q.empty())
		{
			int min_dist = 100000,targetx=-1,targety=-1;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(visited[i][j] && dist[i][j]<min_dist && arr[i][j] < size && arr[i][j] !=0)
					{
						min_dist = dist[i][j];
						targetx = i;
						targety = j;
					}
				}
			}
			if(targetx == -1) break;
			arr[targetx][targety] = 0;
			eat++;
			if(eat == size)
			{
				eat = 0;
				size++;
			}
			cnt+=min_dist;
			sharkx = targetx;
			sharky = targety;
			q = queue<pair<int,int>>();
			q.push(make_pair(sharkx,sharky));
			fill(&visited[0][0],&visited[21][22],0);
			fill(&dist[0][0],&dist[21][22],0);
			visited[sharkx][sharky] = true;
			/*
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					printf("%d ",arr[i][j]);
				}
				printf("\n");
			}
			printf("\n%d %d\n",size,cnt);
			*/
		}
	}
	
	printf("%d",cnt);
}
/*
구현, 시뮬레이션
왼쪽 위의 물고기부터 먹는 기능을 구현해야 하는데,
BFS의 탐색 우선순위를 활용한 풀이가 불가능하다. 
탐색을 전부 마친 뒤에 먹을 수 있는 물고기들 전체를 확인하는 방식으로 구현해야 한다.
*/ 
