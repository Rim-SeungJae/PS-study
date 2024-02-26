#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int mId, int mNum);
extern int add(int mId, int mNum, int mParent);
extern int remove(int mId);
extern int reorganize(int M, int K);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_REORGANIZE 4

static bool run() {
	int q;
	scanf("%d", &q);

	int mid, mnum, mparent, m, k;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				scanf("%d %d", &mid, &mnum);
				init(mid, mnum);
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %d %d", &mid, &mnum, &mparent, &ans);
				ret = add(mid, mnum, mparent);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%d %d", &mid, &ans);
				ret = remove(mid);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REORGANIZE:
				scanf("%d %d %d", &m, &k, &ans);
				ret = reorganize(m, k);
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
	freopen("C:/Users/callo/Downloads/sample_input(12).txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include<unordered_map>
#include<algorithm>

using namespace std;

unordered_map<int,int> id2pos;
unordered_map<int,int> pos2id;
int tree[8040],subsum[8040],parent[8040];
pair<int,int> children[8040];
int nCnt;

void init(int mId, int mNum) {
    id2pos.clear();
    pos2id.clear();
    fill(tree,&tree[8040],0);
    fill(subsum,&subsum[8040],0);
    fill(parent,&parent[8040],0);
    fill(children,&children[8040],make_pair(0,0));
    id2pos[mId] = 1;
    pos2id[1] = mId;
    tree[1] = mNum;
    subsum[1] = mNum;
    parent[1] = 0;
    nCnt = 2;
	return;
}

int add(int mId, int mNum, int mParent) {
    int Ppos = id2pos[mParent];
    if(children[Ppos].first != 0 && children[Ppos].second != 0) return -1;
    int Cpos = nCnt;
    if(children[Ppos].first != 0) children[Ppos].second = Cpos;
    else children[Ppos].first = Cpos;
    tree[Cpos] = mNum;
    parent[Cpos] = Ppos;
    id2pos[mId] = Cpos;
    pos2id[Cpos] = mId;
    int tmp = Cpos;
    while(tmp)
    {
        subsum[tmp] += mNum;
        tmp=parent[tmp];
    }
    nCnt++;
    return  subsum[Ppos];
}

void tree_del(int pos)
{
    tree[pos] = 0;
    subsum[pos] = 0;
    if(children[parent[pos]].first == pos)children[parent[pos]].first = 0;
    else children[parent[pos]].second = 0;
    parent[pos] = 0;
    int mId = pos2id[pos];
    id2pos.erase(mId);
    pos2id.erase(pos);
    if(children[pos].first != 0) tree_del(children[pos].first);
    if(children[pos].second != 0) tree_del(children[pos].second);
}

int remove(int mId) {
    auto target = id2pos.find(mId);
    if(target == id2pos.end()) return -1;
    int pos = target->second;
    int ret = subsum[pos];
    int tmp = parent[pos];
    while(tmp)
    {
        subsum[tmp]-=ret;
        tmp=parent[tmp];
    }
    tree_del(pos);
	return ret;
}


int cnt;

int recur(int m,int k,int pos) {
    if (tree[pos] > k) cnt = m + 1;
    int left = 0, right = 0;
    if (cnt <= m && children[pos].first != 0) left = recur(m,k,children[pos].first);
    if (cnt <= m && children[pos].second != 0) right = recur(m,k,children[pos].second);
    if (cnt <= m) {
        if (tree[pos] + left > k)
        {
            cnt++;
            left = 0;
        }
        if (tree[pos] + right > k)
        {
            cnt++;
            right = 0;
        }
        if (tree[pos] + left + right > k)
        {
            cnt++;
            if (left > right) return tree[pos] + right;
            else return tree[pos] + left;
        }
        return tree[pos] + left + right;
    }
    return 0;
}

int reorganize(int M, int K) {
    cnt = 1;
    recur(M,K,1);
	return cnt<=M;
}