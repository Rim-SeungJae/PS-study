#include<cstdio>
#include<stack>
#include<algorithm>

using namespace std;

int main()
{
	int chose[100010];
	bool visited[100010], loop[100010];
	long long t;
	stack<int> s;
	scanf("%d",&t);
	for(long long iter=0;iter<t;iter++)
	{
		int n,res;
		scanf("%d",&n);
		res = n;
		for(int i=0;i<n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			chose[i] = tmp-1;
		}
		fill(visited,visited+n,0);
		for(int i=0;i<n;i++)
		{
			if(visited[i]) continue;
			fill(loop,loop+n,0);
			int cur = i;
			while(!visited[cur])
			{
				//printf("%d %d\n",i,cur);
				visited[cur] = true;
				loop[cur] = true;
				s.push(cur);
				cur = chose[cur];
			}
			int cnt=0;
			if(loop[cur])
			{
				if(cur == i)
				{
					cnt = s.size();
				}
				else
				{
					int start = s.top();
					s.pop();
					cnt++;
					while(start!=cur && !s.empty())
					{
						start = s.top();
						s.pop();
						cnt++;
					}
				}
				res -= cnt;
				//printf("%d\n",cnt);
			}
			while(!s.empty()) s.pop();
		}
		printf("%d\n",res);
	}
}
