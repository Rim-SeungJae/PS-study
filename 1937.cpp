#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{

    int n,arr[501][501];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int in[250001] = {0,};
    vector<vector<int>> graph(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-1>=0 && arr[i-1][j] > arr[i][j])
            {
                graph[i*n+j].push_back((i-1)*n+j);
                in[(i-1)*n+j]++;
            }
            if(j-1>=0 && arr[i][j-1] > arr[i][j])
            {
                graph[i*n+j].push_back(i*n+j-1);
                in[i*n+j-1]++;
            }
            if(i+1<n && arr[i+1][j] > arr[i][j])
            {
                graph[i*n+j].push_back((i+1)*n+j);
                in[(i+1)*n+j]++;
            }
            if(j+1<n && arr[i][j+1] > arr[i][j])
            {
                graph[i*n+j].push_back(i*n+j+1);
                in[i*n+j+1]++;
            }
        }
    }
}