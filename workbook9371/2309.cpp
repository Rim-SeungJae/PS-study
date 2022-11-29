#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int arr[10],sum = 0;
	for(int i=0;i<9;i++)
	{
		scanf("%d",&arr[i]);
		sum +=arr[i];
	}
	sort(arr,arr+9);
	int target = sum - 100;
	for(int i=0;i<9;i++)
	{
		int j;
		for(j=i;j<9;j++)
		{
			if(arr[i] + arr[j] == target)
			{
				arr[i] = arr[j] = 200;
				i=9;
			}
		}
	}
	sort(arr,arr+9);
	for(int i=0;i<7;i++)
	{
		printf("%d\n",arr[i]);
	}
 } 
