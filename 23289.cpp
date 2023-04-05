#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
using ii = pair<int,int>;

vector<ii> check,warmer;
const int dirr[4] = {0,0,-1,1},dirc[4]={1,-1,0,0};
int R,C,K,W,arr[22][22],temp[22][22];
bool wall[2][44][44];

void blow()
{
	for(int i=0;i<warmer.size();i++) // i<warmer,size()
	{
		bool visited[22][22] = {0,};
		int r,c,d;
		r = warmer[i].first;
		c = warmer[i].second;
		d = arr[r][c] - 1;
		int d_vert0 = ((d/2)+1)%2*2,d_vert1 = ((d/2)+1)%2*2+1;
		if(!wall[((d/2)+1)%2][r+(d==3)][c-(d==1)])
		{
			r = r+dirr[d];
			c = c+dirc[d];
			temp[r][c] += 5;
			visited[r][c] = true;
		}
		else continue;
		for(int i=0;i<4;i++)
		{
			if(visited[r][c])
			{
				int nr,nc;
				nr = r+dirr[d];
				nc = c+dirc[d];
				if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)]&& !visited[nr][nc])
				{
					visited[nr][nc] = true;
					temp[nr][nc] += 4-i;
				}
				nr = r+dirr[d]+dirr[d_vert0];
				nc = c+dirc[d]+dirc[d_vert0];
				if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert0]+(d==3)][c+dirc[d_vert0]-(d==1)]  && !wall[d/2][r+(d_vert0==3)][c-(d_vert0==1)]&& !visited[nr][nc])
				{
					visited[nr][nc] = true;
					temp[nr][nc] += 4-i;
				}
				nr = r+dirr[d]+dirr[d_vert1];
				nc = c+dirc[d]+dirc[d_vert1];
				if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert1]+(d==3)][c+dirc[d_vert1]-(d==1)]  && !wall[d/2][r+(d_vert1==3)][c-(d_vert1==1)]&& !visited[nr][nc])
				{
					visited[nr][nc] = true;
					temp[nr][nc] += 4-i;
				}
				/*
				for(int i=0;i<R;i++)
				{
					for(int j=0;j<C;j++)
					{
						printf("%d ",temp[i][j]);
					}
					printf("\n");
				}
				printf("\n");
				*/
			}
			for(int j=0;j<i;j++)
			{
				int tmpr = r,tmpc = c;
				r = tmpr + dirr[d_vert0]*(j+1);
				c = tmpc + dirc[d_vert0]*(j+1);
				if(visited[r][c])
				{
					int nr,nc;
					nr = r+dirr[d];
					nc = c+dirc[d];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)] && !visited[nr][nc])
					{
						visited[nr][nc] = true;
						temp[nr][nc] += 4-i;
					}
					nr = r+dirr[d]+dirr[d_vert0];
					nc = c+dirc[d]+dirc[d_vert0];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert0]+(d==3)][c+dirc[d_vert0]-(d==1)]  && !wall[d/2][r+(d_vert0==3)][c-(d_vert0==1)]&& !visited[nr][nc])
					{
						visited[nr][nc] = true;
						temp[nr][nc] += 4-i;
					}
					nr = r+dirr[d]+dirr[d_vert1];
					nc = c+dirc[d]+dirc[d_vert1];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert1]+(d==3)][c+dirc[d_vert1]-(d==1)]  && !wall[d/2][r+(d_vert1==3)][c-(d_vert1==1)]&& !visited[nr][nc])
					{
						visited[nr][nc] = true;
						temp[nr][nc] += 4-i;
					}
				}
				r = tmpr + dirr[d_vert1]*(j+1);
				c = tmpc + dirc[d_vert1]*(j+1);
				if(visited[r][c])
				{
					int nr,nc;
					nr = r+dirr[d];
					nc = c+dirc[d];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+(d==3)][c-(d==1)]&& !visited[nr][nc])
					{
						visited[nr][nc] = true;
						temp[nr][nc] += 4-i;
					}
					nr = r+dirr[d]+dirr[d_vert0];
					nc = c+dirc[d]+dirc[d_vert0];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert0]+(d==3)][c+dirc[d_vert0]-(d==1)]  && !wall[d/2][r+(d_vert0==3)][c-(d_vert0==1)]&& !visited[nr][nc])
					{
						visited[nr][nc] = true;
						temp[nr][nc] += 4-i;
					}
					nr = r+dirr[d]+dirr[d_vert1];
					nc = c+dirc[d]+dirc[d_vert1];
					if(nr>=0 && nr<R && nc>=0 && nc<C && !wall[((d/2)+1)%2][r+dirr[d_vert1]+(d==3)][c+dirc[d_vert1]-(d==1)]  && !wall[d/2][r+(d_vert1==3)][c-(d_vert1==1)]&& !visited[nr][nc])
					{
						visited[nr][nc] = true;
						temp[nr][nc] += 4-i;
					}
				}
				r = tmpr;
				c = tmpc;
			}
			r = r+dirr[d];
			c = c+dirc[d];
		}
		/*
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if(wall[0][i][j]) printf("---");
				else printf("   ");
			}
			printf("\n");
			for(int j=0;j<C;j++)
			{
				printf("%2d",temp[i][j]);
				if(wall[1][i][j]) printf("|");
				else printf(" ");
			}
			printf("\n");
			
		}
		printf("\n");
		*/
	
	}
}

void trans()
{
	int new_temp[22][22];
	copy(&temp[0][0],&temp[21][22],&new_temp[0][0]);
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(i+1<R && temp[i][j]<temp[i+1][j] && !wall[0][i+1][j])
			{
				new_temp[i][j] += (temp[i+1][j] - temp[i][j])/4;
				new_temp[i+1][j] -= (temp[i+1][j] - temp[i][j])/4;
			}
			if(i+1<R && temp[i][j]>temp[i+1][j] && !wall[0][i+1][j])
			{
				new_temp[i+1][j] += (temp[i][j] - temp[i+1][j])/4;
				new_temp[i][j] -= (temp[i][j] - temp[i+1][j])/4;
			}
			if(j+1<C && temp[i][j]<temp[i][j+1] && !wall[1][i][j])
			{
				new_temp[i][j] += (temp[i][j+1] - temp[i][j])/4;
				new_temp[i][j+1] -= (temp[i][j+1] - temp[i][j])/4;
			}
			if(j+1<C && temp[i][j]>temp[i][j+1] && !wall[1][i][j])
			{
				new_temp[i][j+1] += (temp[i][j] - temp[i][j+1])/4;
				new_temp[i][j] -= (temp[i][j] - temp[i][j+1])/4;
			}
		}
	}
	copy(&new_temp[0][0],&new_temp[21][22],&temp[0][0]);
}

void dec()
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(i == 0 || i == R-1 || j == 0 || j == C-1)
			{
				if(temp[i][j])temp[i][j] -= 1;
			}
		}
	}
}

bool tempCheck()
{
	for(int i=0;i<check.size();i++)
	{
		int r,c;
		r = check[i].first;
		c = check[i].second;
		if(temp[r][c] < K) return false;
	}
	return true;
}

int main()
{
	int chocolate = 0;
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
	while(chocolate<101){
		blow();
		/*
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				printf("%d ",temp[i][j]);
			}
			printf("\n");
		}
		*/
		trans();
		dec();
		chocolate++;
		if(tempCheck()) break;
	}
	/*
	for(int i=0;i<22;i++)
	{
		for(int j=0;j<22;j++)
		{
			printf("%d ",temp[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d",chocolate);
}
