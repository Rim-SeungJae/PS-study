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

int N,K,M;
const int dirr[8] = {-1,-1,0,1,1,1,0,-1}, dirc[8] = {0,1,1,1,0,-1,-1,-1};

int main()
{
	vector<Fireball> arr;
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<M;i++)
	{
		int r,c,m,s,d;
		scanf("%d %d %d %d %d",&r,&c,&m,&s,&d);
		arr.push_back(Fireball(r,c,m,s,d));
	}
	for(int i=0;i<K;i++)
	{
		int colide_check[55][55] = {0,};
		vector<pair<int,int>> colide;
		for(int j=0;j<arr.size();j++)
		{
			int d = arr[j].d;
			arr[j].r = ((arr[j].r + dirr[d] * arr[j].s)%N+N)%N;
			arr[j].c = ((arr[j].c + dirc[d] * arr[j].s)%N+N)%N;
			colide_check[arr[j].r][arr[j].c] += 1;
			if(colide_check[arr[j].r][arr[j].c] == 2) colide.push_back(make_pair(arr[j].r,arr[j].c));
		}
		for(int j=0;j<colide.size();j++)
		{
			int col_r = colide[j].first, col_c = colide[j].second,m_sum = 0,s_sum = 0,cnt = 0;
			bool odd_flag = true, even_flag = true;
			vector<int> target_idx;
			for(int k=0;k<arr.size();k++)
			{
				if(arr[k].r == col_r && arr[k].c == col_c)
				{
					m_sum += arr[k].m;
					s_sum += arr[k].s;
					cnt++;
					if(arr[k].d%2==0) odd_flag = false;
					else even_flag = false;
					arr.erase(arr.begin()+k);
					k--;
				}
			}
			if(m_sum/5 != 0)
			{
				if(odd_flag || even_flag)
				{
					arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,0));
					arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,2));
					arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,4));
					arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,6));
				}
				else{
					arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,1));
					arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,3));
					arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,5));
					arr.push_back(Fireball(col_r,col_c,m_sum/5,s_sum/cnt,7));
				}
			}
		}
	}
	int result=0;
	for(int i=0;i<arr.size();i++)
	{
		result += arr[i].m;
	}
	printf("%d",result);
}
/*
굉장히 복잡한 구현문제
이 문제에서 알게 된 점은 c++는 파이썬과 다르게
데이터를 기준으로 반복문을 도는 도중에 데이터의 요소를 삭제할 수 있다는 점이다
(66-67 행 참조) 
*/ 
