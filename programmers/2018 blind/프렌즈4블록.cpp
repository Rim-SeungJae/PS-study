#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<char>> b(n,vector<char>());
    bool target[33][33]={0,};
    bool flag = true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            b[i].push_back(board[m-1-j][i]);
        }
    }
    while(flag)
    {
        vector<vector<char>> next_b(n,vector<char>());
        flag = false;
        fill(&target[0][0],&target[32][33],false);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<b[i].size();j++)
            {
                if(j+1 < b[i].size() && i+1 < n && j+1 < b[i+1].size())
                {
                    if(b[i][j] == b[i][j+1] && b[i][j] == b[i+1][j] && b[i][j] == b[i+1][j+1])
                    {
                        target[i][j] = target[i][j+1] = target[i+1][j] = target[i+1][j+1] = true;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<b[i].size();j++)
            {
                if(!target[i][j]) next_b[i].push_back(b[i][j]);
                else
                {
                    answer++;
                    flag = true;
                }
            }
        }
        b = next_b;
    }
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            printf("%c ",b[i][j]);
        }
        printf("\n");
    }
    */
    return answer;
}
/*
쉬운 난이도 구현 문제
*? 
