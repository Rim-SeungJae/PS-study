#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init();
extern int add(int mId, int mGrade, char mGender[7], int mScore);
extern int remove(int mId);
extern int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_REMOVE 300
#define CMD_QUERY 400

static bool run() {
	int q;
	scanf("%d", &q);

	int id, grade, score;
	char gender[7];
	int cmd, ans, ret;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				init();
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %s %d %d", &id, &grade, gender, &score, &ans);
				ret = add(id, grade, gender, score);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%d %d", &id, &ans);
				ret = remove(id);
				if (ans != ret)
					okay = false;
				break;
			case CMD_QUERY: {
				int gradeCnt, genderCnt;
				int gradeArr[3];
				char genderArr[2][7];
				scanf("%d", &gradeCnt);
				if (gradeCnt == 1) {
					scanf("%d %d", &gradeArr[0], &genderCnt);
				} else if (gradeCnt == 2) {
					scanf("%d %d %d", &gradeArr[0], &gradeArr[1], &genderCnt);
				} else {
					scanf("%d %d %d %d", &gradeArr[0], &gradeArr[1], &gradeArr[2], &genderCnt);
				}
				if (genderCnt == 1) {
					scanf("%s %d %d", genderArr[0], &score, &ans);
				} else {
					scanf("%s %s %d %d", genderArr[0], genderArr[1], &score, &ans);
				}
				ret = query(gradeCnt, gradeArr, genderCnt, genderArr, score);
				if (ans != ret)
					okay = false;
				break;
			}
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include<vector>
#include<set>
#include<unordered_map>
#include<cstring>

using namespace std;

set<pair<int,int>> s[4][2];
unordered_map<int,array<int,3>> um;

void init() {
    for(int i=1;i<=3;i++)
    {
        for(int j=0;j<2;j++) s[i][j].clear();
    }
    um.clear();
    //printf("init\n");
	return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) {
    int gender;
    if(strcmp(mGender,"male") == 0) gender = 0;
    else gender = 1;
    s[mGrade][gender].insert(make_pair(mScore,mId));
    um[mId] = array<int,3>({mGrade,gender,mScore});
    //printf("add %d\n",(*s[mGrade][gender].rbegin()).second);
	return (*s[mGrade][gender].rbegin()).second;
}

int remove(int mId) {
    int grade,gender,score;
    auto target = um.find(mId);
    if(target == um.end()) return 0;
    grade = (*target).second[0];
    gender = (*target).second[1];
    score = (*target).second[2];
    s[grade][gender].erase(make_pair(score,mId));
    um.erase(mId);
    if(s[grade][gender].empty()) return 0;
    //printf("remove %d\n",(*s[grade][gender].begin()).second);
	return (*s[grade][gender].begin()).second;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
    int gender;
    pair<int,int> min = make_pair(300001,1000000001);
    for(int i=0;i<mGradeCnt;i++)
    {
        for(int j=0;j<mGenderCnt;j++)
        {
            int grade = mGrade[i],gender;
            if(strcmp(mGender[j],"male") == 0) gender = 0;
            else gender = 1;
            auto target = s[grade][gender].lower_bound(make_pair(mScore,0));
            if(target != s[grade][gender].end())
            {
                if((*target).first < min.first) min = (*target);
                else if((*target).first == min.first && (*target).second < min.second) min = (*target);
            }
        }
    }
    if(min.first == 300001) return 0;
    //printf("q %d\n",min.second);
	return min.second;
}