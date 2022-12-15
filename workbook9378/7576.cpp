#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int arr[1000][1000];

int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j] == 1)
			{
				q.push(make_pair(i,j));
			}
		}
	}
	q.push(make_pair(-1,-1));
	int cnt=0;
	while(!q.empty())
	{
		//printf("%d %d\n",q.front().first,q.front().second);
		pair<int,int> p = q.front();
		q.pop();
		int x=p.first,y=p.second;
		if(x==-1)
		{
			if(q.empty()) break;
			cnt++;
			q.push(make_pair(-1,-1));
			continue;
		}
		if(x+1<n && arr[x+1][y] == 0)
		{
			arr[x+1][y] = 1;
			q.push(make_pair(x+1,y));
		}
		if(y-1>=0 && arr[x][y-1] == 0)
		{
			arr[x][y-1] = 1;
			q.push(make_pair(x,y-1));
		}
		if(x-1>=0 && arr[x-1][y] == 0)
		{
			arr[x-1][y] = 1;
			q.push(make_pair(x-1,y));
		}
		if(y+1<m && arr[x][y+1] == 0)
		{
			arr[x][y+1] = 1;
			q.push(make_pair(x,y+1));
		}
	}
	int i;
	for(i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j] == 0)
			{
				i=n+1;
				break;
			}
		}
	}
	if(i!=n) printf("-1");
	else printf("%d",cnt);
} 
/*
dfs 응용
생각만 잘하면 풀 수 있는 간단한 문제
배열 범위를 벗어나는 접근에만 주의하자 
*/ 
