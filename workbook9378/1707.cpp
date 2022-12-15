#include<cstdio>
#include<vector>

using namespace std;

vector<int> graph[20020];
int visited[20020];
int visited_long[20020];
bool result = true;

void dfs(int cur,bool state)
{
	visited_long[cur] = true;
	for(int i=0;i<graph[cur].size();i++)
	{
		//printf("%d %d %d\n",cur,graph[cur][i],state);
		if(visited[graph[cur][i]] && visited[graph[cur][i]] == state+1)
		{
			result=false;
			return;
		}
		if(!visited[graph[cur][i]])
		{
			visited[cur] = state+1;
			dfs(graph[cur][i],!state);
			//visited[cur] = 0;
			if(!result) return;
		}
	}
	//printf("%d %d %d\n",max,second,cur);
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int v,e;
		scanf("%d %d",&v,&e);
		for(int j=0;j<e;j++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for(int j=1;j<=v;j++)
		{
			if(!visited_long[j])dfs(j,0);
			//else printf("hi");
	        if(result == false) break;
		}
		if(result) printf("YES\n");
		else printf("NO\n");
		result = true;
		for(int j=1;j<=v;j++)
		{
			graph[j].clear();
		}
		fill(visited_long,visited_long+20010,0);
		fill(visited,visited+20010,0);
	}
}
/*
dfs ����
�ǿܷ� ��û �����ɸ� ����. �Ʒ��� �ֿ��� �Ǽ����� �����Ͽ���.
26��: �� ������ ��Ʈ��ŷ�� �� �ʿ䰡 ����. �ѹ��� dfs�� �����ϸ� �ȴ�. �׷��Ƿ� 26���� �ʿ� ���� �ڵ�.
59��: �׷����� �ʱ�ȭ �κ��̴�. �׽�Ʈ���̽��� ���������� ���������� �׻� �������� �ʱ�ȭ�� ��������.
�׸��� ��ø for���� ��뿡 �־ i,j �� ������ �̸��� �����Ұ�. 
*/ 
 
