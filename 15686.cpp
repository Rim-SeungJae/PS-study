#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int n,m,arr[55][55],min_total_dist = 100000000;
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;
bool selected[110];

bool inRange(int a)
{
	if(a>=0 && a<n) return true;
	return false;
}
//////////////////////////////
int Dist(int r,int c)
{
	int min_dist = 100000000;
	for(int i=0;i<chicken.size();i++)
	{
		if(!selected[i]) continue;
		int dist = abs(chicken[i].first - r) + abs(chicken[i].second - c);
		if(dist<min_dist) min_dist = dist;
	}
	return min_dist;
}
/////////////////////////////
void bt(int prev,int depth)
{
	if(depth == m)
	{
		int total_dist = 0;
		for(int i=0;i<chicken.size();i++)
		{
			if(!selected[i])arr[chicken[i].first][chicken[i].second] = 0;
		}
		for(int i=0;i<house.size();i++)
		{
			int x = house[i].first;
			int y = house[i].second;
			total_dist += Dist(x,y);;
		}
		if(total_dist < min_total_dist)
		{
			min_total_dist = total_dist;
		}
		for(int i=0;i<chicken.size();i++)
		{
			if(!selected[i])arr[chicken[i].first][chicken[i].second] = 2;
		}
		return;
	}
	for(int i=prev+1;i<chicken.size();i++)
	{
		selected[i] = true;
		bt(i,depth+1);
		selected[i] = false;
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
			if(arr[i][j] == 1) house.push_back(make_pair(i,j));
			if(arr[i][j] == 2) chicken.push_back(make_pair(i,j));
		}
	}
	bt(-1,0);
	printf("%d",min_total_dist);
} 
/*
거리를 dfs로 구현하면 메모리 초과가 난다
*/ 
