#include<cstdio>
#include<algorithm>

using namespace std;
int arr[10010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int i;
	for(i=n-1;i>=0;i--)
	{
		for(int j=n;j>i;j--)
		{
			if(arr[i] < arr[j])
			{
				//printf("%d %d",arr[i],arr[j]);
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				sort(arr+i+1,arr+n);
				i = -1;
				break;
			}
		}
	}
	if(i!=-2) printf("-1");
	else
	{
		for(int i=0;i<n;i++)
		{
			printf("%d ",arr[i]);
		}
	}
}
/*
������ ��Ģ���� ���ؼ� �� �����غ���
�ڿ��� ���� �˻��Ͽ� ���ڸ��� �ڱ⺸�� ū ��ġ�� ã�´�.
�� �ٽ� �ڿ������� �˻��Ͽ� �ش� ��ġ���� ū ���� ��ġ�� ã�� ���� ��ġ�� �ٲ۴�.
���������� �ٲ� �ڸ����� ������ �ڸ����� ������������ �����Ѵ�. 
*/ 
