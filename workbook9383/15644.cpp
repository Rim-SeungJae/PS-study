#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;

int n,m,maxi,result = -1;
string result_path;
char arr[11][11],visited[11][11][11][11];
int dir_x[4] = {0,1,0,-1}, dir_y[4] = {1,0,-1,0};//RDLU
char dir[5] = "RDLU";

void bt(int k,int r_x,int r_y,int b_x,int b_y,string path)
{
	//printf("%d %d %d %d %d\n",k,r_x,r_y,b_x,b_y);
	if(k>10) return;
	if(result<k && result != -1) return;
	for(int i=0;i<4;i++)
	{
		int r_x_t = r_x, r_y_t = r_y, b_x_t = b_x, b_y_t = b_y;
		while(!(arr[r_x_t+dir_x[i]][r_y_t+dir_y[i]] == '#') && !(arr[r_x_t][r_y_t] == 'O') && ((r_x_t+dir_x[i]!=b_x_t || r_y_t+dir_y[i]!=b_y_t || arr[b_x_t][b_y_t] == 'O')))
		{
			r_x_t += dir_x[i];
			r_y_t += dir_y[i];
		}
		while(!(arr[b_x_t+dir_x[i]][b_y_t+dir_y[i]] == '#') && !(arr[b_x_t][b_y_t] == 'O') && ((b_x_t+dir_x[i]!=r_x_t || b_y_t+dir_y[i]!=r_y_t || arr[r_x_t][r_y_t] == 'O')))
		{
			b_x_t += dir_x[i];
			b_y_t += dir_y[i];
		}
		while(!(arr[r_x_t+dir_x[i]][r_y_t+dir_y[i]] == '#') && !(arr[r_x_t][r_y_t] == 'O') && ((r_x_t+dir_x[i]!=b_x_t || r_y_t+dir_y[i]!=b_y_t || arr[b_x_t][b_y_t] == 'O')))
		{
			r_x_t += dir_x[i];
			r_y_t += dir_y[i];
		}
		//printf("%d %d %d %d\n",r_x_t,r_y_t,b_x_t,b_y_t);
		if(arr[b_x_t][b_y_t] == 'O') continue;
		else if(arr[r_x_t][r_y_t] == 'O')
		{
			result = k;
			path.push_back(dir[i]);
			result_path = path;
			return;
		}
		else
		{
			if(visited[r_x_t][r_y_t][b_x_t][b_y_t]>k)
			{
				visited[r_x_t][r_y_t][b_x_t][b_y_t] = k;
				path.push_back(dir[i]);
				bt(k+1,r_x_t,r_y_t,b_x_t,b_y_t,path);
				path.pop_back();
			}
		}
	}
}

int main()
{
	int r_x,r_y,b_x,b_y;
	scanf("%d %d",&n,&m);
	fill(&visited[0][0][0][0],&visited[10][10][10][11],11);
	for(int i=0;i<n;i++)
	{
		scanf("\n");
		for(int j=0;j<m;j++)
		{
			scanf("%1c",&arr[i][j]);
			if(arr[i][j] == 'R')
			{
				r_x = i;
				r_y = j;
				arr[i][j] = '.';
			}
			if(arr[i][j] == 'B')
			{
				b_x = i;
				b_y = j;
				arr[i][j] = '.';
			}
		}
	}
	visited[r_x][r_y][b_x][b_y] = true;
	string path;
	bt(1,r_x,r_y,b_x,b_y,path);
	printf("%d\n",result);
	if(result!=-1)
	{
		for(int i=0;i<result_path.length();i++)
		{
			printf("%c",result_path[i]);
		}
	}
}
/*
그래프 시뮬레이션
*/ 
