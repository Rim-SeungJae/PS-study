#include<cstdio>
#include<vector>

using namespace std;


int N,M,K,A[11][11],manure[11][11];
vector<int> trees[11][11];

bool inRange(int a)
{
	if(a>=0 && a<N) return  true;
	else return false;
}

int main()
{
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(int i=0;i<M;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		trees[x-1][y-1].insert(lower_bound(trees[x-1][y-1].begin(),trees[x-1][y-1].end(),z),z);
	}
	fill(&manure[0][0],&manure[10][11],5);
	for(int t=0;t<K;t++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				// spring
				int k;
				for(k=0;k<trees[i][j].size();k++)
				{
					if(manure[i][j]>=trees[i][j][k])
					{
						manure[i][j] -= trees[i][j][k];
						trees[i][j][k]++;
					}
					else break;
				}
				
				// summer
				for(int l=trees[i][j].size()-1;l>=k;l--)
				{
					manure[i][j] += trees[i][j][l]/2;
					trees[i][j].erase(trees[i][j].begin()+l);
				}
			}
		}
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				// fall
				for(int k=0;k<trees[i][j].size();k++)
				{
					if(trees[i][j][k]%5 == 0)
					{
						if(inRange(i-1) && inRange(j-1)) trees[i-1][j-1].insert(trees[i-1][j-1].begin(),1);
						if(inRange(i-1)) trees[i-1][j].insert(trees[i-1][j].begin(),1);
						if(inRange(i-1) && inRange(j+1)) trees[i-1][j+1].insert(trees[i-1][j+1].begin(),1);
						if(inRange(j-1)) trees[i][j-1].insert(trees[i][j-1].begin(),1);
						if(inRange(j+1)) trees[i][j+1].insert(trees[i][j+1].begin(),1);
						if(inRange(i+1) && inRange(j-1)) trees[i+1][j-1].insert(trees[i+1][j-1].begin(),1);
						if(inRange(i+1)) trees[i+1][j].insert(trees[i+1][j].begin(),1);
						if(inRange(i+1) && inRange(j+1)) trees[i+1][j+1].insert(trees[i+1][j+1].begin(),1);
					}
				}
				
				// winter
				manure[i][j] += A[i][j];
			}
		}
		/*
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				printf("%d ",manure[i][j]);
			}
			printf("\n");
		}
		*/
	}
	int tree_cnt = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			tree_cnt += trees[i][j].size();
		}
	}
	printf("%d",tree_cnt);
}
/*
구현, 시뮬레이션
*/ 
