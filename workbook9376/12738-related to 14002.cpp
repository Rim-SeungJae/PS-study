#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

vector<int> arr,inc;

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
		if(inc.empty()) inc.push_back(arr[i]);
		else if(inc.back() < arr[i]) inc.push_back(arr[i]);
		else
		{
			int start = 0,end = inc.size() - 1,mid = (start+end)/2;
			while(start < end)
			{
				if(inc[mid] == arr[i]) break;
				else if(inc[mid] > arr[i])
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
			inc[mid] = arr[i];
		}
		/*
		for(int j=0;j<inc.size();j++)
		{
			printf("%d ",inc[j]);
		}
		printf("\n");
		*/
	}
	printf("%d",inc.size());
}
/*
이분탐색 & dp.
arr로 입력받아서 가장 긴 증가하는 부분 수열을 inc에 저장한다. 
arr[i]의 값을 하나씩 확인하여 inc의 마지막 값보다 크다면 뒤에 붙이고,
그렇지 않다면 이분탐색으로 arr[i]보다 큰 값중에 최소값을 찾아 치환한다.
inc 배열이 실제로는 불가능하더라도 길이는 맞출 수 있다는 아이디어를 활용한 풀이법.
*/ 
