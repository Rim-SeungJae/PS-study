#include<cstdio>

long long arr[100];

int main()
{
	int n;
	scanf("%d",&n);
	arr[0] = 1;
	arr[1] = 1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i-1;j++)
		{
			arr[i] += arr[j];
		}
	}
	printf("%lld",arr[n]);
}
/*
�⺻���� ���̳���
int�� ������ ����ٴ� ���� ��������
*/ 
