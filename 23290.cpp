#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int dirr[8]={0,-1,-1,-1,0,1,1,1},dirc[8]={-1,-1,0,1,1,1,0,-1};
const int s_dirr[4] = {-1,0,1,0}, s_dirc[4]={0,-1,0,1};

class Fish{
	public:
		int r;
		int c;
		int d;
		Fish(int r,int c,int d)
		{
			this->r = r;
			this->c = c;
			this->d = d;
		}
		Fish()
		{
		}
};

int m,s,shark_r,shark_c,smell[5][5];
vector<int> arr[5][5],arr_copy[5][5];

bool inRange(int a)
{
	return a>0 && a<=4;
}

int main()
{
	scanf("%d %d",&m,&s);
	for(int i=0;i<m;i++)
	{
		int fx,fy,d;
		scanf("%d %d %d",&fx,&fy,&d);
		arr[fx][fy].push_back(d-1);
	}
	scanf("%d %d",&shark_r,&shark_c);
	fill(&smell[0][0],&smell[4][5],-999);
	for(int t=0;t<s;t++)
	{
		// 1
		copy(&arr[0][0],&arr[4][5],&arr_copy[0][0]);

		// 2
		vector<int> new_arr[5][5];
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				for(int k=0;k<arr[i][j].size();k++)
				{
					int d = arr[i][j][k];
					int cnt=0;
					bool stuck_flag=false;
					while(!inRange(i + dirr[d]) || !inRange(j + dirc[d]) || t - smell[i + dirr[d]][j + dirc[d]]<=2 || (shark_r == i + dirr[d] && shark_c == j + dirc[d]))
					{
						if(cnt>8)
						{
							stuck_flag = true;
							break;
						}
						cnt++;
						d = (d+7)%8;
					}
					if(stuck_flag)
					{
						new_arr[i][j].push_back( arr[i][j][k]);
						continue;
					}
					new_arr[i+dirr[d]][j+dirc[d]].push_back(d);
				}
			}
		}
		copy(&new_arr[0][0],&new_arr[4][5],&arr[0][0]);

		// 3
		int max_i = -1, max_j = -1,max_k = -1,max_sum = -1;
		bool visited[5][5] = {0,};
		for(int i=0;i<4;i++)
		{
			int r = shark_r;
			int c = shark_c;
			bool i_flag= false;
			int sum = 0;
			if(!inRange(r + s_dirr[i]) || !inRange(c + s_dirc[i])) continue;
			if(!visited[r + s_dirr[i]][c + s_dirc[i]])
			{
				sum+=arr[r + s_dirr[i]][c + s_dirc[i]].size();
				visited[r + s_dirr[i]][c + s_dirc[i]] = true;
				i_flag = true;
			}
			for(int j=0;j<4;j++)
			{
				bool j_flag = false;
				if(!inRange(r + s_dirr[i] + s_dirr[j]) || !inRange(c + s_dirc[i] + s_dirc[j])) continue;
				if(!visited[r + s_dirr[i] + s_dirr[j]][c + s_dirc[i] + s_dirc[j]])
				{
					sum+=arr[r + s_dirr[i] + s_dirr[j]][c + s_dirc[i] + s_dirc[j]].size();
					visited[r + s_dirr[i] + s_dirr[j]][c + s_dirc[i] + s_dirc[j]] = true;
					j_flag = true;
				}
				for(int k=0;k<4;k++)
				{
					bool k_flag = false;
					if(!inRange(r + s_dirr[i] + s_dirr[j] + s_dirr[k]) || !inRange(c + s_dirc[i] + s_dirc[j] + s_dirc[k])) continue;
					if(!visited[r + s_dirr[i] + s_dirr[j] + s_dirr[k]][c + s_dirc[i] + s_dirc[j] + s_dirc[k]])
					{
						sum+=arr[r + s_dirr[i] + s_dirr[j] + s_dirr[k]][c + s_dirc[i] + s_dirc[j] + s_dirc[k]].size();
						visited[r + s_dirr[i] + s_dirr[j] + s_dirr[k]][c + s_dirc[i] + s_dirc[j] + s_dirc[k]] = true;
						k_flag = true;
					}
					if(sum>max_sum)
					{
						max_sum = sum;
						max_i = i;
						max_j = j;
						max_k = k;
					}
					if(k_flag)
					{
						sum-=arr[r + s_dirr[i] + s_dirr[j] + s_dirr[k]][c + s_dirc[i] + s_dirc[j] + s_dirc[k]].size();
						visited[r + s_dirr[i] + s_dirr[j] + s_dirr[k]][c + s_dirc[i] + s_dirc[j] + s_dirc[k]] = false;
					}
				}
				if(j_flag)
				{
					sum-=arr[r + s_dirr[i] + s_dirr[j]][c + s_dirc[i] + s_dirc[j]].size();
					visited[r + s_dirr[i] + s_dirr[j]][c + s_dirc[i] + s_dirc[j]] = false;
				}
			}
			if(i_flag)
			{
				sum-=arr[r + s_dirr[i]][c + s_dirc[i]].size();
				visited[r + s_dirr[i]][c + s_dirc[i]] = false;
			}
		}
		shark_r += s_dirr[max_i];
		shark_c += s_dirc[max_i];
		if(!arr[shark_r][shark_c].empty())
		{
			arr[shark_r][shark_c].clear();
			smell[shark_r][shark_c] = t;
		}
		shark_r += s_dirr[max_j];
		shark_c += s_dirc[max_j];
		if(!arr[shark_r][shark_c].empty())
		{
			arr[shark_r][shark_c].clear();
			smell[shark_r][shark_c] = t;
		}
		shark_r += s_dirr[max_k];
		shark_c += s_dirc[max_k];
		if(!arr[shark_r][shark_c].empty())
		{
			arr[shark_r][shark_c].clear();
			smell[shark_r][shark_c] = t;
		}

		// 5
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=4;j++)
			{
				arr[i][j].insert(arr[i][j].end(),arr_copy[i][j].begin(),arr_copy[i][j].end());
			}
		}

	}
	long long int result = 0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			result += arr[i][j].size();
		}
	}
	printf("%lld",result);
}
