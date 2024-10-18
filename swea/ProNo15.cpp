#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N);
extern int add(int mId, int mSize);
extern int remove(int mId);
extern int count(int mStart, int mEnd);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_COUNT 4

static bool run() {
	int q;
	scanf("%d", &q);

	int mid, msize, mstart, mend, n;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				scanf("%d", &n);
				init(n);
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %d", &mid, &msize, &ans);
				ret = add(mid, msize);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%d %d", &mid, &ans);
				ret = remove(mid);
				if (ans != ret)
					okay = false;
				break;
			case CMD_COUNT:
				scanf("%d %d %d", &mstart, &mend, &ans);
				ret = count(mstart, mend);
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
	freopen("C:/Users/dipreez/Downloads/sample_input(5).txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include<map>
#include<unordered_map>
#include<set>

using namespace std;

unordered_map<int,int> id2pos;
set<pair<int,int>> files[12020];
map<int,int> chunks;
int file_cnt,n,total_size;

void init(int N) {
    id2pos.clear();
    for(int i=0;i<12000;i++) files[i].clear();
    chunks.clear();
    file_cnt = 0;
    n = N;
    chunks[-1] = -1;
    chunks[n] = n;
    total_size = 0;
	return;
}

int add(int mId, int mSize) {
    if(n - total_size < mSize) return -1;
    id2pos[mId] = file_cnt;
    total_size+=mSize;
    for(auto iter = chunks.begin();iter!=chunks.end() && mSize;)
    {
        auto nxt = iter;
        nxt++;
        if(nxt == chunks.end()) break;
        if(nxt->first - iter->second - 1 <= mSize)
        {
            mSize -= nxt->first - iter->second - 1;
            files[file_cnt].insert(make_pair(iter->second + 1,nxt->first - 1));
            iter->second = nxt->second;
            chunks.erase(nxt);
        }
        else
        {
            files[file_cnt].insert(make_pair(iter->second + 1,iter->second + mSize));
            iter->second = iter->second + mSize;
            break;
        }
    }
    int ret = files[file_cnt].begin() -> first + 1;
    file_cnt++;
	return ret;
}

int remove(int mId) {
    int pos = id2pos[mId];
    int ret = files[pos].size();
    for(auto iter = files[pos].begin();iter!=files[pos].end();iter++)
    {
        int s = iter->first,e = iter->second;
        total_size -= e - s + 1;
        auto target = chunks.lower_bound(s);
        if(target->first != s) target--;
        int first = target->first,second = target->second;
        chunks.erase(target);
        if(first == s && second == e) continue;
        if(second!= e)
        {
            chunks.insert(make_pair(e+1,second));
        }
        if(first != s)
        {
            chunks.insert(make_pair(first,s-1));
        }
    }
    files[pos].clear();
    id2pos.erase(mId);
	return ret;
}

int count(int mStart, int mEnd) {
    mStart--;
    mEnd--;
    int ret = 0;
    for(int i=0;i<file_cnt;i++)
    {
        if(!files[i].empty())
        {
            for(auto iter = files[i].begin();iter!=files[i].end();iter++)
            {
                if(!(mStart>iter->second || mEnd<iter->first))
                {
                    ret++;
                    break;
                }
            }

        }
    }
	return ret;
}