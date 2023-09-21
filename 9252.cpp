#include<cstdio>
#include<string>

using namespace std;

int dp[1010][1010];

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	string a,b;
	char tmp[1010];
	scanf("%s\n",tmp);
	a.assign(tmp);
	scanf("%s",tmp);
	b.assign(tmp);
	for(int i=0;i<=a.length();i++)
	{
		for(int j=0;j<=b.length();j++)
		{
			if(i==0 || j==0) dp[i][j] = 0;
			else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	string res = "";
	int i=a.length(),j=b.length();
	printf("%d\n",dp[i][j]);
	while(dp[i][j] !=0)
	{
	
		if(dp[i][j] == dp[i-1][j])
		{
			i--;
			continue;
		}
		else if(dp[i][j] == dp[i][j-1])
		{
			j--;
			continue;
		}
		else
		{
			res.insert(res.begin(),1,a[i-1]);
			i--;
			j--;
		}
	}
	if(res.length()>0) printf("%s",res.c_str());
}
/*
Least common subsequence
*/
