#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n,m;
bool arr[1010][1010],visited[1010][1010];
int * A[1010][1010];
int ans[1010][1010];
const int dirr[4] = {0,-1,0,1},dirc[4] = {1,0,-1,0};


void bfs(int i,int j)
{
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	visited[i][j] = true;
	A[i][j] = new int;
	*A[i][j] = 0;
	while(!q.empty())
	{
		*A[i][j]+=1;
		int r,c;
		r = q.front().first;
		c = q.front().second;
		//printf("%d %d\n",r,c);
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nr,nc;
			nr = r+dirr[i];
			nc = c+dirc[i];
			if(nr>=0 && nr<n && nc>=0 && nc<m && !arr[nr][nc] && !visited[nr][nc])
			{
				visited[nr][nc] = true;
				A[nr][nc] = A[r][c];
				q.push(make_pair(nr,nc));
			}
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!arr[i][j])
			{
				if(!visited[i][j])bfs(i,j);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!arr[i][j]) printf("0");
			else{
				for(int k=0;k<4;k++)
				{
					int ni,nj;
					ni = i+dirr[k];
					nj = j+dirc[k];
					if(ni>=0 && ni<n && nj>=0 && nj<m && !arr[ni][nj])
					{
						int l=0;
						for(l=0;l<k;l++)
						{
							int nni,nnj;
							nni = i+dirr[l];
							nnj = j+dirc[l];
							if(nni>=0 && nni<n && nnj>=0 && nnj<m && !arr[nni][nnj])
							{
								if(A[ni][nj] == A[nni][nnj]) break;
							}
						}
						if(l!=k) continue;
						else ans[i][j] += *A[ni][nj];
					}
				}
				printf("%d",(ans[i][j]+1)%10);
			}
			
			//if(!arr[i][j])printf("%d",*A[i][j]);
		}
		printf("\n");
	}
}
/*
모든칸에서 bfs를 하는 방식은 너무 오래걸린다
더 효율적인 방법을 찾는 것이 핵심
*/ 
