#include<cstdio>

int main()
{
	int k;
	char arr[10];
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf(" %c",&arr[i]);
	}
	int max[10] = {0,};
	max[0] = 9;
	for(int i=1;i<=k;i++)
	{
		if(arr[i] == '>') max[i] = 9-i;
		else{
			max[i] = max[i-1];
			for(int j=i;j>0 && arr[j] != '>';j--)
			{
				max[j-1]--;
			}
		}
	}
	for(int i=0;i<=k;i++)
	{
		printf("%d",max[i]);
	}
	printf("\n");
	int min[10] = {0,};
	for(int i=1;i<=k;i++)
	{
		if(arr[i] == '<') min[i] = i;
		else{
			min[i] = min[i-1];
			for(int j=i;j>0 && arr[j] != '<';j--)
			{
				min[j-1]++;
			}
		}
	}
	for(int i=0;i<=k;i++)
	{
		printf("%d",min[i]);
	}
}
/*
�ֵ� Ȥ ������� Ǯ���Ͽ���.
���Ʈ����, ��Ʈ��ŷ���ε� �ذ� ������ ����.
*/ 
