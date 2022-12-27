#include<cstdio>

int arr[210],dur[210];

void print(int n,int in,int out)
{
	printf("%d %d\n",in,out);
	for(int i=0;i<2*n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	for(int i=0;i<2*n;i++)
	{
		printf("%d ",dur[i]);
	}
	printf("\n\n");
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<2*n;i++)
	{
		scanf("%d",&dur[i]);
	}
	int cnt=0,broken = 0,in = 0,out = n-1;
	while(true)
	{
		cnt++;
		// 1
		in = (in+2*n-1)%(2*n);
		out = (out+2*n-1)%(2*n);
		if(arr[out] == 1)
		{
			arr[out] = 0;
		}
		// 2
		for(int i=out;i!=in;i = (i+2*n-1)%(2*n))
		{
			if(arr[i] == 1 && arr[(i+1)%(2*n)] == 0 && dur[(i+1)%(2*n)]>0)
			{
				arr[(i+1)%(2*n)] = 1;
				arr[i] = 0;
				dur[(i+1)%(2*n)] = dur[(i+1)%(2*n)] - 1;
				if(dur[(i+1)%(2*n)] == 0) broken++;
			}
			if(arr[out] == 1)
			{
				arr[out] = 0;
			}
		}
		// 3
		if(dur[in]>0)
		{
			dur[in] = dur[in] - 1;
			if(dur[in] == 0) broken++;
			arr[in] = 1;
		}
		// 4
		if(broken >= k) break;
	}
	printf("%d",cnt);
}
/*
구현
배열의 인덱스를 활용한 풀이 
