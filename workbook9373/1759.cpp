#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
char arr[20];

void bt(int l, int c,vector<int> v)
{
	if(v.size() == l)
	{
		int vowels=0, consonants=0;
		for(int i=0;i<v.size();i++)
		{
			switch(arr[v[i]])
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vowels++;
					break;
				default:
					consonants++;
					break;
			}
		}
		if(!(vowels>=1 && consonants>=2)) return;
		for(int i=0;i<v.size();i++)
		{
			printf("%c",arr[v[i]]);
		}
		printf("\n");
		return;
	}
	else if(!v.empty() && v.back()==c-1) return;
	int i = 0;
	if(!v.empty()) i = v.back()+1;
	for(;i<c;i++)
	{
		v.push_back(i);
		bt(l,c,v);
		v.pop_back();
	}
}

int main()
{
	int l,c;
	scanf("%d %d",&l,&c);
	for(int i=0;i<c;i++)
	{
		scanf(" %c",&arr[i]);
	}
	sort(arr,arr+c);
	vector<int> v;
	bt(l,c,v);
 } 
