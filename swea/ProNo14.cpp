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
	//freopen("sample_input.txt", "r", stdin);

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
int tree[40040];
int subsum[40040];

void init(int mId, int mNum) {
    id2pos.clear();
    pos2id.clear();
    fill(tree,&tree[40040],0);
    fill(subsum,&subsum[40040],0);
    id2pos[mId] = 1;
    pos2id[1] = mId;
    tree[1] = mNum;
    subsum[1] = mNum;
	return;
}

int add(int mId, int mNum, int mParent) {
    int Ppos = id2pos[mParent];
    if(tree[Ppos * 2] != 0 && tree[Ppos * 2 + 1] != 0) return -1;
    int Cpos;
    if(tree[Ppos * 2] != 0) Cpos = Ppos*2+1;
    else Cpos = Ppos*2;
    tree[Cpos] = mNum;
    id2pos[mId] = Cpos;
    pos2id[Cpos] = mId;
    int tmp = Cpos;
    while(tmp)
    {
        subsum[tmp] += mNum;
        tmp/=2;
    }
    return  subsum[Ppos];
}

void tree_del(int pos)
{
    tree[pos] = 0;
    subsum[pos] = 0;
    int mId = pos2id[pos];
    id2pos.erase(mId);
    pos2id.erase(pos);
    if(tree[pos*2] != 0) tree_del(pos*2);
    if(tree[pos*2+1] != 0) tree_del(pos*2+1);
}

int remove(int mId) {
    auto target = id2pos.find(mId);
    if(target == id2pos.end()) return -1;
    int pos = target->second;
    int ret = subsum[pos];
    int tmp = pos/2;
    while(tmp)
    {
        subsum[tmp]-=ret;
        tmp/=2;
    }
    tree_del(pos);
	return ret;
}


int cnt;

int recur(int m,int k,int pos)
{
    if (cnt > m || tree[pos] > k) {
        cnt = m + 1;
        return 0;
    }
    int left = 0;
    int right = 0;
    if (tree[pos*2] != 0) left = recur(m,k,pos*2);
    if (tree[pos*2+1] != 0) right = recur(m,k,pos*2+1);
    if (cnt <= m) {
        if(left == 0 && right == 0) return tree[pos];
        if(tree[pos] + left > k && tree[pos] + right > k)
        {
            cnt+=2;
            return tree[pos];
        }
        if (tree[pos] + left > k && right != 0)
        {
            cnt++;
            return tree[pos] + right;
        }
        if(tree[pos] + right > k && left != 0)
        {
            cnt++;
            return  tree[pos] + left;
        }
        if (tree[pos] + left + right > k)
        {
            if (left > right && right != 0)
            {
                cnt++;
                return tree[pos] + right;
            }
            else
            {
                cnt++;
                return tree[pos] + left;
            }
        }
        return tree[pos] + left + right;
    }
    return 0;
}

int solve(int m,int k,int pos) {
    if(cnt>m) return 0;
    if (tree[pos] > k) {
        cnt = m + 1;
        return 0;
    }
    int left = 0, right = 0;
    if (tree[pos*2] != 0) left = solve(m,k,pos*2);
    if (tree[pos*2+1] != 0) right = solve(m,k,pos*2+1);
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
            if (left > right) left = 0;
            else right = 0;
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