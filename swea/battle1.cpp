#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 100
#define CMD_UPDATE_SCORE 200
#define CMD_UNION_TEAM 300
#define CMD_GET_SCORE 400

extern void init(int N);
extern void updateScore(int mWinnerID, int mLoserID, int mScore);
extern void unionTeam(int mPlayerA, int mPlayerB);
extern int getScore(int mID);

static bool run()
{
	int queryCnt, cmd;
	int ans, res;
	bool okay = false;

	scanf("%d", &queryCnt);
	for (int i = 0; i < queryCnt; i++)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			int N;
			scanf("%d", &N);
			init(N);
			okay = true;
			break;
		case CMD_UPDATE_SCORE:
			int mWinnerID, mLoserID, mScore;
			scanf("%d%d%d", &mWinnerID, &mLoserID, &mScore);
			updateScore(mWinnerID, mLoserID, mScore);
			break;
		case CMD_UNION_TEAM:
			int mPlayerA, mPlayerB;
			scanf("%d%d", &mPlayerA, &mPlayerB);
			unionTeam(mPlayerA, mPlayerB);
			break;
		case CMD_GET_SCORE:
			int mID;
			scanf("%d", &mID);
			res = getScore(mID);
			scanf("%d", &ans);
			if (ans != res)
			{
				okay = false;
			}
			break;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	// freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d%d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include<algorithm>
#include<vector>
#include<queue>

int parent[100001],rank[100001],score[100001],staged[100001];
std::vector<int> children[100001];

inline int find_set(int x)
{
    while (x!=parent[x])
    {
        x = parent[x];
    }
    return x;
}

void init(int N)
{
    for(int i=1;i<=N;i++)
    {
        parent[i] = i;
        rank[i] = 1;
        score[i] = 0;
        children[i].clear();
        staged[i] = 0;
    }
    //printf("init\n");
}

void dfs(int ID,int mScore)
{
    score[ID] += mScore;
    for(int i=0;i<children[ID].size();i++)
    {
        dfs(children[ID][i],mScore);
    }
}

void bfs(int ID,int mScore)
{
    std::queue<int> q;
    q.push(ID);
    while(!q.empty())
    {
        int cur = q.front();
        score[cur] += mScore;
        q.pop();
        for(int i=0;i<children[cur].size();i++)
        {
            q.push(children[ID][i]);
        }
    }
}

void add(int ID)
{
    //printf("%d to %d\n",ID,staged[ID]);
    if(staged[ID] == 0) return;
    std::queue<int> q;
    q.push(ID);
    while(!q.empty())
    {
        int cur = q.front();
        score[cur] += staged[ID];
        q.pop();
        for(int i=0;i<children[cur].size();i++)
        {
            q.push(children[cur][i]);
        }
    }
    staged[ID] = 0;
}

void updateScore(int mWinnerID, int mLoserID, int mScore)
{
    int wset = find_set(mWinnerID), lset = find_set(mLoserID);
    staged[wset] += mScore;
    staged[lset] -= mScore;
    //printf("update %d %d\n",wset,lset);
}

void unionTeam(int mPlayerA, int mPlayerB)
{
    int aset = find_set(mPlayerA), bset = find_set(mPlayerB);
    //add(aset);
    //add(bset);
    if(rank[aset] > rank[bset])
    {
        parent[bset] = aset;
        children[aset].push_back(bset);
        staged[bset] -= staged[aset];
    }
    else if(rank[bset] > rank[aset])
    {
        parent[aset] = bset;
        children[bset].push_back(aset);
        staged[aset] -= staged[bset];
    }
    else{
        parent[bset] = aset;
        children[aset].push_back(bset);
        rank[aset]++;
        staged[bset] -= staged[aset];
    }
    //printf("union %d %d\n",aset,bset);
}

int getScore(int mID)
{

    int result = 0,x = mID;
    while (x!=parent[x])
    {
        result += staged[x];
        x = parent[x];
    }
    result += staged[x];
    //printf("%d:%d\n",mID,result);
	return result;
}
