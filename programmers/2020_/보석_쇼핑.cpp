#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    pair<int,int> min_pair = make_pair(0,1000100);
    int left=0,right=0;
    unordered_map<string,int> m;
    for(int i=0;i<gems.size();i++)
    {
        if(m.find(gems[i]) == m.end())
        {
            m.insert(make_pair(gems[i],0));
        }
    }
    m[gems[0]] = 1;
    int found = 1;
    while(true)
    {   
        if(found == m.size())
        {
            if(min_pair.second - min_pair.first > right - left)
            {
                min_pair = make_pair(left+1,right+1);
            }
        }
        if(right-left>0)
        {
            auto p = m.find(gems[left]);
            if(p->second>1)
            {
                left++;
                p->second -= 1;
                continue;
            }
        }
        
        right++;
        if(right>=gems.size()) break;
        auto p = m.find(gems[right]);
        if(p->second==0) found++;
        p->second += 1;
    }
    answer.push_back(min_pair.first);
    answer.push_back(min_pair.second);
    return answer;
}
