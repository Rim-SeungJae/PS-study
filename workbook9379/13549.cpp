#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

struct cmp{
	bool operator()(pair<int,int> a, pair<int,int> b)
	{
		return a.second>b.second;
	}
};

int dist[2000010];
bool visited[2000010];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	if(n>k){
		printf("%d",n-k);
		return 0;
	}
	int max_val = k-n;
	fill(dist,dist+200001,max_val);
	dist[n] = 0;
	
	while(true)
	{
		int min_dist=max_val,min_idx = -1;
		for(int i=0;i<200001;i++)
		{
			if(dist[i]<=min_dist && !visited[i])
			{
				min_dist = dist[i];
				min_idx = i;
			}
		}
		
		visited[min_idx]
	}
} 
