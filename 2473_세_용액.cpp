#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int n,arr[5050];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(&arr[0],&arr[n]);
	int l,r,m,close_idx[3];
	long long close = 3000000300;
	bool zero_flag = true, close_flag = true;
	for(int k=0;k<n-2;k++)
	{
		l = k+1;
		r = n-1;
		while(r>l)
		{
			long long sum = arr[l]+arr[r];
			if(abs(close)>abs(sum+arr[k]))
			{
				close=sum+arr[k];
				close_idx[0] = k;
				close_idx[1] = l;
				close_idx[2] = r;
			}
			if(sum+arr[k] == 0) break;
			else if(sum+arr[k] > 0) r--;
			else l++;
		}
	}
	printf("%d %d %d",arr[close_idx[0]],arr[close_idx[1]],arr[close_idx[2]]);
}
/*
�������� ����
2470 �ο�� ������ ��ȭ ����
�ع��� �������� �����ϴ�.
k�� 0���� n-1���� �������Ѽ� -arr[k] �� ��������� l��r�� �������ͷ� ã���� �ȴ�.
*/ 
