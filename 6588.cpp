#include <cstdio>
int arr[1000010] = {0,};
int main()
{
	arr[0] = arr[1] = 1;
	for(int i=0;i * i<1000010;i++)
	{
		if(arr[i] != 0) continue;
		for(int j=i*i;j<1000010;j+=i)
		{
			arr[j] = 1;
		}
	}
	
	while(true)
	{
		int n;
		scanf("%d",&n);
		if(n == 0) break;
		for(int i=3;i<n;i++)
		{
			int a=i,b=n-i;
			if(arr[a] == 0 && arr[b] == 0 && a%2 == 1 && b%2 == 1)
			{
				printf("%d = %d + %d\n",n,a,b);
				break;
			}
		}
	}
 } 
/*
에라토스테네스의 채 응용
*/ 
