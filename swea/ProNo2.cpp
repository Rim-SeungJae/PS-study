#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT       100
#define CMD_INSERT     200
#define CMD_MOVECURSOR 300
#define CMD_COUNT      400

extern void init(int H, int W, char mStr[]);
extern void insert(char mChar);
extern char moveCursor(int mRow, int mCol);
extern int countCharacter(char mChar);
extern void check();

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
	bool correct = false;
	int queryCnt;
	scanf("%d", &queryCnt);
	int H, W;
	char mChar;
	static char mStr[90001];

	while (queryCnt--)
	{
		int cmd;
		scanf("%d", &cmd);

		if (cmd == CMD_INIT)
		{
			scanf("%d %d %s", &H, &W, mStr);
			init(H, W, mStr);
			correct = true;
		}
		else if (cmd == CMD_INSERT)
		{
			scanf(" %c", &mChar);
			insert(mChar);
		}
		else if (cmd == CMD_MOVECURSOR)
		{
			int mRow, mCol;
			scanf("%d %d", &mRow, &mCol);

			char ret = moveCursor(mRow, mCol);

			char ans;
			scanf(" %c", &ans);
			if (ret != ans)
			{
                printf("---------------\n");
				correct = false;
			}
		}
		else if (cmd == CMD_COUNT)
		{
			scanf(" %c", &mChar);

			int ret = countCharacter(mChar);

			int ans;
			scanf("%d", &ans);
			if (ret != ans)
			{
                printf("----------------\n");
				correct = false;
			}
		}
        //check();
	}
	return correct;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

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
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<deque<char>> memo;
vector<vector<int>> cnt;
int h,w,cur_r,cur_c,len;


// void check()
// {
//     for(int i=0;i<len;i++)
//     {
//         if(i%w == 0) printf("\n");
//         if(i == cur_r * w + cur_c) printf("^");
//         printf("%c ",memo[i/w][i%w]);
//     }
//     printf("\n");
// }


void init(int H, int W, char mStr[])
{
    memo.assign(H,deque<char>());
    cnt.assign(H,vector<int>(26,0));
    h = H;
    w = W;
    cur_r = cur_c = 0;
    len = strlen(mStr);
    for(int i=0;i<len;i++)
    {
        memo[i/w].push_back(mStr[i]);
        cnt[i/w][mStr[i]-'a'] += 1;
    }
    // printf("init\n");
}

void insert(char mChar)
{
    memo[cur_r].insert(memo[cur_r].begin() + cur_c,mChar);
    cnt[cur_r][mChar-'a'] += 1;
    int iter = cur_r;
    cur_c++;
    cur_r += cur_c/w;
    cur_c %= w;
    len++;
    while(memo[iter].size()>w)
    {
        char tmp = memo[iter].back();
        memo[iter].pop_back();
        memo[iter+1].push_front(tmp);

        cnt[iter][tmp-'a'] -= 1;
        cnt[iter+1][tmp-'a'] += 1;
        iter++;
    }
    // printf("insert\n");
}

char moveCursor(int mRow, int mCol)
{
    mRow--;
    mCol--;
    if(mRow * w + mCol >= len)
    {
        cur_r = len/w;
        cur_c = len%w;
        return '$';
    }
    cur_r = mRow;
    cur_c = mCol;
    // printf("movecur: %d,%d - %c\n",cur_r,cur_c,memo[cur_r][cur_c]);
	return memo[cur_r][cur_c];
}

int countCharacter(char mChar)
{
    int count = 0;
    for(int i = cur_c;i<memo[cur_r].size();i++)
    {
        if(memo[cur_r][i] == mChar) count++;
    }
    for(int i=cur_r+1;i<h;i++)
    {
        count += cnt[i][mChar-'a'];
    }
    // printf("count: %d\n",count);
	return count;
}
