#include<cstdio>
#include<vector>
#include<deque>

using namespace std;

bool row[9][10],col[9][10],sec[9][10],is_found;
int arr[9][9];
deque<pair<int,int>> q;

void bt()
{
	if(is_found) return;
	if(q.empty())
	{
		is_found = true;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		return;
	}
	int x = q.back().first;
	int y = q.back().second;
	for(int i=1;i<=9;i++)
	{
		if(!row[x][i] && !col[y][i] && !sec[x/3 * 3 + y/3][i])
		{
			row[x][i] = true;
			col[y][i] = true;
			sec[x/3 * 3 + y/3][i] = true;
			arr[x][y] = i;
			q.pop_back();
			bt();
			q.push_back(make_pair(x,y));
			if(is_found) return;
			row[x][i] = false;
			col[y][i] = false;
			sec[x/3 * 3 + y/3][i] = false;
			arr[x][y] = 0;
		}
	}
}

int main()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j] == 0) q.push_back(make_pair(i,j));
			else
			{
				row[i][arr[i][j]] = true;
				col[j][arr[i][j]] = true;
				sec[i/3 * 3 + j/3][arr[i][j]] = true;
			}
		}
	}
	bt();
}
/*
백트래킹
0으로 남는 값이 없도록 주의하여 코드를 작성하자
*/ 
