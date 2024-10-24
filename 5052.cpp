#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct Trie{
    int child[10];
    bool is_word;
    Trie()
    {
        memset(child,-1,sizeof(int)*10);
        is_word = false;
    }
};

vector<Trie> trie;

void insert(int cur,char * num,bool * check)
{
    if(num[0] == 0)
    {
        trie[cur].is_word = true;
        for(int i=0;i<10;i++)
        {
            if(trie[cur].child[i]!=-1) *check = false;
        }
        return;
    }
    int idx = num[0] - '0';
    if(trie[cur].child[idx] == -1)
    {
        trie[cur].child[idx] = trie.size();
        trie.emplace_back();
    }
    if(trie[cur].is_word) *check = false;
    insert(trie[cur].child[idx],num+1,check);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        int n;
        bool check = true;
        trie.clear();
        trie.emplace_back();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            char tmp[11];
            scanf("%s",&tmp);
            insert(0,tmp,&check);
        }
        if(check) printf("YES\n");
        else printf("NO\n");
    }
}