#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int in[1010],out[1010];
vector<vector<int>> g;
vector<int> res;

int main()
{
	int N,K;
	scanf("%d %d",&N,&K);
	g.assign(N+1,vector<int>());
	for(int i=1;i<=K;i++)
	{
		int t,prev,cur;
		scanf("%d",&t); 
		for(int j=0;j<t;j++)
		{
			prev = cur;
			scanf("%d",&cur);
			if(j!=0)
			{
				g[prev].push_back(cur);
				out[prev]++;
				in[cur]++;
			}
		}
	}
	queue<int> q;
	for(int i=1;i<=N;i++)
	{
		if(in[i]==0) q.push(i);
	}
	while(!q.empty())
	{
		int target = q.front();
		res.push_back(target);
		q.pop();
		for(int i=0;i<g[target].size();i++)
		{
			in[g[target][i]]--;
			if(in[g[target][i]]==0) q.push(g[target][i]);
		}
	}
	if(res.size()!=N) printf("0");
	else{
		for(int i=0;i<res.size();i++)
		{
			printf("%d\n",res[i]);
		}
	}
}
/*
위상정렬
*/ 
