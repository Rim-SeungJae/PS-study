#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

struct Result
{
    int top;
    int count;
};

void init(int C);
Result dropBlocks(int mCol, int mHeight, int mLength);

#define CMD_INIT 100
#define CMD_DROP 200

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ans_top, ans_count;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);
        if (query == CMD_INIT)
        {
            int C;
            scanf("%d", &C);
            init(C);
            ok = true;
        }
        else if (query == CMD_DROP)
        {
            int mCol, mHeight, mLength;
            scanf("%d %d %d", &mCol, &mHeight, &mLength);
            Result ret = dropBlocks(mCol, mHeight, mLength);
            scanf("%d %d", &ans_top, &ans_count);
            if (ans_top != ret.top || ans_count != ret.count)
            {
                ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    setbuf(stdout, NULL);
    // freopen("sample_input.txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    return 0;
}

#include<algorithm>

using namespace std;

int segmin[4000000],segmax[4000000],lazy[4000000],c,cnt;

// struct Result{
//     int top;
//     int count;
// };

void init(int C)
{
    fill(segmin,&segmin[4 * C],0);
    fill(segmax,&segmax[4 * C],0);
    fill(lazy,&lazy[4 * C],0);
    c = C;
    cnt=0;
}

void update(int l,int r,int idx,int mHeight,int lbound,int rbound)
{
    if(lazy[idx]!=0)
    {
        segmax[idx] += lazy[idx];
        segmin[idx] += lazy[idx];
        if(l!=r)
        {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if(l>rbound || r<lbound) return;
    if(l>=lbound && r<=rbound)
    {
        if(l!=r)
        {
            lazy[2 * idx] += mHeight;
            lazy[2 * idx + 1] += mHeight;
        }
        segmax[idx] += mHeight;
        segmin[idx] += mHeight;
    }
    else{
        int mid = l + (r-l)/2;
        update(l,mid,2*idx, mHeight,lbound,rbound);
        update(mid+1,r,2*idx + 1,mHeight,lbound,rbound);
        segmax[idx] = max(segmax[2*idx],segmax[2*idx+1]);
        segmin[idx] = min(segmin[2*idx],segmin[2*idx+1]);
    }
}

Result dropBlocks(int mCol, int mHeight, int mLength)
{
    cnt += (mHeight * mLength)%1000000;
    cnt %= 1000000;
    update(0,c-1,1,mHeight,mCol,mCol+mLength-1);
    Result ret;
    ret.top = segmax[1] - segmin[1];
    ret.count = cnt - (segmin[1] * c)%1000000;
    ret.count %= 1000000;
    if(ret.count < 0 ) ret.count += 1000000;
    printf("%d %d\n",ret.top,ret.count);
    return ret;
}
