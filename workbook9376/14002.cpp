#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,arr[1010],dp[1010][2];
	vector<int> v[1010][2];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	dp[0][0] = 0;
	dp[0][1] = 1;
	v[0][1].push_back(arr[0]);
	for(int i=1;i<n;i++)
	{
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		if(dp[i-1][0] > dp[i-1][1])
		{
			v[i][0] = v[i-1][0];
		}
		else
		{
			v[i][0] = v[i-1][1];
		}
		int max_len = 1;
		dp[i][1] = 1;
		for(int j=0;j<i;j++)
		{
			if(arr[j] < arr[i] && max_len < dp[j][1]+1)
			{
				max_len = dp[j][1]+1;
				dp[i][1] = dp[j][1] + 1;
				v[i][1] = v[j][1];
			}
		}
		v[i][1].push_back(arr[i]);
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<v[i][0].size();j++)
		{
			printf("%d ",v[i][0][j]);
		}
		printf("\n");
		for(int j=0;j<v[i][1].size();j++)
		{
			printf("%d ",v[i][1][j]);
		}
		printf("\n\n");
	}
	*/
	printf("%d\n",max(dp[n-1][0],dp[n-1][1]));
	if(dp[n-1][0] > dp[n-1][1])
	{
		for(int j=0;j<v[n-1][0].size();j++)
		{
			printf("%d ",v[n-1][0][j]);
		}
	}
	else
	{
		for(int j=0;j<v[n-1][1].size();j++)
		{
			printf("%d ",v[n-1][1][j]);
		}
	}
}
/*
��ǥ���� ���̳��� ����
dp[i][0]�� �ڱ��ڽ��� �������� �ʾ��� ��, dp[i][1]�� ������������ �ִ���̶�� ������ Ǯ�̹��̴�. 
�� ����� Ǯ�̰� ������ �����Ұ�
*/ 
