#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr,inc,LIS;
vector<vector<int>> inc_t;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		arr.push_back(tmp);
	}
	for(int i=0;i<n;i++)
	{
		if(inc.empty())
		{
			inc.push_back(i);
			inc_t.push_back(vector<int>({i}));
		}
		else if(arr[inc.back()] < arr[i])
		{
			inc.push_back(i);
			inc_t.push_back(vector<int>({i}));
		}
		else
		{
			int start = 0,end = inc.size(),mid = (start+end)/2;
			while(start < end)
			{
				if(arr[inc[mid]] == arr[i]) break;
				else if(arr[inc[mid]] > arr[i])
				{
					end = mid;
					mid = (start+end)/2;
				}
				else
				{
					start = mid+1;
					mid = (start+end)/2;
				}
			}
			inc[mid] = i;
			inc_t[mid].push_back(i);
		}
		
		for(int j=0;j<inc.size();j++)
		{
			printf("%d ",arr[inc[j]]);
		}
		printf("\n");
		
	}
	printf("%d",inc.size());
	printf("\n");
	LIS.push_back(inc_t.back().back());
	for(int i=inc_t.size()-2;i>=0;i--)
	{
		for(int j=inc_t[i].size()-1;j>=0;j--)
		{
			if(arr[inc_t[i][j]] < arr[LIS.back()] && inc_t[i][j] < LIS.back())
			{
				LIS.push_back(inc_t[i][j]);
				break;
			}
		}
	}
	for(int i=LIS.size()-1;i>=0;i--)
	{
		printf("%d ",arr[LIS[i]]);
	}
}
/*
이분탐색 & dp.
inc의 원소들을 모두 기억해 놓았다가 LIS의 출력에 이용한다.
*/ 
