#include<cstdio>
#include<algorithm>

int N,M,T;
int board[55][55],idx[55];
const int dir[2] = {-1,1};

int main()
{
	scanf("%d %d %d",&N,&M,&T);
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&board[i][j]);
		}
	}
	for(int t=0;t<T;t++)
	{
		// 1
		int x,d,k;
		scanf("%d %d %d",&x,&d,&k);
		for(int i=x;i<=N;i+=x)
		{
			idx[i] = (idx[i] + (dir[d] * k)%M + M)%M;
		}
		/*
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<M;j++)
			{
				int r = i,c = (j+idx[r])%M;
				printf("%d ",board[r][c]);
			}
			printf("\n");
		}
		*/
		// 2
		int new_board[55][55]={0,},sum = 0,cnt=0;
		bool noAdj = true;
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<M;j++)
			{
				int r = i,c = (j+idx[r])%M;
				new_board[r][c] = board[r][c];
				if(board[r][c] == 0) continue;
				if(board[r][c]>0)
				{
					sum+=board[r][c];
					cnt++;
				}
				if(board[r][c] == board[r][(c+M-1)%M])
				{
					new_board[r][c] = 0;
					noAdj = false;
				}
				else if(board[r][c] == board[r][(c+1)%M])
				{
					new_board[r][c] = 0;
					noAdj = false;
				}
				else if(r-1>0 && board[r][c] == board[r-1][(j+idx[r-1])%M])
				{
					new_board[r][c] = 0;
					noAdj = false;
				}
				else if(r+1<=N && board[r][c] == board[r+1][(j+idx[r+1])%M])
				{
					new_board[r][c] = 0;
					noAdj = false;
				}
			}
		}
		double avg = (double)sum/cnt;
		if(noAdj)
		{
			for(int i=1;i<=N;i++)
			{
				for(int j=0;j<M;j++)
				{
					if(board[i][j]>0)
					{
						if(board[i][j]>avg) new_board[i][j] = board[i][j]-1;
						else if(board[i][j]<avg) new_board[i][j] = board[i][j]+1;
					}
				}
			}
		}
		std::copy(&new_board[0][0],&new_board[54][55],&board[0][0]);
		/*
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<M;j++)
			{
				int r = i,c = (j+idx[r])%M;
				printf("%d ",board[r][c]);
			}
			printf("\n");
		}
		printf("---------------");
		printf("\n");
		*/
	}
	int result = 0;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<M;j++)
		{
			result+=board[i][j];
		}
	}
	printf("%d",result);
}
/*
구현, 시뮬레이션
*/ 
