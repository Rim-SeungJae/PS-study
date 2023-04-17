#include <string>
#include <vector>
#include<cstdio>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    vector<vector<int>> v(n,vector<int>());
    vector<int> bucket;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int j=n-1;
        while(j>=0 && board[j][i]!=0)
        {
            v[i].push_back(board[j][i]);
            j--;
        }
    }
    for(int i=0;i<moves.size();i++)
    {
        int cmd = moves[i]-1;
        
        if(!v[cmd].empty())
        {
            bucket.push_back(v[cmd].back());
            v[cmd].pop_back();
        }
        
        while(bucket.size()>=2 && *(bucket.end()-1) == *(bucket.end()-2))
        {
            bucket.pop_back();
            bucket.pop_back();
            answer+=2;
        }
        
    }
    return answer;
}
