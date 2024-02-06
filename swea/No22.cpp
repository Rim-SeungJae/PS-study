#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int dist[50005],rdist[50005];
vector<vector<pair<int,int>>> graph;
vector<vector<pair<int,int>>> rgraph;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n,m,x;
        cin >> n >> m >> x;
        graph.assign(n+1,vector<pair<int,int>>());
        rgraph.assign(n+1,vector<pair<int,int>>());
        fill(&dist[0],&dist[n+1],2000000000);
        fill(&rdist[0],&rdist[n+1],2000000000);
        for(int i=0;i<m;i++)
        {
            int s,e,t;
            cin >> s >> e >> t;
            graph[s].push_back(make_pair(e,t));
            rgraph[e].push_back(make_pair(s,t));
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,x));
        dist[x] = 0;
        while(!pq.empty())
        {
            int d,cur;
            d = pq.top().first;
            cur = pq.top().second;
            pq.pop();
            if(d != dist[cur]) continue;
            for(int i=0;i<graph[cur].size();i++)
            {
                if(d + graph[cur][i].second < dist[graph[cur][i].first])
                {
                    dist[graph[cur][i].first] = d + graph[cur][i].second;
                    pq.push(make_pair(d + graph[cur][i].second,graph[cur][i].first));
                }
            }
        }
        pq.push(make_pair(0,x));
        rdist[x] = 0;
        while(!pq.empty())
        {
            int d,cur;
            d = pq.top().first;
            cur = pq.top().second;
            pq.pop();
            if(d != rdist[cur]) continue;
            for(int i=0;i<rgraph[cur].size();i++)
            {
                if(d + rgraph[cur][i].second < rdist[rgraph[cur][i].first])
                {
                    rdist[rgraph[cur][i].first] = d + rgraph[cur][i].second;
                    pq.push(make_pair(d + rgraph[cur][i].second,rgraph[cur][i].first));
                }
            }
        }
        int max = 0;
        for(int i=1;i<=n;i++)
        {
            if(max < dist[i] + rdist[i]) max = dist[i]+rdist[i];
        }
        cout << '#' << test_case << ' ' << max << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}