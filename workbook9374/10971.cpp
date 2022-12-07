#include<cstdio>
#include<vector>

using namespace std;

int mind=-1,n;
bool visited[11];
void t(vector<pair<int, int>> * graph, int start, int len, int cur)
{
	if(start == cur && len != 0)
	{
		bool complete = true;
		for(int i=0;i<n;i++)
		{
			complete &= visited[i];
		}
		if(complete)
		{
			mind == -1 ? mind = len : (len < mind ? mind = len : false ); 
		}
		return;
	}
	for(int i=0;i<graph[cur].size();i++)
	{
		int dest = graph[cur][i].first;
		int dist = graph[cur][i].second;
		if(!visited[dest] || dest == start)
		{
			visited[dest] = true;
			t(graph,start,len + dist,dest);
			visited[dest] = false;
		}
	}
}

int main()
{
	scanf("%d",&n);
	vector<pair<int, int>> * graph = new vector<pair<int, int>>[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(tmp!=0)
			{
				graph[i].push_back(make_pair(j,tmp));
			}
		}
	}
	t(graph,0,0,0);
	printf("%d",mind);
}
/*
���Ʈ����
tsp ���������� �ּҺ�����Ʈ�� �˰����� ����� �� ����.
vector�� pair�� Ȱ���� graph�� ������ �Ű澲��
*/ 
