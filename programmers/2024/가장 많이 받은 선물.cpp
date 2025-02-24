#include <string>
#include <vector>
#include<unordered_map>
#include<iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0, n = friends.size();
    unordered_map<string,int> name2idx;
    vector<vector<int>> graph(n,vector<int>(n,0));
    vector<int> point(n,0);
    vector<int> nextMonth(n,0);
    for(int i=0;i<n;i++)
    {
        name2idx.insert(make_pair(friends[i],i));
    }
    for(int i=0;i<gifts.size();i++)
    {
        int loc = gifts[i].find(" ");
        string sender,receiver;
        sender = gifts[i].substr(0,loc);
        receiver = gifts[i].substr(loc+1,gifts[i].size());
        int sidx,ridx;
        sidx = name2idx.at(sender);
        ridx = name2idx.at(receiver);
        graph[sidx][ridx]++;
        point[sidx]++;
        point[ridx]--;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(graph[i][j] > graph[j][i])
            {
                nextMonth[i]++;
            }
            else if(graph[i][j] == graph[j][i])
            {
                if(point[i]>point[j]) nextMonth[i]++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(answer < nextMonth[i]) answer = nextMonth[i];
    }
    return answer;
}