#include <string>
#include <vector>

using namespace std;

bool visited[10],mem[600];
int cnt=0;

bool cmp(string full_id,string star_id)
{
    if(full_id.length()!=star_id.length()) return false;
    for(int i=0;i<full_id.length();i++)
    {
        if(full_id[i]!=star_id[i] && star_id[i]!='*') return false;
    }
    return true;
}

void bt(vector<string> user_id, vector<string> banned_id,int idx)
{
    if(idx == banned_id.size())
    {
        int mask = 0;
        for(int i=0;i<user_id.size();i++)
        {
            mask<<=1;
            if(visited[i]) mask+=1;
        }
        if(!mem[mask])
        {
            mem[mask] = true;
            cnt++;
        }
        return;
    }
    string target = banned_id[idx];
    for(int i=0;i<user_id.size();i++)
    {
        if(!visited[i] && cmp(user_id[i],target))
        {
            visited[i] = true;
            bt(user_id,banned_id,idx+1);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    bt(user_id,banned_id,0);
    answer = cnt;
    return answer;
}
