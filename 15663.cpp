#include<cstdio>
#include<vector>
#include<set>

using namespace std;

set<vector<int>> sol;
vector<int> num;
int n,m;

void bt(vector<int> s, vector<bool> visited)
{
    if(s.size() == m)
    {
        sol.insert(s);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]) continue;
        s.push_back(num[i]);
        visited[i] = true;
        bt(s,visited);
        s.erase(s.end()-1);
        visited[i] = false;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    num.assign(n,0);
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    bt(vector<int>(),vector<bool>(n,0));
    for(auto iter=sol.begin();iter!=sol.end();iter++)
    {
        for(int j=0;j<(*iter).size();j++)
        {
            printf("%d ",(*iter)[j]);
        }
        printf("\n");
    }
}