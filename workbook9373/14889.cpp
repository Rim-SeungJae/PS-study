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
기본적인 백트래킹.
팀에 한명씩 넣는다고 생각하기 보다 모든 사람이 포함된 팀에서 한명씩 빼는게 쉽다. 
중복되는 검사를 하지 않도록 해서 시간초과를 피하는 것이 핵심.
*/ 
