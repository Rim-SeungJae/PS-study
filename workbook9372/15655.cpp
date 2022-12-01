#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool visited[10] = {0,};

void backtrack(vector<int> v, vector<int> seq,int len)
{
	if(seq.size() >= len)
	{
		for(int i=0;i<seq.size();i++)
		{
			printf("%d ",seq[i]);
		}
		printf("\n");
		return;
	}
	for(int i=0;i<v.size();i++)
	{
		if(!visited[i])
		{
			if(!seq.empty() && seq.back()>v[i]) continue;
			//visited[i] = true;
			seq.push_back(v[i]);
			backtrack(v,seq,len);
			seq.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> v,seq;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp); 
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	backtrack(v,seq,m);
}
