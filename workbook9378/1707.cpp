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
dfs 응용
의외로 엄청 오래걸린 문제. 아래는 주요한 실수들을 나열하였다.
26행: 이 문제는 백트래킹을 할 필요가 없다. 한번의 dfs만 실행하면 된다. 그러므로 26행은 필요 없는 코드.
59행: 그래프의 초기화 부분이다. 테스트케이스가 여러가지인 문제에서는 항상 변수들의 초기화를 잊지말자.
그리고 중첩 for문의 사용에 있어서 i,j 등 변수의 이름에 주의할것. 
*/ 
 
