#include<cstdio>
#include<set>
using namespace std;
int main()
{
	int n,first,size=0;
	multiset<int> s;
	scanf("%d",&n);
	scanf("%d",&first);
	s.insert(first);
	size++;
	auto mid = s.begin();
	printf("%d\n",*mid);
	for(int i=1;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		s.insert(tmp);
		if(*mid > tmp && size%2 != 0)
		{
			--mid;
		}
		else if(*mid <= tmp && size%2 == 0)
		{
			++mid;
		}
		printf("%d\n",*mid);
		size++;
	}
}
/*
set(binary search tree)ÀÇ È°¿ë
*/ 
