#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

using ii = pair<int,int>;

vector<vector<ii>> tree;
vector<bool> visited;

int maxRadi;

int FindRadi(int cur)
{
    vector<int> legLength;
    for(int i=0;i<tree[cur].size();i++)
    {
        if(!visited[tree[cur][i].first])
        {
            visited[tree[cur][i].first] = true;
            legLength.push_back(tree[cur][i].second + FindRadi(tree[cur][i].first));
        }
    }
    legLength.push_back(0);
    legLength.push_back(0);
    sort(legLength.begin(),legLength.end(),greater<int>());
    if(legLength[0] + legLength[1] > maxRadi) maxRadi = legLength[0]+legLength[1];
    return legLength[0];
}

int main()
{
    int v;
    scanf("%d",&v);
    tree.assign(v+1,vector<ii>());
    visited.assign(v+1,false);
    for(int i=1;i<=v;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        int a,b;
        while(scanf("%d",&a) && a!=-1)
        {
            scanf("%d",&b);
            tree[tmp].push_back(make_pair(a,b));
        }
    }
    visited[1] = true;
    FindRadi(1);
    printf("%d",maxRadi);
}