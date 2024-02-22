#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int mPopulation[]);
extern int expand(int M);
extern int calculate(int mFrom, int mTo);
extern int divide(int mFrom, int mTo, int K);

/////////////////////////////////////////////////////////////////////////

#define MAX_N				10000

#define CMD_INIT			100
#define CMD_EXPAND			200
#define CMD_CALCULATE		300
#define CMD_DIVIDE			400

static bool run()
{
	int population[MAX_N];
	int cmd, ans, ret;
	int Q = 0;
	int N, from, to, num;
	bool okay = false;

	scanf("%d", &Q);

	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);

		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &N);

			for (int i = 0; i < N; i++)
				scanf("%d", &population[i]);

			init(N, population);
			okay = true;
			break;

		case CMD_EXPAND:
			scanf("%d", &num);
			ret = expand(num);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;

		case CMD_CALCULATE:
			scanf("%d %d", &from, &to);
			ret = calculate(from, to);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;

		case CMD_DIVIDE:
			scanf("%d %d %d", &from, &to, &num);
			ret = divide(from, to, num);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
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
	freopen("C:/Users/dipreez/Desktop/SWEA/PS-study/swea/sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

class node{
    public:
    int l,r,val;
    bool operator<(const node a) const{
        return this->val > a.val;
    }
    node(int a,int b,int c)
    {
        l = a;
        r = b;
        val = c;
    }
};

int pop[10001],w[10001],rNum[10001],segw[40004],n;
priority_queue<pair<int,int>> pq;

void segw_init(int l,int r,int idx)
{
    if(l==r)
    {
        segw[idx] = w[l];
        return;
    }
    int mid = (l+r)/2;
    segw_init(l,mid,2*idx);
    segw_init(mid+1,r,2*idx+1);
    segw[idx] = segw[2*idx] + segw[2*idx+1];
}

int segw_get(int l,int r,int idx,int mFrom,int mTo)
{
    if(r<mFrom || l>mTo) return 0;
    if(l>=mFrom && r<=mTo) return segw[idx];
    int mid = (l+r)/2;
    return segw_get(l,mid,2*idx,mFrom,mTo) + segw_get(mid+1,r,2*idx+1,mFrom,mTo);
}

void segw_update(int l,int r,int idx,int target,int val)
{
    if(r<target || l>target) return;
    if(l == r)
    {
        segw[idx] = val;
        return;
    }
    int mid = (l+r)/2;
    segw_update(l,mid,2*idx,target,val);
    segw_update(mid+1,r,2*idx+1,target,val);
    segw[idx] = segw[2*idx] + segw[2*idx+1];
}

void init(int N, int mPopulation[])
{
    n=N;
    while(!pq.empty()) pq.pop();
    for(int i=0;i<n;i++)
    {
        pop[i] = mPopulation[i];
    }
    for(int i=0;i<n-1;i++)
    {
        w[i] = mPopulation[i] + mPopulation[i+1];
        rNum[i] = 1;
        pq.push(make_pair(w[i],-i));
    }
    segw_init(0,n-2,1);
	return;
}

int expand(int M)
{
    for(int t=0;t<M;t++)
    {
        auto cur = pq.top();
        pq.pop();
        int idx = -cur.second;
        rNum[idx] += 1;
        w[idx] = (pop[idx] + pop[idx+1]) / rNum[idx];
        pq.push(make_pair(w[idx],-idx));
        segw_update(0,n-2,1,idx,w[idx]);
        if(t == M-1) return w[idx];
    }
}

int calculate(int mFrom, int mTo)
{
    if(mFrom > mTo) swap(mFrom,mTo);
	return segw_get(0,n-2,1,mFrom,mTo-1);
}

bool check_exist(int mFrom,int mTo,int C)
{
    for(int i=mFrom;i<=mTo;i++)
    {
        int sum = 0;
        for(int j=i;j<=mTo;j++)
        {
            sum += pop[j];
            if(sum == C) return true;
        }
    }
    return false;
}

int divide(int mFrom, int mTo, int K)
{
    int l=0,r=1;
    for(int i=mFrom;i<=mTo;i++)
    {
        r+=pop[i];
        if(pop[i] > l) l = pop[i];
    }
    int ret = 2000000000;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        int cnt = 1,sum = 0,sum_max = 0;
        for(int i=mFrom;i<=mTo;i++)
        {
            if(sum + pop[i] > mid)
            {
                // if(mid == 784213)
                // {
                //     if(sum == 784213)printf("hi\n");
                // }
                if(sum > sum_max) sum_max = sum;
                sum = 0;
                cnt++;
            }
            sum+=pop[i];
        }
        if(sum > sum_max) sum_max = sum;
        if(cnt == K)
        {
            r = mid - 1;
            ret = sum_max;
        }
        else if(cnt > K)
        {
            l = mid + 1;
        }
        else{
            r = mid - 1;
            ret = sum_max;
        }
    }
    return ret;
}