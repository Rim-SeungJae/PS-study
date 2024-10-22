#include<cstdio>

using namespace std;

int parent[1000001],h[1000001];

int find(int a)
{
    while(parent[a] != a) a = parent[a];
    return a;
}

void uni(int a,int b)
{
    a = find(a);
    b = find(b);
    if(h[a] > h[b])
    {
        parent[b] = a;
    }
    else if(h[a] == h[b])
    {
        parent[b] = a;
        h[a] += 1;
    }
    else{
        parent[a] = b;
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
    }
    for(int i=0;i<m;i++)
    {
        int cmd,a,b;
        scanf("%d %d %d",&cmd,&a,&b);
        if(cmd == 0)
        {
            uni(a,b);
        }
        else{
            a = find(a);
            b = find(b);
            if(a==b) printf("YES\n");
            else printf("NO\n");
        }
    }

}