#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int parent[100001];

int find(int a)
{
    if(parent[a] != a) return parent[a] = find(parent[a]);
    return a;
}

void uni(int a,int b)
{
    parent[b] = a;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<pair<int,int>>> tree(n+1,vector<pair<int,int>>());
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        pq.push(make_pair(-c,make_pair(a,b)));
    }
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
    }
    int cnt=0,max = 0,total = 0;
    while(cnt<n-1)
    {
        int a,b,c;
        c = -pq.top().first;
        b = pq.top().second.second;
        a = pq.top().second.first;
        pq.pop();
        b = find(b);
        a = find(a);
        if(a == b) continue;
        tree[a].push_back(make_pair(b,c));
        tree[b].push_back(make_pair(a,c));
        uni(a,b);
        cnt++;
        if(c>max) max = c;
        total += c;
    }
    printf("%d",total-max);
}