#include<cstdio>
#include<vector>

using namespace std;

vector<int> * graph;
bool visited[2020];
bool result;

void dfs(int cur,int depth)
{
	if(depth >= 4)
	{
		result = true;
		return;
	}
	int max=0;
	for(int i=0;i<graph[cur].size();i++)
	{
		if(!visited[graph[cur][i]])
		{
			visited[cur] = true;
			dfs(graph[cur][i],depth+1);
            if(result == true) return;
			visited[cur] = false;
		}
	}
	//printf("%d %d %d\n",max,second,cur);
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	graph = new vector<int>[n];
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		dfs(i,0);
        if(result == true) break;
	}
	printf("%d",result);
}
/*
DFS ����
�ǹ���: result�� true�� ������ ���α׷��� �����ϵ��� �ߴ��� �ð��ʰ� ������ �ذ�Ǿ���.
�׷��� ����� false�̸鼭 �ð��ʰ��� ���� ���� ���°ɱ�?
*/ 
