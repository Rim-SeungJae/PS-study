#include<cstdio>

int arr[10010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=i;j<n;j++)
		{
			if(arr[i] < arr[j])
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				i = -1;
				break;
			}
		}
	}
}
