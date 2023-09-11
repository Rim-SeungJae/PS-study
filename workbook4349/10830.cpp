#include<cstdio>
#include<algorithm>
using namespace std;

int res[7][7],mat[7][7];

void mat_mult(int mat1[][7], int mat2[][7], int size)
{
	int mult[7][7] = {0,};
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			for(int k=0;k<size;k++)
			{
				mult[i][j] += (mat1[i][k] * mat2[k][j])%1000;
				mult[i][j] %= 1000;
			}
		}
	}
	copy(&mult[0][0],&mult[size-1][size],&mat1[0][0]);
}


int main()
{
	int n;
	long long b;
	scanf("%d %lld",&n,&b);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		res[i][i] = 1;
	}
	while(b)
	{
		if(b%2==1)
		{
			mat_mult(res,mat,n);
		}
		mat_mult(mat,mat,n);
		b>>=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
}
/*
topic : 분할정복을 이용한 거듭제곱
def fpow(C, n):

	res = 1

	while n:

		if n & 1:

			res *= C

		C *= C;

		n >> 1
	return res 
*/
