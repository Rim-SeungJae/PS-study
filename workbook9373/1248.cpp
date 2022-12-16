#include<cstdio>
#include<vector>

using namespace std;

int n;
vector<char> arr[12];
bool isFound = false;

void bt(vector<int> v,int idx)
{
	if(isFound) return;
	if(idx == n)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d ",v[i]);
		}
		isFound = true;
		return;
	}
	for(int i=-10;i<=10;i++)
	{
		int sum = 0,j;
		for( j=idx;j>=0;j--)
		{
			sum+=v[j];
			//printf("%d %d %d\n",idx,j,sum);
			if(arr[idx][j] == '0' && sum!=0) break;
			if(arr[idx][j] == '+' && sum<=0) break;
			if(arr[idx][j] == '-' && sum>=0) break;
		}
		if(j!=-1) continue;
		v.push_back(i);
		bt(v,idx+1);
		if(isFound) return;
		v.pop_back();
	}
	
}

int main()
{
	scanf("%d\n",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			char tmp;
			scanf("%c",&tmp);
			arr[j+i].push_back(tmp);
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<arr[i].size();j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
	*/
	for(int i=-10;i<=10;i++)
	{
		bt(vector<int>(1,i),0);
	}
}
/*
백트래킹
벡터에 -10부터 10까지 하나씩 값을 추가해 보면서 조건을 만족하는지 확인한다.
의외로 시간초과가 나지 않는다
*/ 
