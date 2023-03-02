#include<cstdio>
#include<vector>

using namespace std;

class Fireball{
	public:
		int m=0;
		int s=0;
		int d=0;
};

int n,k,m;
const int dirr[8] = {-1,-1,0,1,1,1,0,-1}, dirc[8] = {0,1,1,1,0,-1,-1,-1};
Fireball arr[55][55];

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		int r,c,m,s,d;
		scanf("%d %d %d %d %d",&r,&c,&m,&s,&d);
		arr[r-1][c-1].m = m;
		arr[r-1][c-1].s = s;
		arr[r-1][c-1].d = d;
	}
	for(int t=0;t<k;t++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j].m != 0)
				{
					int d = arr[i][j].d;
					int dr = (n + arr[i][j].r + dirr[d] * arr[i][j].s)%n;
					int dc = (n + arr[i][j].r + dirc[d] * arr[i][j].s)%n;
					arr[dr][dc] = arr[i][j];
					arr[i][j].m = arr[i][j].s = arr[i][j].d = 0;
				}
			}
		}
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
			int m_sum=0,s_sum=0;
			bool odd_flag = true, even_flag = true;
			for(int k=0;k<arr.size();k++)
			{
				if(arr[k].r == col_r && arr[k].c == col_c)
				{
					m_sum += arr[k].m;
					s_sum += arr[k].s;
					if(arr[k].d%2==0) odd_flag = false;
					else even_flag = false;
				}
			}
		}
	}
}
