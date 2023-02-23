#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,arr[10][10],min_area = 100000;
int dirx[4] = {-1,0,1,0}, diry[4] = {0,1,0,-1};
vector<pair<int,int>> cctv;
vector<vector<int>> cctv_dir;

void bt(int idx)
{
	if(idx >= cctv.size())
	{
		int tmp[10][10];
		copy(&arr[0][0],&arr[9][10],&tmp[0][0]);
		for(int i=0;i<cctv.size();i++)
		{
			for(int j=0;j<cctv_dir[i].size();j++)
			{
				int x = cctv[i].first, y = cctv[i].second;
				int dir = cctv_dir[i][j];
				x += dirx[dir];
				y += diry[dir];
				while(x >= 0 && x < n && y >= 0 && y < m && tmp[x][y] != 6)
				{
					if(tmp[x][y] == 0) tmp[x][y] = -1;
					x += dirx[dir];
					y += diry[dir];
				}
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(tmp[i][j]==0) cnt++;
			}
		}
		if(min_area > cnt) min_area = cnt;
		return;
	}
	int x = cctv[idx].first, y = cctv[idx].second;
	if(arr[x][y] == 1)
	{
		for(int i=0;i<4;i++)
		{
			cctv_dir[idx].push_back(i);
			bt(idx+1);
			cctv_dir[idx].pop_back();
		}
	}
	else if(arr[x][y] == 2)
	{
		cctv_dir[idx] = vector<int>{0,2};
		bt(idx+1);
		cctv_dir[idx] = vector<int>{1,3};
		bt(idx+1);
	}
	else if(arr[x][y] == 3)
	{
		cctv_dir[idx] = vector<int>{0,1};
		bt(idx+1);
		cctv_dir[idx] = vector<int>{1,2};
		bt(idx+1);
		cctv_dir[idx] = vector<int>{2,3};
		bt(idx+1);
		cctv_dir[idx] = vector<int>{3,0};
		bt(idx+1);
	}
	else if(arr[x][y] == 4)
	{
		cctv_dir[idx] = vector<int>{0,1,2};
		bt(idx+1);
		cctv_dir[idx] = vector<int>{1,2,3};
		bt(idx+1);
		cctv_dir[idx] = vector<int>{2,3,0};
		bt(idx+1);
		cctv_dir[idx] = vector<int>{3,0,1};
		bt(idx+1);
	}
	else if(arr[x][y] == 5)
	{
		cctv_dir[idx] = vector<int>{0,1,2,3};
		bt(idx+1);
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j] != 0 && arr[i][j] != 6)
			{
				cctv.push_back(make_pair(i,j));
			}
		}
	}
	cctv_dir.assign(cctv.size(),vector<int>());
	bt(0);
	printf("%d",min_area);
}
/*
백트래킹
*/ 
