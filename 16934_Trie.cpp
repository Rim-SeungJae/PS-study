#include<cstdio>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

struct Trie{
    int child[26];
    int is_word;
    Trie()
    {
        memset(child,-1,sizeof(int) * 26);
        is_word = 0;
    }
};

vector<Trie> trie;

int insert(int cur,char * str,int * nn)
{
    if(str[0] == 0)
    {
        return ++(trie[cur].is_word);
    }
    int nxt = str[0] - 'a';
    if(trie[cur].child[nxt] == -1)
    {
        trie[cur].child[nxt] = trie.size();
        trie.emplace_back();
        return insert(trie[cur].child[nxt],str+1,nn);
    }
    (*nn) = (*nn) + 1;
    return insert(trie[cur].child[nxt],str+1,nn);
}

int main()
{
    int n;
    trie.emplace_back();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char tmp[11];
        int nn=0;
        scanf("%s",tmp);
        int cnt = insert(0,tmp,&nn);
        string nickname;
        if(nn == strlen(tmp))
        {
            nickname = string(tmp);
            if(cnt>1) nickname.append(to_string(cnt));
        }
        else{
            nickname = string(tmp);
            nickname = nickname.substr(0,nn+1);
        }
        printf("%s\n",nickname.c_str());
    }
}