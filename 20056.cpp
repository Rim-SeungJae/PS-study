#include<cstdio>
#include<vector>

using namespace std;

class Fireball{
	public:
		int r=0;
		int c=0;
		int m=0;
		int s=0;
		int d=0;
		Fireball(int r,int c,int m,int s,int d)
		{
			this->r = r;
			this->c = c;
			this->m = m;
			this->s = s;
			this->d = d;
		}
		Fireball()
		{
			r=c=m=s=d=0;
		}
};

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

		arr.push_back(Fireball(r,c,m,s,d));
	}
	for(int i=0;i<k;i++)
	{
		bool colide_check[55][55] = {0,};
		vector<pair<int,int>> colide;
		for(int j=0;j<arr.size();j++)
		{
			int d = arr[j].d;
			arr[j].r = (n + arr[j].r + dirr[d] * arr[j].s)%n;
			arr[j].c = (n + arr[j].c + dirc[d] * arr[j].s)%n;
			colide_check[arr[j].r][arr[j].c]  = true;
			if(colide_check[arr[j].r][arr[j].c]) colide.push_back(make_pair(arr[j].r,arr[j].c));
		}
		for(int j=0;j<colide.size();j++)
		{
			int col_r = colide[j].first, col_c = colide[j].second,m_sum = 0,s_sum = 0,cnt = 0;
			vector<Fireball> new_arr;
			bool odd_flag = true, even_flag = true;
			for(int k=0;k<arr.size();k++)
			{
				if(arr[k].r == col_r && arr[k].c == col_c)
				{
					m_sum += arr[k].m;
					s_sum += arr[k].s;
					cnt++;
					if(arr[k].d%2==0) odd_flag = false;
					else even_flag = false;
				}
				else{
					new_arr.push_back(arr[k]);
				}
			}
			if(m_sum/5 != 0)
			{
				if(odd_flag || even_flag)
				{
					new_arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,0));
					new_arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,2));
					new_arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,4));
					new_arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,6));
				}
				else{
					new_arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,1));
					new_arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,3));
					new_arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,5));
					new_arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,7));
				}
			}
			arr = new_arr;
		}
	}
	int result=0;
	for(int i=0;i<arr.size();i++)
	{
		printf("%d\n",arr[i].m);
		result+=m;
	}
	printf("%d",result);
}
