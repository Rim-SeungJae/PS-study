#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int cnt[30]={0,},n;
	vector<string> v;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string tmp;
		cin>>tmp;
		for(int j=0;j<tmp.length();j++)
		{
			cnt[tmp[j]-'A'] += pow(10,tmp.length()-j-1);
		}
	}
	sort(cnt,cnt+26,greater<int>());
	int result=0,num=9;
	for(int i=0;cnt[i]!=0;i++)
	{
		result+=num--*cnt[i];
	}
	cout<<result;
}
/*
그리디
골드4 치고 너무 쉬운데...
*/ 
