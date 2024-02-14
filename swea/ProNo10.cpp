#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define BAR_LEN 5

#define CMD_INIT 100
#define CMD_MAKEWALL 200
#define CMD_MATCHPIECE 300

extern void init();
extern void makeWall(int mHeights[BAR_LEN]);
extern int matchPiece(int mHeights[BAR_LEN]);

static bool run()
{
	int N;
	int cmd;
	int heights[BAR_LEN];

	int ret = 0;
	int ans = 0;
	scanf("%d", &N);

	scanf("%d", &cmd);
	bool okay = false;
	if (cmd == CMD_INIT)
	{
		init();
		okay = true;
	}

	for (int turn = 0; turn < N-1; turn++)
	{
		scanf("%d", &cmd);
		for (int i = 0; i < BAR_LEN; i++)
		{
			scanf("%d", &heights[i]);
		}

		switch (cmd)
		{
		case CMD_MAKEWALL:
			makeWall(heights);
			break;
		case CMD_MATCHPIECE:
			ret = matchPiece(heights);
			scanf("%d", &ans);
			if (ans != ret)
				okay = false;
			break;
		}
	}
	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	// freopen("C:/Users/callo/Downloads/sample_25_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);
	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}
	return 0;
}

#include<list>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<deque>

using namespace std;

class node{
    public:
    char val;
    int next;
    int prev;
};

node lt[100010];
bool valid[100010];
unordered_map<int,set<int,greater<int>>> hm;
const int pw[5] = {279841,12167,529,23,1};
const int MOD = 292561;
int n;

void init()
{
    for(int i=0;i<100010;i++)
    {
        lt[i].next = i+1;
        lt[i].prev = i-1;
        lt[i].val = 0;
    }
    fill(valid,&valid[100010],0);
    hm.clear();
    n=0;
}

void makeWall(int mHeights[5])
{
    deque<int> dq;
    int min = 11;
    int hval = 0;
    for(int i=0;i<5;i++)
    {
        lt[n].val = mHeights[i];
        valid[n] = true;
        n++;
        dq.push_front(mHeights[i]);
        if(min>mHeights[i]) min = mHeights[i];
    }
    for(int i=0;i<5;i++) hval += (dq[i]-min) * pw[i];
    int idx = n - 5;
    for(int j=0;j<5;j++)
    {
        auto f = hm.find(hval);
        if(f == hm.end())
        {
            set<int,greater<int>> tmp = set<int,greater<int>>();
            tmp.insert(idx);
            hm[hval] = tmp;
        }
        else{
            (*f).second.insert(idx);
        }
        idx = lt[idx].prev;
        if(idx<0) break;
        dq.pop_front();
        dq.push_back(lt[idx].val);
        min = 11;
        hval = 0;
        for(int i=0;i<5;i++) if(min>dq[i]) min = dq[i];
        for(int i=0;i<5;i++) hval += (dq[i]-min) * pw[i];
    }
}

int matchPiece(int mHeights[5])
{
    int max = 0;
    int target = 0;
    for(int i=0;i<5;i++)
    {
        if(max < mHeights[i]) max = mHeights[i];
    }
    for(int i=0;i<5;i++)
    {
        target += (max - mHeights[i]) * pw[i];
    }
    auto f = hm.find(target);
    if(f!=hm.end() && !(*f).second.empty())
    {
        auto loc = (*f).second.begin();
        while(loc != (*f).second.end())
        {
            int idx = *loc;
            int i;
            for(i=0;i<5;i++)
            {
                if(!valid[idx]) break;
                idx = lt[idx].next;
            }
            if(i!=5) loc = (*f).second.erase(loc);
            else break;
        }
        if(loc == (*f).second.end()) return -1;
        else{
            int idx = *loc;
            for(int i=0;i<5;i++)
            {
                valid[idx] = false;
                idx = lt[idx].next;
            }
            if(lt[*loc].prev >= 0)
            {
                lt[lt[*loc].prev].next = idx;
            }
            lt[idx].prev = lt[(*loc)].prev;
            return *loc + 1;
        }
    }
    return -1;
    /*
    int cur = 0;
    for(int i=0;i<5;i++)
    {
        cur += lt[lt.size()-1-i] * pw[i];
    }
    if((target-cur)%MOD == 0)
    {
        lt.erase(lt.end()-5,lt.end());
        return lt.size() + 1;
    }
    for(int i=lt.size()-6;i>=0;i--)
    {
        cur -= lt[i+5] * pw[0];
        cur *= pw[3];
        cur += lt[i];
        if((target-cur)%MOD == 0)
        {
            lt.erase(lt.begin()+i,lt.begin()+i+5);
            return i + 1;
        }
    }
    */
}