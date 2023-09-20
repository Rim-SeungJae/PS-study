#include<cstdio>
using namespace std;

int mem[3][1010], n, arr[3][1010],res = 1000100;

int bt(int idx,int prev)
{
	if(idx > n)
	{
		return 0;
	}
	int min = 1000100;
	for(int i=0;i<3;i++)
	{
		if(i == prev) continue;
		if(mem[i][idx]!=0)
		{
			if(mem[i][idx] + arr[i][idx] < min) min = mem[i][idx] + arr[i][idx];
		}
		else
		{
			int tmp = bt(idx+1,i);
			mem[i][idx] = tmp;
			if(tmp + arr[i][idx] < min) min = tmp + arr[i][idx];
		}
	}
	//printf("%d %d %d\n",idx,prev,min);
	return min;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&arr[0][i],&arr[1][i],&arr[2][i]);
	}
	printf("%d",bt(0,-1));
}
/*
´ÙÀÌ³ª¹Í
*/ 
