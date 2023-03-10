#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int r,c,k,A[110][110];

bool comp(pair<int,int> a,pair<int,int> b)
{
	if(a.second > b.second) return false;
	else if(a.second == b.second)
	{
		if(a.first > b.first) return false;
		else return true;
	}
	else return true;
}

int main()
{
	scanf("%d %d %d",&r,&c,&k);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	int row = 3, col = 3;
	for(int t=0;t<100;t++)
	{
		if(A[r-1][c-1] == k)
		{
			printf("%d",t);
			return 0;
		}
		if(row>=col)
		{
			for(int i=0;i<row;i++)
			{
				int cnt[110] = {0,};
				vector<pair<int,int>> v;
				for(int j=0;j<col;j++)
				{
					cnt[A[i][j]]++;
					A[i][j] = 0;
				}
				for(int j=1;j<=100;j++)
				{
					if(cnt[j] != 0) v.push_back(make_pair(j,cnt[j]));
				}
				sort(v.begin(),v.end(),comp);
				for(int j=0;j<v.size();j++)
				{
					A[i][j*2] = v[j].first;
					A[i][j*2+1] = v[j].second;
				}
				if(col<v.size()*2) col = v.size()*2;
			}
			/*
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					printf("%d ",A[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			*/
		}
		else
		{
			for(int i=0;i<col;i++)
			{
				int cnt[110] = {0,};
				vector<pair<int,int>> v;
				for(int j=0;j<row;j++)
				{
					cnt[A[j][i]]++;
					A[j][i] = 0;
				}
				for(int j=1;j<=100;j++)
				{
					if(cnt[j] != 0) v.push_back(make_pair(j,cnt[j]));
				}
				sort(v.begin(),v.end(),comp);
				for(int j=0;j<v.size();j++)
				{
					A[j*2][i] = v[j].first;
					A[j*2+1][i] = v[j].second;
				}
				if(row<v.size()*2) row = v.size()*2;
			}
			/*
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					printf("%d ",A[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			*/
		}
	}
	printf("-1");
	return 0;
}
/*
구현,시뮬레이션
*/ 
