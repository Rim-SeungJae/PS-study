#include<cstdio>
#include<string>

using namespace std;

struct Trie{
	Trie * child[26];
	bool is_word;
};

void insert(char * str, Trie * cur)
{
	if(str[0] == 0)
	{
		cur->is_word = true;
		return;
	}
	int idx = str[0] - 'a';
	if(cur->child[idx] == nullptr) cur->child[idx] = new Trie();
	insert(str+1,cur->child[idx]);
}

bool find(char * str, Trie * cur)
{
	if(str[0] == 0)
	{
		if(cur->is_word)return true;
		else return false;
	}
	int idx = str[0] - 'a';
	if(cur->child[idx] == nullptr) return false;
	return find(str+1, cur->child[idx]);
}

int main()
{
	int n,m,cnt=0;
	Trie * trie = new Trie();
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		char tmp[510];
		scanf("%s",tmp);
		insert(tmp,trie);
	}
	for(int i=0;i<m;i++)
	{
		char tmp[510];
		scanf("%s",tmp);
		if(find(tmp,trie)) cnt++;
	}
	printf("%d",cnt);
}
