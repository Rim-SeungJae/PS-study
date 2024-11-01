#include<cstdio>
#include<vector>

using namespace std;

int parent[500001];

int find(int a)
{
    if(parent[a] != a) return parent[a] = find(parent[a]);
    return parent[a];
}

void uni(int a,int b)
{
    parent[a] = parent[b];
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
    }
    int ans = 0;
    for(int i=0;i<m;i++)
    {
        int src,dst;
        scanf("%d %d",&src,&dst);

        src = find(src);
        dst = find(dst);

        if(src == dst)
        {
            printf("%d",i+1);
            return 0;
        }
        else uni(src,dst);
    }
    printf("0");
}
