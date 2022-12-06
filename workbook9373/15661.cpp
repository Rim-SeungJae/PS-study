#include<cstdio>
#include<cmath>
#include<vector>

bool visited[22];

using namespace std;

int bt(int arr[][22], vector<int> start,int n)
{

	vector<int> link;
	int link_sum = 0,start_sum=0;
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			link.push_back(i);
		}
	}
	for(vector<int>::iterator i=start.begin();i!=start.end();i++)
	{
		for(vector<int>::iterator j=i+1;j!=start.end();j++)
		{
			start_sum += arr[*i][*j] + arr[*j][*i];
		}
	}
	for(vector<int>::iterator i=link.begin();i!=link.end();i++)
	{
		for(vector<int>::iterator j=i+1;j!=link.end();j++)
		{
			link_sum += arr[*i][*j] + arr[*j][*i];
		}
	}
	int diff = abs(start_sum - link_sum);
	if(start.size() > n/2) return diff;
	int min = diff;
	for(int i=start.back()+1;i<n;i++)
	{
		if(!visited[i])
		{
			int tmp;
			visited[i] = true;
			start.push_back(i);
			tmp = bt(arr,start,n);
			start.pop_back();
			visited[i] = false;
			if(tmp < min) min=tmp;
		}
	}
	return min;
}

int main()
{
	int n,arr[22][22];
	vector<int> start;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	visited[0] = true;
	start.push_back(0);
	printf("%d",bt(arr,start,n));
}
/*
브루트포스
14889의 심화 버전.
비트마스크 등을 이용한 다른 풀이법도 있으니 참고할것. 
*/ 
