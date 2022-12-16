#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	int n,m,sum=0;
	vector<int> div;
	vector<int> nxt;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			sum = (sum+i%1000000007)%1000000007;
			div.push_back(i);
		}
	}
	nxt = div;
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			for(int k=1;k<nxt.size();k++)
			{

				nxt[k] = (nxt[k] + div[k]%1000000007)%1000000007;
			}
		}
		for(int k=1;k<nxt.size();k++)
		{
			sum = (sum+nxt[k]%1000000007)%1000000007;
		}
		div = nxt;
	}
	printf("%d",sum);
}
