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
    if(a == b) return;
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
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(tmp) uni(i,j);
        }
    }
    int cur;
    scanf("%d",&cur);
    cur--;
    cur = find(cur);
    for(int i=1;i<m;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        tmp--;
        tmp = find(tmp);
        if(tmp != cur)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}