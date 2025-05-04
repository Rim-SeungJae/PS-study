#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
using ii=pair<int,int>;

int knapsack[1001][10001];
ii courses[1001];

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        courses[i].first = a;
        courses[i].second = b;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j-courses[i].second<0) knapsack[i][j] = knapsack[i-1][j];
            else{
                knapsack[i][j] = max(knapsack[i-1][j],courses[i].first + knapsack[i-1][j-courses[i].second]);
            }
        }
    }
    printf("%d",knapsack[k][n]);
}