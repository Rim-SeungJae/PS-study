#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class node{
	public:
		int r,c,priority;
		bool operator<(const node b) const
		{
			return b.priority < this->priority;
		}
		node(int a,int b,int c)
		{
			this->r=a;
			this->c=b;
			this->priority=c;
		}
};

char arr[1550][1550];
int w[1550][1550] = {0,},dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
bool visited[1550][1550] = {0,};
priority_queue<node> pq;
queue<pair<int,int>> q;

int main()
{
	int r,c,cnt=0,L1_r=-1,L1_c,L2_r,L2_c;
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++)
	{
		scanf("\n");
		for(int j=0;j<c;j++)
		{
			scanf("%c",&arr[i][j]);
			if(arr[i][j] == 'X') cnt++;
			else visited[i][j] = true;
			if(arr[i][j] == 'L')
			{
				if(L1_r==-1)
				{
					L1_r = i;
					L1_c = j;
				}
				else{
					L2_r = i;
					L2_c = j;
				}
			}
		}
	}
	int t=1;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(arr[i][j]=='X')
			{
				for(int k=0;k<4;k++)
				{
					if(i+dx[k]>=0 && i+dx[k]<r && j+dy[k]>=0 && j+dy[k]<c && arr[i+dx[k]][j+dy[k]] == '.' || arr[i+dx[k]][j+dy[k]] == 'L')
					{
						visited[i][j] = true;
						w[i][j] = t;
						q.push(make_pair(i,j));
						break;
					}
				}
			}
		}
	}
	/*
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			printf("%d",w[i][j]);
		}
		printf("\n");
	}
	*/
	while(!q.empty())
	{
		t++;
		int n = q.size();
		for(int k=0;k<n;k++)
		{
			int tr = q.front().first, tc = q.front().second;
			q.pop();
			for(int i=0;i<4;i++)
			{
				if(tr+dx[i]>=0 && tr+dx[i]<r && tc+dy[i]>=0 && tc+dy[i]<c && !visited[tr+dx[i]][tc+dy[i]])
				{
					visited[tr+dx[i]][tc+dy[i]] = true;
					w[tr+dx[i]][tc+dy[i]] = t;
					q.push(make_pair(tr+dx[i],tc+dy[i]));
				}
			}
		}
		/*
		printf("\n----------------------------------------------------------------------\n");
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				printf("%d",w[i][j]);
			}
			printf("\n");
		}
		*/
	}
	
	fill(&visited[0][0],&visited[1549][1550],0);
	pq.push(node(L1_r,L1_c,0));
	visited[L1_r][L1_c] = true;
	int max_t = 0;
	while(!pq.empty())
	{
		node target = pq.top();
		pq.pop();
		int tr = target.r, tc = target.c;
		if(tr == L2_r && tc == L2_c)
		{
			break;
		}
		if(target.priority>max_t) max_t = target.priority;
		for(int i=0;i<4;i++)
		{
			if(tr+dx[i]>=0 && tr+dx[i]<r && tc+dy[i]>=0 && tc+dy[i]<c && !visited[tr+dx[i]][tc+dy[i]])
			{
				visited[tr+dx[i]][tc+dy[i]] = true;
				pq.push(node(tr+dx[i],tc+dy[i],w[tr+dx[i]][tc+dy[i]]));
			}
		}
	}
	printf("%d",max_t);
}
