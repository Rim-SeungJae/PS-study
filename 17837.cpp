#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int dirr[4] = {0,0,-1,1}, dirc[4] = {1,-1,0,0};

class Horse{
	public:
		int r;
		int c;
		int d;
		Horse(int r,int c,int d)
		{
			this->r = r;
			this->c = c;
			this->d = d;
		}
};

class Plate{
	public:
		int color;
		vector<int> placed;
		Plate(int c)
		{
			color = c;
		}
		Plate()
		{
		}
};

int N,K;
Plate board[20][20];
vector<Horse> list;

bool inRange(int a)
{
	if(a>=0 && a<N) return true;
	else return false;
}

int main()
{
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&board[i][j].color);
		}
	}
	for(int i=0;i<K;i++)
	{
		int r,c,d;
		scanf("%d %d %d",&r,&c,&d);
		r--;
		c--;
		d--;
		board[r][c].placed.push_back(list.size());
		list.push_back(Horse(r,c,d));
	}
	for(int t=1;t<=1000;t++)
	{
		for(int i=0;i<K;i++)
		{
			int d = list[i].d;
			int dst_r = list[i].r + dirr[d], dst_c = list[i].c + dirc[d];
			int src_r = list[i].r, src_c = list[i].c;
			// if board is blue or out of range
			if(!inRange(dst_r) || !inRange(dst_c) || board[dst_r][dst_c].color == 2)
			{
				list[i].d = d = d/2*2 + (d+1)%2;
				dst_r = list[i].r + dirr[d], dst_c = list[i].c + dirc[d];
			}
			// blue again
			if(!inRange(dst_r) || !inRange(dst_c) || board[dst_r][dst_c].color == 2) continue;
			// white
			else if(board[dst_r][dst_c].color == 0)
			{
				auto start=find(board[src_r][src_c].placed.begin(),board[src_r][src_c].placed.end(),i);
				auto end = board[src_r][src_c].placed.end();
				for(auto j=start;j!=end;j+=1)
				{
					board[dst_r][dst_c].placed.push_back(*j);
					list[*j].r = dst_r;
					list[*j].c = dst_c;
				}
				board[src_r][src_c].placed.erase(start,board[src_r][src_c].placed.end());
			}
			//red
			else if(board[dst_r][dst_c].color == 1)
			{
				auto start=find(board[src_r][src_c].placed.begin(),board[src_r][src_c].placed.end(),i);
				auto end = board[src_r][src_c].placed.end()-1;
				for(auto j=end;j!=start-1;j-=1)
				{
					board[dst_r][dst_c].placed.push_back(*j);
					list[*j].r = dst_r;
					list[*j].c = dst_c;
				}
				board[src_r][src_c].placed.erase(start,board[src_r][src_c].placed.end());
			}
			
			if(board[dst_r][dst_c].placed.size()>=4)
			{
				printf("%d",t);
				return 0;
			}
			
			/*
			for(int j=0;j<N;j++)
			{
				for(int k=0;k<N;k++)
				{
					for(int l=0;l<board[j][k].placed.size();l++)
					{
						printf("%d/",board[j][k].placed[l]);
					}
					printf(". ");
				}
				printf("\n");
			}
			printf("\n");
			*/
		}
	}
	printf("-1");
}
/*
구현, 시뮬레이션
반복문을 도든 도중에 반복문의 조건부에 접근하여 값을 변경하는 코드에 주의하자
*/ 
