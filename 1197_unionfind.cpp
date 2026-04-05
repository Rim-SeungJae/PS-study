#include<cstdio>
#include<queue>
#include<tuple>

using namespace std;

int p[10001];

int find(int a)
{
    if(p[a] == a) return a;
    else return p[a] = find(p[a]);
}

void uni(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a != b)
    p[a] = b;
}

int main()
{
    priority_queue<tuple<int,int,int>> pq;
    int v,e;
    scanf("%d %d",&v,&e);
    for(int i=1;i<=v;i++) p[i] = i;
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        pq.push({-c,a,b});
    }
    int ans = 0;
    for(int i=0;i<v-1;i++)
    {
        int a,b,c;
        c = -get<0>(pq.top());
        a = get<1>(pq.top());
        b = get<2>(pq.top());
        pq.pop();
        if(find(a) != find(b))
        {
            ans += c;
            uni(a,b);
        }
        else
        {
            i--;
        }
    }
    printf("%d",ans);
}