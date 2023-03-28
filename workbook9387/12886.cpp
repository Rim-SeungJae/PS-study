#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int sum;
bool visited[1000][1000];
bool success = false;

void bfs(int a,int b,int c)
{
	queue<pair<int,int>> q;
	q.push(make_pair(a,b));
	visited[a][b] = true;
	while(!q.empty())
	{
		int x,y,z;
		x = q.front().first;
		y = q.front().second;
		z = sum - x - y;
		printf("%d %d %d\n",x,y,z);
		if(x==y && y==z)
		{
			success = true;
			break;
		}
		q.pop();
		if(x!=y)
		{
			if(x>y && !visited[x-y][y+y])
			{
				visited[x-y][y+y] = true;
				q.push(make_pair(x-y,y+y));
			}
			else if(x<y && !visited[x+x][y-x])
			{
				visited[x+x][y-x] = true;
				q.push(make_pair(x+x,y-x));
			}
		}
		if(x!=z)
		{
			if(x>z && !visited[x-z][y])
			{
				visited[x-z][y] = true;
				q.push(make_pair(x-z,y));
			}
			else if(x<z && !visited[x+x][y])
			{
				visited[x+x][y] = true;
				q.push(make_pair(x+x,y));
			}
		}
		if(z!=y)
		{
			if(z>y && !visited[x][y+y])
			{
				visited[x][y+y] = true;
				q.push(make_pair(x,y+y));
			}
			else if(z<y && !visited[x][y-z])
			{
				visited[x][y-z] = true;
				q.push(make_pair(x,y-z));
			}
		}
	}
}

int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	sum = a+b+c;
	bfs(a,b,c);
	printf("%d",success);
}
