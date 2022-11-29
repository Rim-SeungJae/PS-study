#include<iostream>
#include<cstdio>
int arr[1001000];

using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	arr[1] = 1;
	for(int i=2;i*i<=m;i++)
	{
	    if(arr[i]!=0) continue;
	    for(int j=i*i;j<=m;j+=i)
	    {
	        arr[j] = 1;
	    }
	}
	for(int i=n;i<=m;i++)
	{
	    if(arr[i]==0) printf("%d\n",i);
	}
}
/*
백준 1929
에라토스테네스의 채 응용
*/ 
