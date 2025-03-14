#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>

using namespace std;
using ii = pair<int,int>;

vector<int> parent;

void Union(int a,int b)
{
    parent[b] = a;
}

int Find(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;i++) parent.push_back(i);
    priority_queue<tuple<int,int,int>> pq;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        pq.push(make_tuple(-c,a-1,b-1));
    }
    int ans = 0;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        c = -get<0>(pq.top());
        a = get<1>(pq.top());
        b = get<2>(pq.top());
        pq.pop();

        a = Find(a);
        b = Find(b);
        if(a == b)
        {
            i--;
            continue;
        }
        else
        {
            Union(a,b);
            ans += c;
        }
    }
    printf("%d",ans);

}