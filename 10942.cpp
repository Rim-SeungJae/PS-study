#include<cstdio>

using namespace std;

int dp[2020][2020],n,m,num[2020];

bool is_pelindrom(int a,int b)
{
	if(dp[a][b]!=0)
	{
		return dp[a][b] == 1;
	}
	if(a>b) return true;
	if(a == b)
	{
		dp[a][b] = 1;
		return true;
	}
	else
	{
		if(num[a] != num[b])
		{
			dp[a][b] = 2;
			return false;
		}
		else
		{
			bool tmp = is_pelindrom(a+1,b-1);
			if(tmp) dp[a][b] = 1;
			else dp[a][b] = 2;
			return dp[a][b] == 1;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		b--;
		printf("%d\n",is_pelindrom(a,b));
	}
}
