#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
using ii=pair<int,int>;

int parent[200001];

int find(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

int main()
{
    while(true)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        if(m == 0 && n == 0) break;
        priority_queue<tuple<int,int,int>> pq;
        for(int i=0;i<m;i++) parent[i] = i;
        for(int i=0;i<n;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            pq.push(make_tuple(-z,x,y));
        }
        int sum = 0;
        while(!pq.empty())
        {
            int w = -get<0>(pq.top()), b = get<1>(pq.top()), a = get<2>(pq.top());
            pq.pop();
            a = find(a);
            b = find(b);
            if(a != b)
            {
                parent[a] = b;
            }
            else{
                sum+=w;
            }
        }
        printf("%d\n",sum);
    }
}