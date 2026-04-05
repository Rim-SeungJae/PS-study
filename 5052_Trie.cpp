#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Trie{
    int child[10];
    bool isLast;
    Trie()
    {
        for(int i=0;i<10;i++) child[i] = -1;
        isLast = false;
    }
};

vector<Trie> trie;

bool insert(char * word, int idx)
{
    if(word[0] == 0)
    {
        trie[idx].isLast = true;
        for(int i=0;i<10;i++)
        {
            if(trie[idx].child[i]!=-1) return false;
        }
        return true;
    }
    if(trie[idx].isLast) return false;
    int cur = word[0] - '0';
    if(trie[idx].child[cur] == -1)
    {
        trie.emplace_back();
        trie[idx].child[cur] = trie.size()-1;
    }
    return insert(word+1,trie[idx].child[cur]);
}

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        trie.clear();
        trie.emplace_back();
        int n;
        bool ans = true;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++)
        {
            char phone[11];
            scanf("%s",&phone);
            ans &= insert(phone,0);
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
}