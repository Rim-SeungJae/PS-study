#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
    queue<pair<int,int>> q;
    int x;
    scanf("%d",&x);
    vector<int> visited(x+1,0);
    visited[x] = true;

    q.push(make_pair(x,-1));

    while(!q.empty())
    {
        int cur = q.front().first;
        q.pop();

        if(cur%2 == 0 && !visited[cur/2])
        {
            q.push(make_pair(cur/2,cur));
            visited[cur/2] = cur;
            if(cur/2 ==  1) break; 
        }
        if(cur%3 == 0 && !visited[cur/3])
        {
            q.push(make_pair(cur/3,cur));
            visited[cur/3] = cur;
            if(cur/3 == 1) break;
        }
        if(cur-1 && !visited[cur-1])
        {
            q.push(make_pair(cur-1,cur));
            visited[cur-1] = cur;
            if(cur-1 == 1) break;
        }

    }

    vector<int> trace;
    int tmp = 1;
    while(tmp != x)
    {
        trace.push_back(tmp);
        tmp = visited[tmp];
    }
    trace.push_back(x);
    printf("%d\n",trace.size()-1);

    reverse(trace.begin(),trace.end());

    for(int &a : trace) printf("%d ",a);

}