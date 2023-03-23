#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n,m,arr[22][22];
bool visited[22][22];

bool inRange(int a)
{
	return a>=0 && a<n;
}

pair<int,int> bfs(int src_r,int src_c)
{
	queue<pair<int,int>> q;
	q.push(make_pair(src_r,src_c));
	visited[src_r][src_c] = true;
	int color = arr[src_r][src_c];
	int cnt=0,rainbow=0;
	vector<pair<int,int>> rainbows;
	while(!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if(arr[r][c]==0)
		{
			rainbow++;
			rainbows.push_back(make_pair(r,c));
		}
		cnt++;
		if(inRange(r-1) && !visited[r-1][c] && (arr[r-1][c]==color || arr[r-1][c] == 0))
		{
			visited[r-1][c] = true;
			q.push(make_pair(r-1,c));
		}
		if(inRange(r+1) && !visited[r+1][c] && (arr[r+1][c]==color || arr[r+1][c] == 0))
		{
			visited[r+1][c] = true;
			q.push(make_pair(r+1,c));
		}
		if(inRange(c-1) && !visited[r][c-1] && (arr[r][c-1]==color || arr[r][c-1] == 0))
		{
			visited[r][c-1] = true;
			q.push(make_pair(r,c-1));
		}
		if(inRange(c+1) && !visited[r][c+1] && (arr[r][c+1]==color || arr[r][c+1] == 0))
		{
			visited[r][c+1] = true;
			q.push(make_pair(r,c+1));
		}
	}
	for(int i=0;i<rainbows.size();i++)
	{
		visited[rainbows[i].first][rainbows[i].second] = false;
	}
	return make_pair(cnt,rainbow);
}

void bfs_erase(int src_r,int src_c)
{
	queue<pair<int,int>> q;
	q.push(make_pair(src_r,src_c));
	visited[src_r][src_c] = true;
	int color = arr[src_r][src_c];
	while(!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		arr[r][c] = -2;
		if(inRange(r-1) && !visited[r-1][c] && (arr[r-1][c]==color || arr[r-1][c] == 0))
		{
			visited[r-1][c] = true;
			q.push(make_pair(r-1,c));
		}
		if(inRange(r+1) && !visited[r+1][c] && (arr[r+1][c]==color || arr[r+1][c] == 0))
		{
			visited[r+1][c] = true;
			q.push(make_pair(r+1,c));
		}
		if(inRange(c-1) && !visited[r][c-1] && (arr[r][c-1]==color || arr[r][c-1] == 0))
		{
			visited[r][c-1] = true;
			q.push(make_pair(r,c-1));
		}
		if(inRange(c+1) && !visited[r][c+1] && (arr[r][c+1]==color || arr[r][c+1] == 0))
		{
			visited[r][c+1] = true;
			q.push(make_pair(r,c+1));
		}
	}
	return;
}

void spin()
{
	// spin
	int new_A[200][200];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			new_A[n-1-j][i] = arr[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j] = new_A[i][j];
		}
	}
	return;
}

void grav()
{
	for(int i=0;i<n;i++)
	{
		int dst = n-1;
		for(int j=n-1;j>=0;j--)
		{
			if(arr[j][i] == -1) dst = j-1;
			else if(arr[j][i] != -2)
			{
				int tmp = arr[j][i];
				arr[j][i] = -2;
				arr[dst][i] = tmp;
				dst --;
			}
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int score = 0;
	while(true)
	{
		// 1
		int max_cnt = 0,max_rainbow=0,max_r=-1,max_c=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]>0 && !visited[i][j])
				{
					pair<int,int> tmp = bfs(i,j);
					if(max_cnt<tmp.first)
					{
						max_cnt = tmp.first;
						max_rainbow = tmp.second;
						max_r = i;
						max_c = j;
					}
					else if(max_cnt==tmp.first && max_rainbow<=tmp.second)
					{
						max_cnt = tmp.first;
						max_rainbow = tmp.second;
						max_r = i;
						max_c = j;
					}
				}
			}
		}
		fill(&visited[0][0],&visited[21][22],0);
		// 2
		if(max_cnt<2 || max_cnt-max_rainbow<1) break;
		bfs_erase(max_r,max_c);
		fill(&visited[0][0],&visited[21][22],0);
		score += max_cnt * max_cnt;
		
		// 3
		grav();

		// 4
		spin();

		// 5
		grav();

	}
	printf("%d",score);
}
/*
조건이 복잡한 구현, 시뮬레이션
*/ 
