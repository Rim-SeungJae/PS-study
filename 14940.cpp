#include<cstdio>
#include<queue>

using namespace std;

bool inRange(int a,int limit)
{
    return a>=0 && a<limit;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    vector<vector<int>> map(n,vector<int>(m,0));


    pair<int,int> target;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j] == 2) target = make_pair(i,j);
        }
    }

    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<vector<int>> dist(n,vector<int>(m,0));
    q.push(target);
    visited[target.first][target.second] = true;

    while(!q.empty())
    {
        int x,y;
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(inRange(x-1,n) && !visited[x-1][y] && map[x-1][y])
        {
            q.push(make_pair(x-1,y));
            visited[x-1][y] = true;
            dist[x-1][y] = dist[x][y] + 1;
        }
        if(inRange(x+1,n) && !visited[x+1][y] && map[x+1][y])
        {
            q.push(make_pair(x+1,y));
            visited[x+1][y] = true;
            dist[x+1][y] = dist[x][y] + 1;
        }
        if(inRange(y-1,m) && !visited[x][y-1] && map[x][y-1])
        {
            q.push(make_pair(x,y-1));
            visited[x][y-1] = true;
            dist[x][y-1] = dist[x][y] + 1;
        }
        if(inRange(y+1,m) && !visited[x][y+1]&& map[x][y+1])
        {
            q.push(make_pair(x,y+1));
            visited[x][y+1] = true;
            dist[x][y+1] = dist[x][y] + 1;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[i][j] == 0 && map[i][j] == 1) printf("-1 ");
            else printf("%d ",dist[i][j]);
        }
        printf("\n");
    }

}