#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    vector<vector<int>> graph;
    graph.assign(n,vector<int>());
    deque<int> dq;
    unordered_set<int> s;
    int condition[200010]={0,},rcondition[200010]={0,};
    fill(condition,condition+200010,-1);
    fill(rcondition,rcondition+200010,-1);
    bool visited[200010]={0,},fake_visited[200010]={0,};
    bool tried[200010]={0,};
    for(int i=0;i<path.size();i++)
    {
        graph[path[i][0]].push_back(path[i][1]);
        graph[path[i][1]].push_back(path[i][0]);
    }
    for(int i=0;i<order.size();i++)
    {
        condition[order[i][1]] = order[i][0];
        rcondition[order[i][0]] = order[i][1];
    }
    dq.push_back(0);
    fake_visited[0] = true;
    int cnt=0;
    while(!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();
        //printf("%d\n",cur);
        if(visited[cur]) continue;
        if(condition[cur]!=-1 && !visited[condition[cur]])
        {
            if(cnt==dq.size()+1)
            {
                answer = false;
                break;
            }
            else{
                cnt++;
                dq.push_back(cur);
                continue;
            }
        }
        visited[cur] = true;
        cnt = 0;
        if(rcondition[cur]!=-1 && s.find(rcondition[cur])!=s.end())
        {
            fake_visited[rcondition[cur]] = true;
            dq.push_front(rcondition[cur]);
            //printf("skip\n");
        }
        for(int i=0;i<graph[cur].size();i++)
        {
            if(!fake_visited[graph[cur][i]])
            {
                fake_visited[graph[cur][i]] = true;
                if(condition[graph[cur][i]]==-1 || visited[condition[graph[cur][i]]])
                {
                    dq.push_front(graph[cur][i]);
                    s.insert(graph[cur][i]);
                }
                else{
                    dq.push_back(graph[cur][i]);
                    s.insert(graph[cur][i]);
                }
            }
        }
    }
    return answer;
}
/*
프로그래머스 첫 4단계 solve!
*/ 
