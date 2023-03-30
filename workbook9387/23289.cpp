#include<cstdio>
#include<vector>

using namespace std;
using ii = pair<int,int>;

vector<ii> check,warmer;
const int dirr[4] = {0,0,-1,1},dirc[4]={1,-1,0,0};
int R,C,K,W,arr[22][22],temp[22][22];
bool wall[2][22][22];

void blow()
{
	for(int i=0;i<warmer.size();i++)
	{
		bool visited[22][22] = {0,};
		int r,c,d;
		r = warmer[i].first;
		c = warmer[i].second;
		d = arr[r][c] - 1;
		int d_vert0 = ((d/2)+1)%2,d_vert1 = ((d/2)+1)%2+1;
		r = r+dirr[d];
		c = c+dirr[d];
		temp[r][c] = 5;
		visited[r][c] = true;
		for(int i=0;i<4;i++)
		{
			if(visited[r][c])
			{
				int nr,nc;
				nr = r+dirr[d];
				nc = c+dirc[d];
				printf("%d,%d ",nr,nc);
				if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)])
				{
					visited[nr][nc] = true;
					temp[nr][nc] = temp[r][c] - 1;
				}
				nr = r+dirr[d]+dirr[d_vert0];
				nc = c+dirc[d]+dirc[d_vert0];
				printf("%d,%d ",nr,nc);
				if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert0]+(d==3)][c+dirc[d_vert0]-(d==1)]  && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)])
				{
					visited[nr][nc] = true;
					temp[nr][nc] = temp[r][c] - 1;
				}
				nr = r+dirr[d]+dirr[d_vert1];
				nc = c+dirc[d]+dirc[d_vert1];
				printf("%d,%d\n",nr,nc);
				if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert1]+(d==3)][c+dirc[d_vert1]-(d==1)]  && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)])
				{
					visited[nr][nc] = true;
					temp[nr][nc] = temp[r][c] - 1;
				}
				
			}
			for(int j=0;j<i;j++)
			{
				int tmpr = r,tmpc = c;
				r = tmpr + dirr[d_vert0]*j;
				c = tmpc + dirc[d_vert0]*j;
				if(visited[r][c])
				{
					int nr,nc;
					int d_vert0 = ((d/2)+1)%2,d_vert1 = ((d/2)+1)%2+1;
					nr = r+dirr[d];
					nc = c+dirc[d];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)])
					{
						visited[nr][nc] = true;
						temp[nr][nc] = temp[r][c] - 1;
					}
					nr = r+dirr[d]+dirr[d_vert0];
					nr = c+dirc[d]+dirc[d_vert0];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert0]+(d==3)][c+dirc[d_vert0]-(d==1)]  && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)])
					{
						visited[nr][nc] = true;
						temp[nr][nc] = temp[r][c] - 1;
					}
					nr = r+dirr[d]+dirr[d_vert1];
					nr = c+dirc[d]+dirc[d_vert1];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert1]+(d==3)][c+dirc[d_vert1]-(d==1)]  && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)])
					{
						visited[nr][nc] = true;
						temp[nr][nc] = temp[r][c] - 1;
					}
				}
				r = tmpr + dirr[d_vert1]*j;
				c = tmpc + dirc[d_vert1]*j;
				if(visited[r][c])
				{
					int nr,nc;
					int d_vert0 = ((d/2)+1)%2,d_vert1 = ((d/2)+1)%2+1;
					nr = r+dirr[d];
					nc = c+dirc[d];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)])
					{
						visited[nr][nc] = true;
						temp[nr][nc] = temp[r][c] - 1;
					}
					nr = r+dirr[d]+dirr[d_vert0];
					nr = c+dirc[d]+dirc[d_vert0];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert0]+(d==3)][c+dirc[d_vert0]-(d==1)]  && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)])
					{
						visited[nr][nc] = true;
						temp[nr][nc] = temp[r][c] - 1;
					}
					nr = r+dirr[d]+dirr[d_vert1];
					nr = c+dirc[d]+dirc[d_vert1];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert1]+(d==3)][c+dirc[d_vert1]-(d==1)]  && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)])
					{
						visited[nr][nc] = true;
						temp[nr][nc] = temp[r][c] - 1;
					}
				}
				r = tmpr;
				c = tmpc;
			}
		}
		/*
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				printf("%d ",visited[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
	}
}

int main()
{
	scanf("%d %d %d",&R,&C,&K);
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==5)check.push_back(make_pair(i,j));
			else if(arr[i][j]>0) warmer.push_back(make_pair(i,j));
		}
	}
	scanf("%d",&W);
	for(int i=0;i<W;i++)
	{
		int x,y,t;
		scanf("%d %d %d",&x,&y,&t);
		wall[t][x-1][y-1] = 1;
	}
	blow();
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			printf("%d ",temp[i][j]);
		}
		printf("\n");
	}
}
