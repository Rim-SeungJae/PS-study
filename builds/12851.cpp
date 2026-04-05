#include<cstdio>
#include<queue>

using namespace std;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    queue<int> q;
    q.push(n);
    vector<int> visited(200001,false);
    visited[n] = 1;

    int cnt = 0;
    int time = 0;

    while(!q.empty())
    {
        int size = q.size();
        bool isFound = false;
        time++;
        for(int i=0;i<size;i++)
        {
            int cur = q.front();

            q.pop();
            if(cur == k)
            {
                isFound = true;
                cnt++;
            }

            if(cur-1>=0 && (!visited[cur-1] || visited[cur-1] == time))
            {
                q.push(cur-1);
                visited[cur-1] = time;
                
            }
            if(cur+1<=100000 && (!visited[cur+1] || visited[cur+1] == time))
            {
                q.push(cur+1);
                visited[cur+1] = time;
            }
            if(cur*2<=200000 && (!visited[cur*2] || visited[cur*2] ==time))
            {
                q.push(cur*2);
                visited[cur*2] = time;
            }
        }
        if(isFound) break;
    }

    printf("%d\n%d",time-1,cnt);
}