#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int mId[], int mNum[]);
extern int add(int mId, int mNum, int mParent);
extern int remove(int mId);
extern int distribute(int K);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_DISTRIBUTE 4

static bool run() {
	int q;
	scanf("%d", &q);

	static int midArr[1000], mnumArr[1000];
	int mid, mnum, mparent, n, k;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				scanf("%d", &n);
				for (int j = 0; j < n; ++j) {
					scanf("%d %d", &midArr[j], &mnumArr[j]);
				}
				init(n, midArr, mnumArr);
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
			case CMD_DISTRIBUTE:
				scanf("%d %d", &k, &ans);
				ret = distribute(k);
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
#include<algorithm>

using namespace std;

vector<vector<int>> children;
int etotal[20000];
int parent[20000];
unordered_map<int,int> idm;
int n = 0,rootn;

void init(int N, int mId[], int mNum[]) {
    children.assign(N,vector<int>());
    fill(etotal,&etotal[20000],0);
    idm.clear();
    n = 0;
    rootn = N;
    for(int i=0;i<N;i++)
    {
        idm[mId[i]] = n++;
        etotal[i] = mNum[i];
        parent[i] = i;
    }
	return;
}

int add(int mId, int mNum, int mParent) {
    int pid = idm[mParent];
    if(children[pid].size() >= 3) return -1;
    children[pid].push_back(n);
    parent[n] = pid;
    etotal[n] = mNum;
    children.push_back(vector<int>());
    idm[mId] = n++;
    while(pid != parent[pid])
    {
        etotal[pid] += mNum;
        pid = parent[pid];
    }
    etotal[pid] += mNum;
    // printf("add:%d\n",etotal[idm[mParent]]);
	return etotal[idm[mParent]];
}

void sub_remove(int id)
{
    parent[id] = -1;
    for(int i=0;i<children[id].size();i++)
    {
        sub_remove(children[id][i]);
    }
}

int remove(int mId) {
    if(parent[idm[mId]] < 0) return -1;
    int id = idm[mId];
    int pid = parent[id];
    for(int i=0;i<children[pid].size();i++)
    {
        if(children[pid][i] == id)
        {
            children[pid].erase(children[pid].begin()+i);
            break;
        }
    }
    while(pid != parent[pid])
    {
        etotal[pid] -= etotal[id];
        pid = parent[pid];
    }
    etotal[pid] -= etotal[id];
    sub_remove(idm[mId]);
    // printf("rm:%d\n",etotal[id]);
	return etotal[id];
}

void bs(int l,int r)
{
    int mid = l + (r - l)/2;

}

int distribute(int K) {
    int l = 0, r = K,result;
    while(l<=r)
    {
        int mid = l + (r - l)/2;
        int sum = 0,max = 0;
        for(int i=0;i<rootn;i++)
        {
            if(etotal[i] <= mid)
            {
                sum+=etotal[i];
                if(max < etotal[i]) max = etotal[i];
            }
            else
            {
                sum+=mid;
                if(max < mid) max = mid;
            }
        }
        if(sum > K)
        {
            r = mid - 1;
        }
        else if(sum == K)
        {
            result = max;
            break;
        }
        else{
            result = max;
            l = mid + 1;
        }
    }
    // printf("dis:%d\n",result);
	return result;
}