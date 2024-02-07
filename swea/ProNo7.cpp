#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int K);
extern void registerUser(int mTime, int mUID, int mNum, int mGroupIDs[]);
extern int offerNews(int mTime, int mNewsID, int mDelay, int mGroupID);
extern void cancelNews(int mTime, int mNewsID);
extern int checkUser(int mTime, int mUID, int mRetIDs[]);

/////////////////////////////////////////////////////////////////////////

#define INIT	0
#define REGI	1
#define OFFER	2
#define CANCEL	3
#define CHECK	4

static int gids[30];
static int ansids[3];
static int retids[3];
static bool run()
{
	int N, K;
	int cmd, ans, ret;	
	int time, num, uid, gid, nid, delay;

	int Q = 0;
	bool okay = false;

	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case INIT:
			scanf("%d %d", &N, &K);
			init(N, K);
			okay = true;
			break;

		case REGI:
			scanf("%d %d %d", &time, &uid, &num);
			for (int m = 0; m < num; m++) {
				scanf("%d", &gids[m]);
			}
			registerUser(time, uid, num, gids);
			break;

		case OFFER:
			scanf("%d %d %d %d %d", &time, &nid, &delay, &gid, &ans);
			ret = offerNews(time, nid, delay, gid);
			if (ans != ret) {
				okay = false;
			}
			break;

		case CANCEL:
			scanf("%d %d", &time, &nid);
			cancelNews(time, nid);
			break;

		case CHECK:
			scanf("%d %d %d", &time, &uid, &ans);
			ret = checkUser(time, uid, retids);

			num = ans;
			if (num > 3) num = 3;
			for (int m = 0; m < num; m++) {
				scanf("%d", &ansids[m]);
			}
			if (ans != ret)	{
				okay = false;
			}
			else {
				for (int m = 0; m < num; m++) {
					if (ansids[m] != retids[m]) {
						okay = false;
					}
				}
			}
			break;

		default:
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>

#define CAN	5
#define OFF	6

using namespace std;

class query{
	public:
	int type;
	int t;
	int nid;
	int cid;
	bool operator<(const query tmp) const
	{
		if(this->t == tmp.t) return this->nid > tmp.nid; 
		return this->t > tmp.t;
	}
	query(int a,int b,int c,int d)
	{
		type = a;
		t = b;
		nid = c;
		cid = d;
	}
};

priority_queue<query> pq;
vector<int> users[505];
vector<int> ch[505];
unordered_map<int,int> cid2idx;
unordered_map<int,int> uid2idx;
unordered_set<int> del;
int ucnt,ccnt,n,k;

void process(int mTime)
{
	while(!pq.empty())
	{
		query cur = pq.top();
		if(cur.t > mTime) break;
		pq.pop();
		auto search = del.find(cur.nid);
		if(search != del.end())
		{
			del.erase(search);
			continue;
		}
		int cidx = cid2idx[cur.cid];
		for(int i=0;i<ch[cidx].size();i++)
		{
			int uidx = ch[cidx][i];
			users[uidx].push_back(cur.nid);
		}
	}
}

void init(int N, int K)
{
	cid2idx.clear();
	uid2idx.clear();
	del.clear();
	ucnt = ccnt = 0;
	n = N;
	k = K;
	pq = priority_queue<query>();
}

void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[])
{
	process(mTime);
	int uidx,cidx;
	auto search = uid2idx.find(mUID);
	if(search == uid2idx.end())
	{
		uidx = ucnt;
		uid2idx[mUID] = ucnt++;
		users[uidx].clear();
	}
	else{
		uidx = (*search).second;
	}
	for(int i=0;i<mNum;i++)
	{
		auto search = cid2idx.find(mChannelIDs[i]);
		if(search == cid2idx.end())
		{
			cidx = ccnt;
			ch[cidx].clear();
			cid2idx[mChannelIDs[i]] = ccnt++;
		}
		else
		{
			cidx = (*search).second;
		}
		ch[cidx].push_back(uidx);
	}
}

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID)
{
	pq.push(query(OFF,mTime+mDelay,mNewsID,mChannelID));
	return ch[cid2idx[mChannelID]].size();
}

void cancelNews(int mTime, int mNewsID)
{
	del.insert(mNewsID);
}

int checkUser(int mTime, int mUID, int mRetIDs[])
{
	process(mTime);
	int uidx = uid2idx[mUID];
	int ret = 0;
	for(int i=users[uidx].size() - 1;i>=0;i--)
	{
		int cur = users[uidx][i];
		if(del.find(cur) == del.end())
		{
			if(ret < 3) mRetIDs[ret++] = cur;
			else ret++;
		}
	}
	users[uidx].clear();
	return ret;
}