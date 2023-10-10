#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int D[1010],mt,dp[1010];
vector<vector<int>> g;

int dfs(int node,int depth)
{
	if(dp[node]!=-1)
	{
		depth += dp[node];
		if(mt<depth) mt = depth;
		return dp[node];
	}
	if(g[node].empty())
	{
		dp[node] = D[node];
		depth += D[node];
		if(mt<depth) mt = depth;
		return D[node];
	}
	int md = 0;
	for(int i=0;i<g[node].size();i++)
	{
		int tmp = dfs(g[node][i],depth+D[node]);
		if(tmp>md) md = tmp;
	}
	dp[node] = md + D[node];
	return dp[node];
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int epoch = 0;epoch<t;epoch++)
	{
		mt = 0;
		for(int i=0;i<g.size();i++)
		{
			g[i].clear();
		}
		g.clear();
		fill(dp,&dp[1010],-1);
		int N,K,W;
		scanf("%d %d",&N,&K);
		g.assign(N+1,vector<int>());
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&D[i]);
		}
		for(int i=0;i<K;i++)
		{
			int X,Y;
			scanf("%d %d",&X,&Y);
			g[Y].push_back(X);
		}
		scanf("%d",&W);
		
		//dfs
		dfs(W,0);
		printf("%d\n",mt);
	}
}
/*
다이나믹을 할때 0으로 초기화하는 것을 주의하자
dp의 결과값이 0인지, 초기값 0인지 구별할 수 없다
*/ 
