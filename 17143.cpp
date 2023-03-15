#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int dirr[4] = {-1,1,0,0}, dirc[4] = {0,0,1,-1};

int R,C,M,total;
int arr[110][110];

class Shark{
	public:
		int r,c,s,d,z;
		bool eaten;
		Shark(int r,int c,int s,int d,int z)
		{
			this -> r = r;
			this -> c = c;
			this -> s = s;
			this -> d = d;
			this -> z = z;
			eaten = false;
		}
};

vector<Shark> sharks;

bool inR(int a)
{
	if(a>=0 && a<R) return true;
	else return false;
}
bool inC(int a)
{
	if(a>=0 && a<C) return true;
	else return false;
}

int main()
{
	scanf("%d %d %d",&R,&C,&M);
	sharks.push_back(Shark(0,0,0,0,0));
	sharks[0].eaten = true;
	for(int i=0;i<M;i++)
	{
		int r,c,s,d,z;
		scanf("%d %d %d %d %d",&r,&c,&s,&d,&z);
		arr[r-1][c-1] = sharks.size();
		sharks.push_back(Shark(r-1,c-1,s,d-1,z));
	}
	for(int i=0;i<C;i++)
	{
		/*
		
		for(int j=0;j<R;j++)
		{
			for(int k=0;k<C;k++)
			{
				printf("%d ",sharks[arr[j][k]].z);
			}
			printf("\n");
		}
		printf("\n");
		*/
		
		// 1 & 2
		for(int j=0;j<R;j++)
		{
			if(arr[j][i]!=0)
			{
				total += sharks[arr[j][i]].z;
				sharks[arr[j][i]].eaten = true;
				arr[j][i] = 0;
				break;
			}
		}
		
		// 3
		int new_arr[110][110]={0,};
		for(int j=1;j<sharks.size();j++)
		{
			if(sharks[j].eaten) continue;
			int src_r = sharks[j].r, src_c = sharks[j].c;
			sharks[j].r += (dirr[sharks[j].d] * sharks[j].s);
			while(true)
			{
				if(sharks[j].r < 0)
				{
					sharks[j].r = -sharks[j].r;
					sharks[j].d  = (sharks[j].d/2)*2 + (sharks[j].d+1)%2;
					continue;
				}
				if(sharks[j].r >= R)
				{
					sharks[j].r = (R - (sharks[j].r - R) - 2);
					sharks[j].d  = (sharks[j].d/2)*2 + (sharks[j].d+1)%2;
					continue;
				}
				break;
			}
			sharks[j].c += (dirc[sharks[j].d] * sharks[j].s);
			while(true)
			{
				if(sharks[j].c < 0)
				{
					sharks[j].c = -sharks[j].c;
					sharks[j].d  = (sharks[j].d/2)*2 + (sharks[j].d+1)%2;
					continue;
				}
				if(sharks[j].c >= C)
				{
					sharks[j].c = (C - (sharks[j].c - C) - 2);
					sharks[j].d  = (sharks[j].d/2)*2 + (sharks[j].d+1)%2;
					continue;
				}
				break;
			}
			int dst_r = sharks[j].r, dst_c = sharks[j].c;
			//if(!inR(src_r)) return 0;
			if(new_arr[dst_r][dst_c] == 0)
			{
				new_arr[dst_r][dst_c] = arr[src_r][src_c];
			}
			else
			{
				if(sharks[new_arr[dst_r][dst_c]].z < sharks[arr[src_r][src_c]].z)
				{
					sharks[new_arr[dst_r][dst_c]].eaten = true;
					new_arr[dst_r][dst_c] = arr[src_r][src_c];
				}
				else{
					sharks[arr[src_r][src_c]].eaten = true;
				}
			}
			//printf("%d %d -> %d %d\n",src_r,src_c,dst_r,dst_c);
		}
		copy(&new_arr[0][0],&new_arr[109][110],&arr[0][0]);
		
	}
	printf("%d",total);
}
/*
구현, 시뮬레이션 
괜히 시간초과 걱정하다가 오래걸린 문제
*/ 
