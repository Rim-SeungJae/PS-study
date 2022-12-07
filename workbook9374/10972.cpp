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
순열의 규칙성에 대해서 잘 생각해보자
뒤에서 부터 검사하여 뒷자리가 자기보다 큰 위치를 찾는다.
또 다시 뒤에서부터 검사하여 해당 위치보다 큰 수의 위치를 찾아 서로 위치를 바꾼다.
마지막으로 바꾼 자리부터 마지막 자리까지 오름차순으로 정렬한다. 
*/ 
