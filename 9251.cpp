#include<cstdio>
#include<string>
using namespace std;
int dp[1010][1010];
int main()
{
	char tmp_a[1010],tmp_b[1010];
	string a,b;
	scanf("%s\n%s",&tmp_a,&tmp_b);
	a = string(tmp_a);
	b = string(tmp_b);
	for(int i=0;i<=a.length();i++)
	{
		for(int j=0;j<=b.length();j++)
		{
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = (dp[i-1][j]>dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
		}
	}
	printf("%d",dp[a.length()][b.length()]);
}
/*
longest common subsequence
*/
