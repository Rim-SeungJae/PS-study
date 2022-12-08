#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int main()
{
	int mask = 0,m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		string cmd;
		char tmp[10];
		int n;
		scanf(" %s ",tmp);
		cmd = tmp;
		if(cmd == "add")
		{
			scanf("%d",&n);
			mask |= (1 << n);
		}
		else if(cmd == "remove")
		{
			scanf("%d",&n);
			mask &= ~(1 <<n);
		}
		else if(cmd == "check")
		{
			scanf("%d",&n);
			if((mask >> n)%2) printf("1\n");
			else printf("0\n"); 
		}
		else if(cmd == "toggle")
		{
			scanf("%d",&n);
			mask ^= (1 << n);
		}
		else if(cmd == "all")
		{
			mask = 2097150;
		}
		else if(cmd == "empty")
		{
			mask = 0;
		}
	}
} 
/*
비트마스크 기초
*/ 
