#include<cstdio>
#include<typeinfo>

int arr[5][5];
bool d[5][5];
int n,m,max;

void bt(int x,int y)
{
	if(x >= n)
	{
		int sum = 0;
		for(int j=0;j<n;j++)
		{
			int rowsum = 0;
			for(int k=0;k<m;k++)
			{
				if(d[j][k])
				{
					rowsum *= 10;
					rowsum += arr[j][k];
				}
				else
				{
					sum += rowsum;
					rowsum = 0;
				}
			}
			sum += rowsum;
		}
		for(int j=0;j<m;j++)
		{
			int colsum = 0;
			for(int k=0;k<n;k++)
			{
				if(!d[k][j])
				{
					colsum *= 10;
					colsum += arr[k][j];
				}
				else
				{
					sum += colsum;
					colsum = 0;
				}
			}
			sum += colsum;
		}
		//printf("%d ",sum);
		if(sum > max) max = sum;
		return;
	}
	d[x][y] = false;
	bt(x+(y+1)/m, (y+1)%m);
	d[x][y] = true;
	bt(x+(y+1)/m, (y+1)%m);
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%1d",&arr[i][j]);
		}
	}
	bt(0,0);
	printf("%d",max);
}
/*
�⺻���� ��Ʈ��ŷ.
c����� ��� ��Ʈ����ũ�� �̿��� Ǯ�� �׽�Ʈ���̽��� ������� ���Ѵ�.
�Ƹ� �����÷ο� ���� �����ε�.
*/ 
