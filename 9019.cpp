#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        queue<pair<int,string>> q;
        bool visited[10000] = {0,};
        int a,b;
        scanf("%d %d",&a,&b);
        q.push(make_pair(a,string("")));
        visited[a] = true;
        while(!q.empty())
        {
            int cur = q.front().first;
            string cmd = q.front().second;
            q.pop();
            if(cur == b)
            {
                printf("%s\n",cmd.c_str());
                break;
            }
            if(!visited[(cur*2)%10000])
            {
                visited[(cur*2)%10000] = true;
                q.push(make_pair((cur*2)%10000,cmd+"D"));
            }
            if(!visited[(cur+9999)%10000])
            {
                q.push(make_pair((cur+9999)%10000,cmd+"S"));
                visited[(cur+9999)%10000] = true;
            }
            if(!visited[(cur*10)%10000 + (cur/1000)])
            {
                visited[(cur*10)%10000 + (cur/1000)] = true;
                q.push(make_pair((cur*10)%10000 + (cur/1000),cmd+"L"));
            }
            if(!visited[(cur/10) + (cur%10)*1000])
            {
                visited[(cur/10) + (cur%10)*1000] = true;
                q.push(make_pair((cur/10) + (cur%10)*1000,cmd+"R"));
            }
            
        }
    }
}