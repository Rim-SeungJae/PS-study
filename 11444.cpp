#include<cstdio>
#include<algorithm>
using namespace std;

void mat_mult(long long a[][2],long long b[][2])
{
	int tmp[2][2]={0,};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				tmp[i][j] += (a[i][k] * b[k][j])%1000000007;
				tmp[i][j] %= 1000000007;
			}
		}
	}
	copy(&tmp[0][0],&tmp[1][2],&a[0][0]);
}

int main()
{
	long long n, res[2][2] = {{1,1},{1,0}}, iden[2][2] = {{1,1},{1,0}};
	scanf("%lld",&n);
	while(n)
	{
		if(n&1 != 0) mat_mult(res,iden);
		mat_mult(iden,iden);
		n >>= 1;
		
	}
	printf("%lld",res[1][1]);
}
