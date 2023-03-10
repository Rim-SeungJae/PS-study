#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n,m,arr[55][55],min_result = 100000000;
bool visited[55][55];
vector<pair<int,int>> spot;
vector<pair<int,int>> virus;

bool inRange(int a)
{
	if(a>=0 && a<n) return true;
	return false;
}

int bfs()
{
	queue<pair<int,int>> q;
	int tmp[55][55];
	copy(&arr[0][0],&arr[54][55],&tmp[0][0]);
	fill(&visited[0][0],&visited[54][55],0);
	for(int i=0;i<virus.size();i++)
	{
		q.push(virus[i]);
		visited[virus[i].first][virus[i].second] = true;
		tmp[virus[i].first][virus[i].second] = 2;
	}
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();
		if(inRange(x-1) && !visited[x-1][y] && tmp[x-1][y] !=1)
		{
			visited[x-1][y] = true;
			tmp[x-1][y] = tmp[x][y]+1;
			q.push(make_pair(x-1,y));
		}
		if(inRange(x+1) && !visited[x+1][y] && tmp[x+1][y] !=1)
		{
			visited[x+1][y] = true;
			tmp[x+1][y] = tmp[x][y]+1;
			q.push(make_pair(x+1,y));
		}
		if(inRange(y-1) && !visited[x][y-1] && tmp[x][y-1] !=1)
		{
			visited[x][y-1] = true;
			tmp[x][y-1] = tmp[x][y]+1;
			q.push(make_pair(x,y-1));
		}
		if(inRange(y+1) && !visited[x][y+1] && tmp[x][y+1] !=1)
		{
			visited[x][y+1] = true;
			tmp[x][y+1] = tmp[x][y]+1;
			q.push(make_pair(x,y+1));
		}
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",tmp[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
	}
	
	int max_sec = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(tmp[i][j]==0) return -1;
			if(tmp[i][j] >= 2 && tmp[i][j]>max_sec)
			{
				if(arr[i][j] == 2)
				{
					if(2>max_sec) max_sec = 2;
				}
				else max_sec = tmp[i][j];
				//max_sec = tmp[i][j];
			}
		}
	}
	return max_sec;
}

void bt(int depth,int prev)
{
	if(depth == m){
		int result = bfs();
		//printf("%d\n",result);
		if(result<min_result && result!=-1) min_result = result;
	}
	else{
		for(int i=prev+1;i<spot.size();i++)
		{
			virus.push_back(spot[i]);
			bt(depth+1,i);
			virus.erase(virus.end()-1);
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
			if(arr[i][j] == 2) spot.push_back(make_pair(i,j));
			//if(arr[i][j] == 1) visited[i][j] = true;
		}
	}
	bt(0,-1);
	if(min_result == 100000000) printf("-1");
	else printf("%d",min_result-2);
}
/*
백트래킹 + 그래프 탐색
*/ 
