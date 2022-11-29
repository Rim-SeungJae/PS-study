#include<iostream>

using namespace std;
int main()
{
	int arr[1100] = {0,},n,sum=0;
	arr[1] = 1;
	for(int i=2;i*i<=1000;i++)
	{
	    if(arr[i]!=0) continue;
	    for(int j=i*i;j<=1000;j+=i)
	    {
	        arr[j] = 1;
	    }
	}
	cin >> n;
	for(int i=0;i<n;i++)
	{
	    int t;
	    cin >> t;
	    sum+=!arr[t];
	}
	cout << sum;
}
/*
백준 1978
에라토스테네스의 채 응용
*/ 
