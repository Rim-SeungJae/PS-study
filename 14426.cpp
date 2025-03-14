#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct Trie
{
    int child[26];
    bool isFin;

    Trie()
    {
        fill(child,child+26,-1);
        isFin = false;
    }
};

vector<Trie> trie;

void insert(char * word,int cur)
{
    int target = word[0] - 'a';
    if(word[0] == 0)
    {
        trie[cur].isFin = true;
        return;
    }
    if(trie[cur].child[target] == -1)
    {
        trie[cur].child[target] = trie.size();
        trie.emplace_back();
    }
    insert(word+1,trie[cur].child[target]);
}

bool Find(char * word,int cur)
{
    int target = word[0] - 'a';
    if(word[0] == 0)
    {
        return true;
    }
    if(trie[cur].child[target] == -1)
    {
        return false;
    }
    else{
        return Find(word+1,trie[cur].child[target]);
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    trie.emplace_back();

    for(int i=0;i<n;i++)
    {
        char tmp[500];
        scanf("\n%s",tmp);
        insert(tmp,0);
    }

    int ans = 0;
    for(int i=0;i<m;i++)
    {
        char tmp[500];
        scanf("\n%s",tmp);
        ans += Find(tmp,0);
    }
    printf("%d",ans);
}