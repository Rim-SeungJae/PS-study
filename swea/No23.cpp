#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern int init(int N, int sCity[], int eCity[], int mCost[]);
extern void add(int sCity, int eCity, int mCost);
extern int cost(int mHub);

/////////////////////////////////////////////////////////////////////////

#define MAX_N 1400
#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_COST 3

static bool run() {
	int q;
	scanf("%d", &q);

	int n;
	int sCityArr[MAX_N], eCityArr[MAX_N], mCostArr[MAX_N];
	int sCity, eCity, mCost, mHub;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				okay = true;
				scanf("%d", &n);
				for (int j = 0; j < n; ++j) {
					scanf("%d %d %d", &sCityArr[j], &eCityArr[j], &mCostArr[j]);
				}
				scanf("%d", &ans);
				ret = init(n, sCityArr, eCityArr, mCostArr);
				if (ans != ret)
					okay = false;
				break;
			case CMD_ADD:
				scanf("%d %d %d", &sCity, &eCity, &mCost);
				add(sCity, eCity, mCost);
				break;
			case CMD_COST:
				scanf("%d %d", &mHub, &ans);
				ret = cost(mHub);
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

vector<vector<pair<int,int>>> road;
vector<vector<pair<int,int>>> rroad;
unordered_map<int,int> id2pos;
int cNum;


int init(int N, int sCity[], int eCity[], int mCost[]) {
    road.clear();
    rroad.clear();
    id2pos.clear();
    cNum = 0;
    for(int i=0;i<N;i++)
    {
        if(id2pos.find(sCity[i]) == id2pos.end()) id2pos[sCity[i]] = cNum++;
        if(id2pos.find(eCity[i]) == id2pos.end()) id2pos[eCity[i]] = cNum++;
    }
    road.assign(cNum,vector<pair<int,int>>());
    rroad.assign(cNum,vector<pair<int,int>>());
    for(int i=0;i<N;i++)
    {
        int s = id2pos[sCity[i]], e = id2pos[eCity[i]];
        road[s].push_back(make_pair(mCost[i],e));
        rroad[e].push_back(make_pair(mCost[i],s));
    }
	return cNum;
}

void add(int sCity, int eCity, int mCost) {
    int s = id2pos[sCity],e = id2pos[eCity];
    road[s].push_back(make_pair(mCost,e));
    rroad[e].push_back(make_pair(mCost,s));
	return;
}

int cost(int mHub) {
    int target = id2pos[mHub];
    vector<int> dist(cNum,2000000000),rdist(cNum,200000000);
    dist[target] = rdist[target] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,target));
    while(!pq.empty())
    {
        int d = pq.top().first, cur = pq.top().second;
        pq.pop();
        if(dist[cur] != d) continue;
        for(int i=0;i<road[cur].size();i++)
        {
            int next = road[cur][i].second,nd = road[cur][i].first;
            if(d+nd < dist[next])
            {
                dist[next] = d+nd;
                pq.push(make_pair(d+nd,next));
            }
        }
    }
    pq.push(make_pair(0,target));
    while(!pq.empty())
    {
        int d = pq.top().first, cur = pq.top().second;
        pq.pop();
        if(rdist[cur] != d) continue;
        for(int i=0;i<rroad[cur].size();i++)
        {
            int next = rroad[cur][i].second,nd = rroad[cur][i].first;
            if(d+nd < rdist[next])
            {
                rdist[next] = d+nd;
                pq.push(make_pair(d+nd,next));
            }
        }
    }
    int ret = 0;
    for(int i=0;i<cNum;i++)
    {
        ret += dist[i] + rdist[i];
    }
	return ret;
}