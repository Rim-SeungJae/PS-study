#include<iostream>
#include<string>

using namespace std;

int total = 0;

struct Trie{
	Trie * child[128];
	int cnt=0;
};

void insert(const char * str,Trie * cur)
{
	if(str[0] == 0)
	{
		cur->cnt = (cur->cnt)+1;
		total++;
		return;
	}
	if(cur->child[str[0]] == nullptr) cur->child[str[0]] = new Trie();
	insert(str+1,cur->child[str[0]]);
}

void print_p(string str,Trie * cur)
{
	if(cur->cnt>0) printf("%s %.4lf\n",str.c_str(),(double)cur->cnt/total*100);
	for(int i=0;i<128;i++)
	{
		if(cur->child[i] != nullptr)
		{
			string tmp = str;
			tmp.append(1,i);
			print_p(tmp,cur->child[i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string tmp;
    Trie * trie = new Trie();
    while(getline(cin,tmp))
    {
    	insert(tmp.c_str(),trie);
	}
	print_p(string(""),trie);
}
