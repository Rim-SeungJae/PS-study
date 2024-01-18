#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_INPUT 10000
#define MAX_NUM 30000

extern void init();
extern void addUser(int uID, int income);
extern int getTop10(int result[10]);

static int input[MAX_INPUT];

static unsigned int seed = 13410;

static unsigned int pseudoRand() {
	seed = seed * 214013 + 2531011;
	return (unsigned int)(seed >> 11) % MAX_NUM;
}

static void makeInput(int inputLen) {
	for (int i = 0; i < inputLen; i++) {
		input[i] = pseudoRand();
	}
}

static int run() {
	int N, userNum, uID = 0;
	int score = 100, result[10], cnt;
	int sum, check;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &userNum);
		makeInput(userNum);
		for (int j = 0; j < userNum; j++) {
			addUser(uID++, input[j]);
		}
		cnt = getTop10(result);

		sum = 0;
		for (int j = 0; j < cnt; j++)
			sum += result[j];
		scanf("%d", &check);
		if (check != sum)
			score = 0;
	}
	return score;
}

int main(void) {
	setbuf(stdout, NULL);
	//freopen("partial_sort_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		init();
		printf("#%d %d\n", tc, run());
	}
	return 0;
}

int pq[100010],income[100010];
int size;

void init()
{
    size = 0;
}

void addUser(int uID, int height) 
{
    pq[++size] = uID;
    income[uID] = height;
    int cur = size;
    int parent = cur/2;
    while(parent >= 1)
    {
        if(income[pq[parent]] < income[pq[cur]] || ((income[pq[parent]] == income[pq[cur]]) && (pq[parent] > pq[cur])))
        {
            int tmp = pq[parent];
            pq[parent] = pq[cur];
            pq[cur] = tmp;
            cur = parent;
            parent = cur/2;
        }
        else break;
    }
}

void pq_pop()
{
    pq[1] = pq[size--];
    int cur = 1;
    int lc = cur*2, rc = cur*2 + 1;
    while(true)
    {
        if(rc <= size)
        {
            if(income[pq[lc]] > income[pq[rc]] || (income[pq[rc]] == income[pq[lc]] && pq[rc] > pq[lc]))
            {
                int tmp = lc;
                lc = rc;
                rc = tmp;
            }
            if(income[pq[rc]] > income[pq[cur]] || (income[pq[rc]] == income[pq[cur]] && pq[rc] < pq[cur]))
            {
                int tmp = pq[cur];
                pq[cur] = pq[rc];
                pq[rc] = tmp;
                cur = rc;
                lc = cur * 2;
                rc = cur * 2 + 1;
            }
            else break;
        }
        else if(lc <= size)
        {
            if(income[pq[lc]] > income[pq[cur]] || (income[pq[lc]] == income[pq[cur]] && pq[lc] < pq[cur]))
            {
                int tmp = pq[lc];
                pq[lc] = pq[cur];
                pq[cur] = tmp;
                cur = lc;
                lc = cur * 2;
                rc = cur * 2 + 1;
            }
            else break;
        }
        else break;
    }
}

int getTop10(int result[10]) 
{
    int i=0;
    int max = (10<size?10:size);
    for(;i<max;i++)
    {
        result[i] = pq[1];
        pq_pop();
    }
    for(int j=0;j<i;j++)
    {
        addUser(result[j],income[result[j]]);
    }
    return i;
}