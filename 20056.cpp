#include<cstdio>
#include<vector>

using namespace std;

typedef struct{
	int r;
	int c;
	int m;
	int s;
	int d;
}Fireball;

int n,k,m;
const int dirr[8] = {-1,-1,0,1,1,1,0,-1}, dirc[8] = {0,1,1,1,0,-1,-1,-1};
vector<Fireball> arr;

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		int r,c,m,s,d;
		scanf("%d %d %d %d %d",&r,&c,&m,&s,&d);
		Fireball f;
		f.r = r;
		f.c = c;
		f.m = m;
		f.s = s;
		f.d = d;
		arr.push_back(f);
	}
	for(int i=0;i<k;i++)
	{
		int colide_check[55][55] = {0,};
		vector<pair<int,int>> colide;
		for(int j=0;j<arr.size();j++)
		{
			int d = arr[j].d;
			arr[j].r = (n + arr[j].r + dirr[d] * arr[j].s)%n;
			arr[j].c = (n + arr[j].c + dirc[d] * arr[j].s)%n;
			colide_check[arr[j].r][arr[j].c] += 1;
			if(colide_check[arr[j].r][arr[j].c] == 2) colide.push_back(make_pair(arr[j].r,arr[j].c));
		}
		for(int j=0;j<colide.size();j++)
		{
			int col_r = colide[j].first, col_c = colide[j].second,m_sum = 0,s_sum = 0,cnt = 0;
			for(int k=0;k<arr.size();k++)
			{
				if(arr[k].r == col_r && arr[k].c == col_c)
			}
		}
	}
}
