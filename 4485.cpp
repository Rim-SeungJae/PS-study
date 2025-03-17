#include<cstdio>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

using iii = tuple<int,int,int>;

int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

bool InRange(int a,int b,int n)
{
    return a>=0 && b>=0 && a<n && b<n;
}

int main()
{
    int tc=1;
    while(true)
    {
        int n;
        scanf("%d",&n);
        if(n==0) break;
        int arr[126][126],dist[126][126];
        priority_queue<iii> pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        fill(&dist[0][0],&dist[125][126],2000000000);
        dist[0][0] = arr[0][0];
        pq.push(make_tuple(-arr[0][0],0,0));
        while(!pq.empty())
        {
            iii tmp = pq.top();
            pq.pop();
            int weight = -get<0>(tmp), x = get<1>(tmp), y = get<2>(tmp);
            if(weight != dist[x][y]) continue;
            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i],ny = y+dy[i];
                if(InRange(nx,ny,n) && dist[nx][ny] > weight + arr[nx][ny])
                {
                    dist[nx][ny] = weight + arr[nx][ny];
                    pq.push(make_tuple(-(weight+arr[nx][ny]),nx,ny));
                }
            }
            
        }
        printf("Problem %d: %d\n",tc,dist[n-1][n-1]);
        tc++;
    }
}