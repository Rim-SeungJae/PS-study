#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

class Passenger{
	public:
		int src_r;
		int src_c;
		int dst_r;
		int dst_c;
		bool operator <(Passenger p) const
		{
			if(src_r == p.src_r) return src_c < p.src_c;
			return src_r < p.src_r;
		}
		Passenger(int a,int b,int c,int d)
		{
			src_r = a;
			src_c = b;
			dst_r = c;
			dst_c = d;
		}
		Passenger()
		{
		}
};

int n,m,fuel,arr[22][22],taxi_r,taxi_c;
vector<Passenger> pq;

bool inRange(int a)
{
	if(a>=0 && a<n) return true;
	else return false;
}

int bfs(int src_r,int src_c,int dst_r,int dst_c)
{
	queue<pair<int,int>> q;
	q.push(make_pair(src_r,src_c));
	int d[22][22] = {0,};
	bool visited[22][22] = {0,};
	while(!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if(r == dst_r && c == dst_c)
		{
			return d[r][c];
		}
		if(inRange(r-1) && !visited[r-1][c] && arr[r-1][c]!=1)
		{
			d[r-1][c] = d[r][c]+1;
			visited[r-1][c] = true;
			q.push(make_pair(r-1,c));
		}
		if(inRange(r+1) && !visited[r+1][c] && arr[r+1][c]!=1)
		{
			d[r+1][c] = d[r][c]+1;
			visited[r+1][c] = true;
			q.push(make_pair(r+1,c));
		}
		if(inRange(c-1) && !visited[r][c-1] && arr[r][c-1]!=1)
		{
			d[r][c-1] = d[r][c]+1;
			visited[r][c-1] = true;
			q.push(make_pair(r,c-1));
		}
		if(inRange(c+1) && !visited[r][c+1] && arr[r][c+1]!=1)
		{
			d[r][c+1] = d[r][c]+1;
			visited[r][c+1] = true;
			q.push(make_pair(r,c+1));
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d %d",&n,&m,&fuel);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	scanf("%d %d",&taxi_r,&taxi_c);
	taxi_r--;
	taxi_c--;
	for(int i=0;i<m;i++)
	{
		int src_r,src_c,dst_r,dst_c;
		scanf("%d %d %d %d",&src_r,&src_c,&dst_r,&dst_c);
		pq.push_back(Passenger(src_r-1,src_c-1,dst_r-1,dst_c-1));
	}
	sort(pq.begin(),pq.end());
	
	while(!pq.empty())
	{
		int result=100000000,min_idx=-1;
		for(int i=0;i<pq.size();i++)
		{
			Passenger p = pq[i];
			int tmp = bfs(taxi_r,taxi_c,p.src_r,p.src_c);
			if(tmp!=-1 && tmp<result)
			{
				result = tmp;
				min_idx = i;
			}
		}
		Passenger p;
		if(min_idx!=-1) p =pq[min_idx];
		//printf("%d %d %d %d:%d ",taxi_r,taxi_c,p.src_r,p.src_c,result);
		if(min_idx==-1 || fuel < result)
		{
			printf("-1");
			return 0;
		}
		else
		{
			pq.erase(pq.begin()+min_idx);
			taxi_r = p.src_r;
			taxi_c = p.src_c;
			fuel -= result;
		}
		result = bfs(taxi_r,taxi_c,p.dst_r,p.dst_c);
		//printf("%d %d %d %d:%d\n",taxi_r,taxi_c,p.dst_r,p.dst_c,result);
		if(result == -1 || fuel < result)
		{
			printf("-1");
			return 0;
		}
		else
		{
			taxi_r = p.dst_r;
			taxi_c = p.dst_c;
			fuel += result;
		}
	}
	printf("%d",fuel);
}
/*
코드가 의도된 대로 작성되었는지 잘 점검하자
102행의 sort를 빼먹어서 고생한 문제
*/ 
