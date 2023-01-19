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
bool visited[2000010];

int main()
{
	int n,k;
	priority_queue<pair<int,int>> pq;
	scanf("%d %d",&n,&k);
	pq.push(make_pair(0,n));
	if(n>k){
		printf("%d",n-k);
		return 0;
	}
	
	fill(dist,dist+200001,k-n);
	
	while(!pq.empty())
	{
		int min_idx = pq.top().second;
		int min_cost = -pq.top().first;
		//printf("%d %d\n",min_idx,min_cost);
		pq.pop();
		if(min_idx+1 < 200001 && dist[min_idx+1] > min_cost+1)
		{
			dist[min_idx+1] = min_cost + 1;
			pq.push(make_pair(-dist[min_idx+1],min_idx+1));
		}
		if(min_idx-1>=0 && dist[min_idx-1] > min_cost+1)
		{
			dist[min_idx-1] = min_cost + 1;
			pq.push(make_pair(-dist[min_idx-1],min_idx-1));
		}
		if(2*min_idx < 200001 && dist[min_idx * 2] > min_cost)
		{
			dist[min_idx * 2] =  min_cost;
			pq.push(make_pair(-dist[min_idx * 2],min_idx * 2));
		}
	}
	printf("%d",dist[k]);
} 
/*
���ͽ�Ʈ�� �˰�����
priority queue�� ������ ���ͽ�Ʈ�� �˰������� ������ ��������
����(100000)�� ����� �ʰ� �ݵ�� �����ظ� ã�� �� ������ ������ �� �ִ�. 
*/