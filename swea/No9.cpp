#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

struct cmp{
    bool operator()(pair<double,int> a,pair<double,int> b)
    {
        return a.first > b.first;
    }
};

int main(int argc, char** argv)
{
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
        // get input
        int n;
        cin >> n;
        vector<pair<long long,long long>> islands;
        islands.assign(n,make_pair(-1,-1));
        for(int i=0;i<n;i++)
        {
            long long tmp;
            cin >> tmp;
            islands[i].first = tmp;
        }
        for(int i=0;i<n;i++)
        {
            long long tmp;
            cin >> tmp;
            islands[i].second = tmp;
        }
        double e;
        cin >> e;

        // kruskal init
        priority_queue<pair<double,int>,vector<pair<double,int>>,cmp> pq;
        vector<pair<int,int>> tunnel;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double value = e * ((islands[i].first - islands[j].first) * (islands[i].first - islands[j].first) + (islands[i].second - islands[j].second) * (islands[i].second - islands[j].second));
                pq.push(make_pair(value,tunnel.size()));
                tunnel.push_back(make_pair(i,j));
            }
        }
        vector<int> parent;
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
        }
        vector<int> rank(n,1);

        // kruskal
        int edge = 0;
        double result = 0;
        while(edge<n-1)
        {
            pair<double,int> tmp = pq.top();
            // cout << tmp.first << ' ' << tmp.second << endl;
            pq.pop();
            double value = tmp.first;
            int idx = tmp.second;
            int x = tunnel[idx].first;
            int y = tunnel[idx].second;
            while(x != parent[x]) x = parent[x];
            while(y != parent[y]) y = parent[y];
            if(x == y) continue;
            if(rank[x] > rank[y])
            {
                parent[y] = x;
                result += value;
                edge++;
            }
            else
            {
                parent[x] = y;
                rank[y] = max(rank[x]+1,rank[y]);
                result += value;
                edge++;
            }
        }
        cout << '#' << test_case << ' ' << (long long)round(result) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}