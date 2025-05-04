#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>> tree;

int CountLeaf(int cur,int del)
{
    if(cur == del) return 0;
    int sum = 0;
    for(int i=0;i<tree[cur].size();i++)
    {
        sum+=CountLeaf(tree[cur][i],del);
    }
    if(sum == 0) return 1;
    return sum;
}

int main()
{
    int n;
    scanf("%d",&n);
    tree.assign(n,vector<int>());
    int root;
    for(int i=0;i<n;i++)
    {
        int parent;
        scanf("%d",&parent);
        if(parent!=-1) tree[parent].push_back(i);
        else root = i;
    }
    int del;
    scanf("%d",&del);
    printf("%d",CountLeaf(root,del));
}