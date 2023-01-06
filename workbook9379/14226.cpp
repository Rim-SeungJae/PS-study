#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int dist[1010][1010];

int main()
{
	int n = 1,k;
	const int INF = 100000000;
	scanf("%d",&k);
	priority_queue<pair<int,pair<int,int>>> pq;
	pq.push(make_pair(0,make_pair(n,0)));
	
	fill(&dist[0][0],&dist[1000][1001],INF);
	
	while(!pq.empty())
	{
		int min_idx = pq.top().second.first;
		int min_idx_sec = pq.top().second.second;
		int min_cost = -pq.top().first;
		//printf("%d %d %d\n",min_idx,min_idx_sec,min_cost);
		pq.pop();
		if(dist[min_idx][min_idx] > min_cost+1)
		{
			dist[min_idx][min_idx] = min_cost + 1;
			pq.push(make_pair(-dist[min_idx][min_idx],make_pair(min_idx,min_idx)));
		}
		if(min_idx-1>=0 && dist[min_idx-1][min_idx_sec] > min_cost+1)
		{
			dist[min_idx-1][min_idx_sec] = min_cost + 1;
			pq.push(make_pair(-dist[min_idx-1][min_idx_sec],make_pair(min_idx-1,min_idx_sec)));
		}
		if(min_idx + min_idx_sec < 1001 && dist[min_idx + min_idx_sec][min_idx_sec] > min_cost + 1)
		{
			dist[min_idx + min_idx_sec][min_idx_sec] =  min_cost + 1;
			pq.push(make_pair(-dist[min_idx + min_idx_sec][min_idx_sec],make_pair(min_idx + min_idx_sec,min_idx_sec)));
		}
	}
	int min = INF;
	for(int i=0;i<1001;i++)
	{
		if(dist[k][i] < min) min = dist[k][i];
	}
	printf("%d",min);
} 
/*
다익스트라
꽤 오래 걸린다. 훨씬 빠른 풀이가 있으니 참고할것
*/ 
