#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using ii = pair<int,int>;

struct Trie
{
    int nxt[26];
    bool isFin;
    int childCount;
    Trie()
    {
        fill(nxt,&nxt[26],-1);
        isFin = false;
        childCount = 0;
    }
};

vector<Trie> trie;

void insert(char * str, int cur)
{
    if(str[0] == 0)
    {
        trie[cur].isFin = true;
        return;
    }
    int target = str[0] - 'a';
    if(trie[cur].nxt[target] == -1)
    {
        trie[cur].nxt[target] = trie.size();
        trie.emplace_back();
        trie[cur].childCount++;
    }
    insert(str+1,trie[cur].nxt[target]);
}

int cnt = 0;

void search(int cur, int localCnt)
{
    if(trie[cur].isFin) cnt += localCnt;
    if(cur == 0 || trie[cur].isFin || trie[cur].childCount>1) localCnt++;
    for(int i=0;i<26;i++)
    {
        if(trie[cur].nxt[i] != -1)
        {
            search(trie[cur].nxt[i],localCnt);
        }
    }
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        trie.clear();
        trie.emplace_back();
        for(int i=0;i<n;i++)
        {
            char tmp[81];
            scanf("%s",tmp);
            insert(tmp,0);
        }
        cnt = 0;
        search(0,0);
        printf("%.2f\n",(double)cnt/n);
    }
}