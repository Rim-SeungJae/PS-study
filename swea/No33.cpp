#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 100
#define CMD_DESTROY 200
#define CMD_UPDATE 300
#define CMD_UPDATE_TYPE 400
#define CMD_CALC 500

void init(int N, int M, int mType[], int mTime[]);
void destroy();
void update(int mID, int mNewTime);
int updateByType(int mTypeID, int mRatio256);
int calculate(int mA, int mB);

#define MAX_N 100000

static int mType[MAX_N];
static int mTime[MAX_N];

static int run()
{
	int C;
	int isOK = 0;
	int cmd, ret, chk;

	int N, M;
	int mID, mTypeID, mNewTime, mRatio;
	int mA, mB;

	scanf("%d", &C);

	for (int c = 0; c < C; ++c)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d %d ", &N, &M);
			for (int i = 0; i < N - 1; i++) scanf("%d", &mType[i]);				
			for (int i = 0; i < N - 1; i++) scanf("%d", &mTime[i]);
			init(N, M, mType, mTime);
			isOK = 1;
			break;

		case CMD_UPDATE:
			scanf("%d %d", &mID, &mNewTime);
			update(mID, mNewTime);			
			break;

		case CMD_UPDATE_TYPE:
			scanf("%d %d", &mTypeID, &mRatio);
			ret = updateByType(mTypeID, mRatio);
			scanf("%d", &chk);
			if (ret != chk)
				isOK = 0;
			break;

		case CMD_CALC:
			scanf("%d %d", &mA, &mB);
			ret = calculate(mA, mB);
			scanf("%d", &chk);
			if (ret != chk)
				isOK = 0;
			break;

		default:
			isOK = 0;
			break;
		}
	}
	destroy();
	return isOK;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("C:/Users/callo/Downloads/sample_input(13).txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		if (run()) printf("#%d %d\n", tc, MARK);
		else printf("#%d %d\n", tc, 0);
	}
	return 0;
}

#include<vector>

using namespace std;
int seg[400010],arr[100010],n,m;
vector<int> type2idx[1000];

void seg_init(int idx,int l,int r)
{
    if(l == r)
    {
        seg[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    seg_init(idx*2,l,mid);
    seg_init(idx*2+1,mid+1,r);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

void init(int N, int M, int mType[], int mTime[])
{
    n = N;
    m = M;
    for(int i=0;i<m;i++) type2idx[i].clear();
    for(int i=0;i<n-1;i++)
    {
        type2idx[mType[i]].push_back(i);
    }
    for(int i=0;i<n-1;i++)
    {
        arr[i] = mTime[i];
    }
    seg_init(1,0,n-2);
}

void destroy()
{

}

void seg_update(int idx,int l,int r,int target,int val)
{
    if(r<target || l>target) return;
    if(l == r)
    {
        seg[idx] = val;
        return;
    }
    int mid = (l+r)/2;
    seg_update(idx*2,l,mid,target,val);
    seg_update(idx*2+1,mid+1,r,target,val);
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}

void update(int mID, int mNewTime)
{
    arr[mID] = mNewTime;
    seg_update(1,0,n-2,mID,mNewTime);
}

int updateByType(int mTypeID, int mRatio256)
{
    int ret = 0;
    for(int i=0;i<type2idx[mTypeID].size();i++)
    {
        int target = type2idx[mTypeID][i];
        arr[target] = arr[target] * mRatio256 / 256;
        ret += arr[target];
        seg_update(1,0,n-2,target,arr[target]);
    }
	return ret;
}

int seg_get(int idx,int l,int r,int mA,int mB)
{
    if(r<mA || l>mB) return 0;
    if(mA<=l && mB >= r) return seg[idx];
    int mid = (l+r)/2;
    return seg_get(idx*2,l,mid,mA,mB) + seg_get(idx*2+1,mid+1,r,mA,mB);
}

int calculate(int mA, int mB)
{
    if(mA>mB) swap(mA,mB);
	return seg_get(1,0,n-2,mA,mB-1);
}