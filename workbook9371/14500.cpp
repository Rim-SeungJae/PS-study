#include<cstdio>
#include<vector>
#include<queue>

using namespace std;



int bfs4(pair<int,int> p,int n, int m,vector <vector <int>> v,vector <vector <bool>> visited)
{
	queue<pair<int,int>> q;
	q.push(p);
	visit[p.first][p.second] = true
	
	int cnt=0,sum=0;
	
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		if(x+1 < n && !visited[x+1][y])
		{
			queue(push(make_pair(x+1,y)));
			visited[x+1][y] = true;
		}
		if(x-1 >= 0 && !visited[x-1][y])
		{
			queue(push(make_pair(x-1,y)));
			visited[x-1][y] = true;
		}
		if(y+1 < n && !visited[x][y+1])
		{
			queue(push(make_pair(x,y+1)));
			visited[x][y+1] = true;
		}
		if(y-1 >= 0 && !visited[x][y-1])
		{
			queue(push(make_pair(x,y-1)));
			visited[x][y-1] = true;
		}
		sum+=v[p.first][p.second];
		cnt++;
		
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector <vector <int>> v(n,(vector<int>(m,0)));
	vector <vector <bool>> visited(n,(vector<bool>(m,false)));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&v[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int max = 0,sum=0;
			sum
		}
	}
}
