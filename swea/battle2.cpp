#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>
void init(int N, int L, int mAbility[]);
int move();
int trade();

#define MAX_N 39990

#define CMD_INIT 100
#define CMD_MOVE 200
#define CMD_TRADE 300

static bool run()
{
    int query_num;
    scanf("%d", &query_num);

    int ans;
    bool ok = false;

    for (int q = 0; q < query_num; q++)
    {
        int query;
        scanf("%d", &query);
        if (query == CMD_INIT)
        {
            int N;
            int L;
            int mAbility[MAX_N];
            scanf("%d %d", &N, &L);
            for (int i = 0; i < N; i++){
                scanf("%d", &mAbility[i]);
            }
            init(N, L, mAbility);
            ok = true;
        }
        else if (query == CMD_MOVE)
        {
            int ret = move();
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
        else if (query == CMD_TRADE)
        {
            int ret = trade();
            scanf("%d", &ans);
            if (ans != ret)
            {
                ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    clock_t start, finish;
    double duration;
    
    start = clock();
    setbuf(stdout, NULL);
    freopen("C:/Users/callo/Downloads/sample_input(10).txt", "r", stdin);
    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }
    finish = clock();
    
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f초", duration);
    return 0;
}

#include<list>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

int abil[40000],n,l;

struct cmp_abil{
    bool operator()(int a,int b)
    {
        if(abil[a] != abil[b]) return abil[a] > abil[b];
        return a<b;
    }
};

bool cmp(int a,int b)
{
    if(abil[a] != abil[b]) return abil[a] > abil[b];
    return a<b;
}

set<int,cmp_abil> league[10];
set<int,cmp_abil>::iterator mid[10];
priority_queue<int,vector<int>,cmp_abil> pq;

void init(int N, int L, int mAbility[])
{
    int tmp[10][4000] = {0,};
    n = N;
    l = L;
    for(int i=0;i<l;i++)
    {
        league[i].clear();
        mid[i] = set<int,cmp_abil>::iterator();
    }
    for(int i=0;i<n;i++)
    {
        abil[i] = mAbility[i];
        tmp[i/(n/l)][i%(n/l)] = i;
    }
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<n/l;j++) league[i].insert(tmp[i][j]);
        mid[i] = league[i].begin();
        advance(mid[i],n/l/2);
    }
    pq.push(0);
    pq.push(1);
}

int move()
{
    int cnt=0;
    int delay[4000][2];
    for(int i=0;i<l-1;i++)
    {
        auto tmp1 = league[i].end();
        tmp1--;
        auto tmp2 = league[i+1].begin();
        int val1 = *tmp1,val2 = *tmp2;
        cnt += val1+val2;
        delay[i][0] = val2;
        delay[i+1][1] = val1;
        league[i].erase(tmp1);
        league[i+1].erase(tmp2);
        int mval = *mid[i];
        if(i == 0)
        {
            league[i].insert(delay[i][0]);
            if(cmp(delay[i][0],mval)) mid[i]--;
        }
        else{
            league[i].insert(delay[i][0]);
            league[i].insert(delay[i][1]);
            if(cmp(delay[i][0],mval) && cmp(delay[i][1],mval)) mid[i]--;
            if(!cmp(delay[i][0],mval) && !cmp(delay[i][1],mval)) mid[i]++;
        }
    }
    league[l-1].insert(delay[l-1][1]);
    if(!cmp(delay[l-1][1],*(mid[l-1]))) mid[l-1]++;
    
    return cnt;
}

int trade()
{
    
    int cnt=0;
    int delay[4000][2];
    for(int i=0;i<l-1;i++)
    {
        auto tmp1 = mid[i];
        auto tmp2 = league[i+1].begin();
        cnt += *tmp1+*tmp2;
        delay[i][0]=(*tmp2);
        delay[i+1][1]=(*tmp1);
        mid[i] = league[i].erase(tmp1);
        league[i+1].erase(tmp2);
        if(i == 0)
        {
            league[i].insert(delay[i][0]);
            if(cmp(delay[i][0],*(mid[i]))) mid[i]--;
        }
        else{
            league[i].insert(delay[i][0]);
            league[i].insert(delay[i][1]);
            if(cmp(delay[i][0],*(mid[i])) && cmp(delay[i][1],*(mid[i]))) mid[i]--;
            if(!cmp(delay[i][0],*(mid[i])) && !cmp(delay[i][1],*(mid[i]))) mid[i]++;
        }
    }
    league[l-1].insert(delay[l-1][1]);
    if(!cmp(delay[l-1][1],*(mid[l-1]))) mid[l-1]++;
    
    return cnt;
}