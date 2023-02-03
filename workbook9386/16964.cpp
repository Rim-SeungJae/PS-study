#include<cstdio>
#include<vector>

using namespace std;

vector<vector<int>> graph;
vector<int> v;
bool check[100010];
int idx;

void dfs(int x)
{
	if(check[x] == true){
		return;
	}
	check[x] = true;
	for(int i=0;i<graph[x].size();i++)
	{
		if(check[graph[x][i]] == false && graph[x][i] == v[idx+1]){
			idx++;
			printf("%d %d\n",idx,graph[x][i]);
			dfs(graph[x][i]);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	graph.assign(n+1,vector<int>());
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		scanf("%d %d",&s,&d);
		graph[s].push_back(d);
	}
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
	dfs(1);
	printf("%d",idx);
}
