#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
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
        int n,m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> graph;
        graph.assign(n+1,vector<pair<int,int>>());
        for(int i=0;i<m;i++)
        {
            int a,b,w;
            cin >> a >> b >> w;
            graph[a].push_back(make_pair(b,w));
            graph[b].push_back(make_pair(a,w));
        }
        long long dist[22];
        int prev[22];
        fill(&dist[0],&dist[22],20000000002);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push(make_pair(0,1));
        dist[1] = 0;

        while(!pq.empty())
        {
            long long d = pq.top().first, cur = pq.top().second;
            pq.pop();
            if(dist[cur] != d) continue;
            for(int i=0;i<graph[cur].size();i++)
            {
                if(d + graph[cur][i].second < dist[graph[cur][i].first])
                {
                    dist[graph[cur][i].first] = d + graph[cur][i].second;
                    prev[graph[cur][i].first] = cur;
                    pq.push(make_pair(d + graph[cur][i].second,graph[cur][i].first));
                }
            }
        }
        long long result = 0;
        for(int i=2;i<=n;i++)
        {
            result += dist[i] - dist[prev[i]];
        }
        cout << '#' << test_case << ' ' << result << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}