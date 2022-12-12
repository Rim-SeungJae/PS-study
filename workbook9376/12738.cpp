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
�̺�Ž�� & dp.
arr�� �Է¹޾Ƽ� ���� �� �����ϴ� �κ� ������ inc�� �����Ѵ�. 
arr[i]�� ���� �ϳ��� Ȯ���Ͽ� inc�� ������ ������ ũ�ٸ� �ڿ� ���̰�,
�׷��� �ʴٸ� �̺�Ž������ arr[i]���� ū ���߿� �ּҰ��� ã�� ġȯ�Ѵ�.
inc �迭�� �����δ� �Ұ����ϴ��� ���̴� ���� �� �ִٴ� ���̵� Ȱ���� Ǯ�̹�.
*/ 
