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

#include <set>
#include <vector>
#include <algorithm>


using namespace std;

struct Player
{
	int id;
	int ability;

	bool operator<(const Player &other) const
	{
		return ability != other.ability ? ability > other.ability : id < other.id;
	}
};

int L, M;
int M_upper, M_lower;
set< Player > league_upper[10];
set< Player > league_lower[10];


void init(int N, int L, int mAbility[])
{
	::L = L;
	M = N / L;
	M_upper = M / 2, M_lower = M - M_upper;

	for (int i = 0; i < L; ++i) {
		league_upper[i].clear(), league_lower[i].clear();
	}

	int count = 0;
	for (int i = 0; i < L; i++) {
		vector< Player > players;
		for (int j = 0; j < M; j++) {
			players.push_back({ count, mAbility[count] });
			count++;
		}
		sort(players.begin(), players.end());
		for (int j = 0; j < M_upper; j++) league_upper[i].insert(players[j]);
		for (int j = 0; j < M_lower; j++) league_lower[i].insert(players[M_upper + j]);

	}
}


void adjust(int index)
{
	auto iter1 = prev(league_upper[index].end());
	auto iter2 = league_lower[index].begin();
	if (*iter1 < *iter2) return;

	Player my_p1 = *iter1;
	Player my_p2 = *iter2;
	league_upper[index].erase(iter1);
	league_lower[index].erase(iter2);

	league_upper[index].insert(my_p2);
	league_lower[index].insert(my_p1);
}


int move()
{
	int ret = 0;
	vector< Player > player_lower, player_upper;
	for (int i = 0; i < L - 1; i++) {
		auto iter = prev(league_lower[i].end());
		Player my_p = *iter;
		league_lower[i].erase(iter);
		player_lower.push_back(my_p);
		ret += my_p.id;
	}

	for (int i = 1; i < L; i++) {
		auto iter = league_upper[i].begin();
		Player my_p = *iter;
		league_upper[i].erase(iter);
		player_upper.push_back(my_p);
		ret += my_p.id;
	}

	for (int i = 0; i < L - 1; i++) league_lower[i].insert(player_upper[i]);
	for (int i = 1; i < L; i++)	league_upper[i].insert(player_lower[i - 1]);
	for (int i = 0; i < L; i++) adjust(i);

	return ret;
}


int trade()
{
	int ret = 0;
	vector< Player > player_middle, player_upper;

	for (int i = 0; i < L - 1; i++) {
		auto iter = league_lower[i].begin();
		Player my_p = *iter;
		league_lower[i].erase(iter);
		player_middle.push_back(my_p);
		ret += my_p.id;
	}

	for (int i = 1; i < L; i++)	{
		auto iter = league_upper[i].begin();
		Player my_p = *iter;
		league_upper[i].erase(iter);
		player_upper.push_back(my_p);
		ret += my_p.id;
	}


	for (int i = 0; i < L - 1; i++) league_lower[i].insert(player_upper[i]);
	for (int i = 1; i < L; i++)	league_upper[i].insert(player_middle[i - 1]);
	for (int i = 0; i < L; i++)	adjust(i);

	return ret;
}
