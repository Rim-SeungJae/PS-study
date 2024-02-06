#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT			(100)
#define CMD_CONNECT			(200)
#define CMD_MEASURE			(300)
#define CMD_TEST			(400)

extern void init(int mDevice);
extern void connect(int mOldDevice, int mNewDevice, int mLatency);
extern int measure(int mDevice1, int mDevice2);
extern int test(int mDevice);

static bool run()
{
	int Q;
	int mDevice, mOldDevice, mNewDevice, mDevice1, mDevice2;
	int mLatency;
	
	int ret = -1, ans;

	scanf("%d", &Q);

	bool okay = false;

	for (int q = 0; q < Q; ++q)
	{
		int cmd;
		scanf("%d", &cmd);
		switch(cmd)
		{
		case CMD_INIT:
			scanf("%d", &mDevice);
			init(mDevice);
			okay = true;
			break;
		case CMD_CONNECT:
			scanf("%d %d %d", &mOldDevice, &mNewDevice, &mLatency);
			connect(mOldDevice, mNewDevice, mLatency);
			break;
		case CMD_MEASURE:
			scanf("%d %d", &mDevice1, &mDevice2);
			ret = measure(mDevice1, mDevice2);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		case CMD_TEST:
			scanf("%d", &mDevice);
			ret = test(mDevice);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		default:
			okay = false;
			break;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int TC, MARK;

	scanf("%d %d", &TC, &MARK);
	for (int tc = 1; tc <= TC; ++tc)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include<vector>
#include<unordered_map>

using namespace std;

vector<vector<pair<int,int>>> g;
unordered_map<int,int> idm;
int id;


void init(int mDevice)
{
    id = 0;
    g.clear();
    idm.clear();
    g.assign(1,vector<pair<int,int>>());
    idm[mDevice] = id++;
	return;
}

void connect(int mOldDevice, int mNewDevice, int mLatency)
{
    int Oid = idm[mOldDevice];
    int Nid = idm[mNewDevice] = id++;
    g.push_back(vector<pair<int,int>>());
    g[Oid].push_back(make_pair(Nid,mLatency));
    g[Nid].push_back(make_pair(Oid,mLatency));
	return;
}

void dfs(bool visited[],int cur,int target,int len,int * result)
{
    if(cur == target)
    {
        *result = len;
        return;
    }
    visited[cur] = true;
    for(int i=0;i<g[cur].size();i++)
    {
        if(!visited[g[cur][i].first]) dfs(visited,g[cur][i].first,target,len + g[cur][i].second,result);
    }
    visited[cur] = false;
}

int measure(int mDevice1, int mDevice2)
{
    int result;
    bool visited[10010] = {0,};
    dfs(visited,idm[mDevice1],idm[mDevice2],0,&result);
    // printf("m:%d\n",result);
	return result;
}

pair<int,int> max2_dfs(bool visited[],int cur)
{
    pair<int,int> result = {0,0};
    visited[cur] = true;
    for(int i=0;i<g[cur].size();i++)
    {
        if(!visited[g[cur][i].first])
        {
            int tmp = max2_dfs(visited,g[cur][i].first).first;
            if(tmp + g[cur][i].second > result.first)
            {
                result.second = result.first;
                result.first = tmp + g[cur][i].second;
            }
            else if(tmp + g[cur][i].second > result.second) result.second = tmp + g[cur][i].second;
        }
    }
    visited[cur] = false;
    return result;
}

int test(int mDevice)
{
    bool visited[10010] = {0,};
    pair<int,int> result = max2_dfs(visited,idm[mDevice]);
    // printf("t:%d\n",result.first + result.second);
	return result.first + result.second;
}
