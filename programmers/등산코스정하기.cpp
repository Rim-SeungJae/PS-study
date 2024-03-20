#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2);
    // init
    vector<vector<pair<int,int>>> g(n+1,vector<pair<int,int>>());
    vector<int> inten;
    for(int i=0;i<paths.size();i++)
    {
        int s = paths[i][0], e = paths[i][1], len = paths[i][2];
        g[s].push_back(make_pair(e,len));
        g[e].push_back(make_pair(s,len));
        inten.push_back(len);
    }
    vector<bool> isgate(n+1,0);
    for(int i=0;i<gates.size();i++)
    {
        isgate[gates[i]] = true;
    }
    vector<bool> issummit(n+1,0);
    for(int i=0;i<summits.size();i++)
    {
        issummit[summits[i]] = true;
    }

    // solve
    sort(inten.begin(),inten.end());
    inten.erase(unique(inten.begin(),inten.end()),inten.end());
    int l=0,r=inten.size()-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        int bound = inten[mid];
        queue<int> q;
        bool visited[50005] = {0,};
        for(int i=0;i<gates.size();i++)
        {
            q.push(gates[i]);
            visited[gates[i]] = true;
        }
        int summit_min = 2000000000;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int i=0;i<g[cur].size();i++)
            {
                int nxt = g[cur][i].first, w = g[cur][i].second;
                if(w<=bound && !isgate[nxt] && !visited[nxt])
                {
                    if(issummit[nxt] && summit_min > nxt)
                    {
                        summit_min = nxt;
                    }
                    if(!issummit[nxt])
                    {
                        visited[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        if(summit_min == 2000000000)
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
            answer[0] = summit_min;
            answer[1] = bound;
        }
    }
    
    return answer;
}