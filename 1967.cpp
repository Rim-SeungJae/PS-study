#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using ii = pair<int,int>;

vector<vector<ii>> tree;
int rad = 0;

int getRad(int cur)
{
    vector<int> legs;
    for(int i=0;i < tree[cur].size();i++)
    {
        legs.push_back(getRad(tree[cur][i].first) + tree[cur][i].second);
    }
    while(legs.size()<2) legs.push_back(0);
    sort(legs.begin(),legs.end(),greater<int>());
    if(legs[0] + legs[1] > rad) rad = legs[0] + legs[1];
    return legs[0];
}

int main()
{
    int n;
    scanf("%d",&n);

    tree = vector<vector<ii>>(n+1,vector<ii>());

    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        tree[a].push_back(make_pair(b,c));
    }

    getRad(1);

    printf("%d",rad);
}