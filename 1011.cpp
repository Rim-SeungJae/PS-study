#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	vector<int> x,y,arr;
	for(int i=0;i<t;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		x.push_back(a);
		y.push_back(b);
	}
	int j;
	for(int i=0;i<t;i++)
	{
		int n = y[i] - x[i];
		long long int an = 0;
		for(j=0;an < n;j++)
		{
		    an += (j+1)/2;
		}
		printf("%d\n",j-1);
	}
}
/*
백준 1011 
규칙성을 발견하는게 핵심
*/ 
