#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<tuple>
#include<unordered_map>
#include<string>

using namespace std;
using ii=pair<int,int>;

unordered_map<char,int> digit2idx;
const char digits[53] = {
    '\\', '!', '#', '$', '%', '&', '\'', '(', ')', '-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
    'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '^', '_', '`', '{', '}', '~'
  };

typedef struct node{
    int nxt[53];
    bool isFin;
    node()
    {
        for(int i=0;i<53;i++) nxt[i] = -1;
        isFin = false;
    }
}Node;

vector<Node> Trie;

void insert(char * str, int idx)
{
    if(str[0] == 0)
    {
        Trie[idx].isFin = true;
        return;
    }
    char cur = digit2idx[str[0]];
    if(cur == 0)
    {
        Trie[idx].isFin = true;
    }
    if(Trie[idx].nxt[cur] == -1)
    {
        Trie[idx].nxt[cur] = Trie.size();
        Trie.emplace_back();
    }
    insert(str+1,Trie[idx].nxt[cur]);
}

void print(int idx,int blank,string word)
{
    if(Trie[idx].isFin)
    {
        for(int j=0;j<blank;j++) printf(" ");
        printf("%s\n",word.c_str());
    }
    for(int i=0;i<53;i++)
    {
        if(Trie[idx].nxt[i] != -1)
        {
            if(i==0)
            {
                print(Trie[idx].nxt[i],blank+1,string(""));
            }
            else{
                print(Trie[idx].nxt[i],blank,word+digits[i]);
            }
        }
    }
}

int main()
{
    for(int i=0;i<53;i++)
    {
        digit2idx[digits[i]] = i;
    }
    Trie.emplace_back();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char tmp[82];
        scanf("\n%s",tmp);
        insert(tmp,0);
    }
    print(0,0,string(""));
    return 0;
}