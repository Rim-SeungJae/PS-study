#include<cstdio>
#include<algorithm>

class Smell{
	public:
		int t;
		int n;
		Smell()
		{
			t=0;
			n=0;
		}
};

int N,M,K,arr[22][22],shark_d[440],priority[440][4][4];
Smell smell[22][22];
const int dir_r[4] = {-1,1,0,0}, dir_c[4] = {0,0,-1,1};
bool inRange(int a)
{
	if(a>=0 && a<N) return true;
	else return false;
}

int main()
{
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
			smell[i][j].n = arr[i][j];
			smell[i][j].t = 0;
		}
	}
	for(int i=1;i<=M;i++)
	{
		scanf("%d",&shark_d[i]);
		shark_d[i]--;
	}
	for(int i=1;i<=M;i++)
	{
		for(int j=0;j<4;j++)
		{
			scanf("%d %d %d %d",&priority[i][j][0],&priority[i][j][1],&priority[i][j][2],&priority[i][j][3]);
			priority[i][j][0]--;
			priority[i][j][1]--;
			priority[i][j][2]--;
			priority[i][j][3]--;
		}
	}
	for(int t=1;t<=1000;t++)
	{
		int new_arr[22][22]={0,};
		Smell new_smell[22][22];
		std::copy(&smell[0][0],&smell[21][22],&new_smell[0][0]);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(arr[i][j]==0) continue;
				int shark = arr[i][j];
				for(int k=0;k<4;k++)
				{
					int d = shark_d[shark];
					int priority_d = priority[shark][d][k];
					int r = i+dir_r[priority_d], c = j+dir_c[priority_d];
					if(inRange(r) && inRange(c) && (smell[r][c].n == 0 || t - smell[r][c].t > K))
					{
						arr[i][j] = 0;
						if(new_arr[r][c]==0 || new_arr[r][c]>shark)
						{
							new_arr[r][c] = shark;
							shark_d[shark] = priority_d;
							new_smell[r][c].n = shark;
							new_smell[r][c].t = t;
						}
						break;
					}
				}
				if(arr[i][j]==0) continue;
				for(int k=0;k<4;k++)
				{
					int d = shark_d[shark];
					int priority_d = priority[shark][d][k];
					int r = i+dir_r[priority_d], c = j+dir_c[priority_d];
					if(inRange(r) && inRange(c) && smell[r][c].n == shark && t - smell[r][c].t <= K)
					{
						if(new_arr[r][c]==0 || new_arr[r][c]>shark)
						{
							new_arr[r][c] = shark;
							shark_d[shark] = priority_d;
							new_smell[r][c].n = shark;
							new_smell[r][c].t = t;
						}
						break;
					}
				}
			}
		}
		std::copy(&new_arr[0][0],&new_arr[21][22],&arr[0][0]);
		std::copy(&new_smell[0][0],&new_smell[21][22],&smell[0][0]);
		bool flag = true;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				//printf("%d(%d) ",arr[i][j],smell[i][j].n);
				if(arr[i][j]>1) flag = false;
			}
			//printf("\n");
		}
		//printf("\n");
		if(flag)
		{
			printf("%d",t);
			return 0;
		}
	}
	printf("-1");
}
/*
구현, 시뮬레이션
*/ 
