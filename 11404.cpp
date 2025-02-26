#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    vector<vector<int>> dist(n+1,vector<int>(n+1,100000000));
    for(int i=0;i<n;i++) dist[i][i] = 0;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(dist[a-1][b-1] > c )dist[a-1][b-1] = c;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(dist[i][j] == 100000000) printf("0 ");
            else printf("%d ",dist[i][j]);
        }
        printf("\n");
    }

}