#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    sort(v.begin(),v.end());
    unique(v.begin(),v.end());

    queue<vector<int>> q;

    for(int i=0;i<v.size();i++)
    {
        q.push(vector<int>({v[i]}));
    }

    set<vector<int>> s;

    while(!q.empty())
    {
        vector<int> cur = q.front();
        q.pop();
        if(cur.size() == m)
        {
            s.insert(cur);
            continue;
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i] >= cur.back())
            {
                cur.push_back(v[i]);
                q.push(cur);
                cur.pop_back();
            }
        }
    }

    for(auto it = s.begin();it!=s.end();it++)
    {
        vector<int> cur = *it;
        for(int i=0;i<cur.size();i++)
        {
            printf("%d ",cur[i]);
        }
        printf("\n");
    }

    return 0;
}