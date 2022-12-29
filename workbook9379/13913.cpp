#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

struct cmp{
	bool operator()(pair<int,int> a, pair<int,int> b)
	{
		return a.second>b.second;
	}
};

int dist[2000010];
int prv[2000010]; 
bool visited[2000010];

void prt(int tmp){
	if(tmp == -1) return;
	prt(prv[tmp]);
	printf("%d ",tmp);
}

int main()
{
	int n,k;
	priority_queue<pair<int,int>> pq;
	scanf("%d %d",&n,&k);
	pq.push(make_pair(0,n));
	
	fill(dist,dist+200001,abs(n-k)+1);
	fill(prv,prv+200001,-1);
	dist[n] = 0;
	
	while(!pq.empty())
	{
		int min_idx = pq.top().second;
		int min_cost = -pq.top().first;
		//printf("%d %d\n",min_idx,min_cost);
		pq.pop();
		if(min_idx+1 < 200001 && dist[min_idx+1] > min_cost+1)
		{
			dist[min_idx+1] = min_cost + 1;
			prv[min_idx+1] = min_idx;
			pq.push(make_pair(-dist[min_idx+1],min_idx+1));
		}
		if(min_idx-1>=0 && dist[min_idx-1] > min_cost+1)
		{
			dist[min_idx-1] = min_cost + 1;
			prv[min_idx-1] = min_idx;
			pq.push(make_pair(-dist[min_idx-1],min_idx-1));
		}
		if(2*min_idx < 200001 && dist[min_idx * 2] > min_cost + 1)
		{
			dist[min_idx * 2] =  min_cost + 1;
			prv[min_idx * 2] = min_idx;
			pq.push(make_pair(-dist[min_idx * 2],min_idx * 2));
		}
	}
	printf("%d\n",dist[k]);
	prt(k);
} 
/*
다익스트라 알고리즘
13549번 문제에 경로를 출력하는 조건이 추가되었다. 
*/ 
