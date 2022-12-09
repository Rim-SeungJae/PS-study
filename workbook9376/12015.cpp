#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

int arr[1000010],dp[1000010];

using namespace std;

multimap<int,int,greater<int>> mm;

int main()
{
	int n,max=0;
	vector<int> v;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mm.insert(pair<int,int>(arr[0],0));
	for(int i=1;i<n;i++)
	{
		multimap<int,int>::iterator upper_iter;
		upper_iter=mm.upper_bound(arr[i]);
		printf("%d %d\n",arr[i],upper_iter->first);
		if(upper_iter != mm.end())
		{
			mm.insert(pair<int,int>(arr[i],upper_iter->second + 1));
			if(upper_iter->second+1 > max) max = upper_iter->second+1;
		}
		else
		{
			mm.insert(pair<int,int>(arr[i],0));
		}
		//printf("%2d ",mm.find(arr[i]) -> second);
	}
	
	printf("%d",max+1);
}
