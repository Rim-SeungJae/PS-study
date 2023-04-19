#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <cstdio>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    map<long long,long long*> s;
    for(int i=0;i<room_number.size();i++)
    {
        
        auto p = s.find(room_number[i]);
        long long target = *(p->second);
        if(p == s.end())
        {
            answer.push_back(room_number[i]);
            auto next = s.find(room_number[i]+1);
            auto prev = s.find(room_number[i]-1);
            if(next==s.end())
            {
                if(prev != s.end())
                {
                    *(prev->second) = room_number[i]+1;
                    s.insert(make_pair(room_number[i],prev->second));
                }
                else{
                    long long * val = new long long;
                    *val = room_number[i]+1;
                    s.insert(make_pair(room_number[i],val));
                }
            }
            else{
                if(prev != s.end())
                {
                    while(prev != s.end())
                    {
                        prev->second = next->second;
                        prev = s.find(prev->first - 1);
                    }
                    s.insert(make_pair(room_number[i],prev->second));
                }
                else s.insert(make_pair(room_number[i],next->second));
            }
        }
        else{
            answer.push_back(target);
            auto next = s.find(target+1);
            auto prev = s.find(target-1);
            //printf("%lld %lld\n",room_number[i],target);
            if(next == s.end())
            {
                if(prev != s.end())
                {
                    *(prev->second) = target+1;
                    s.insert(make_pair(target,prev->second));
                }
                else{
                    long long * val = new long long;
                    *val = target+1;
                    s.insert(make_pair(target,val));
                }
            }
            else{
                if(prev != s.end())
                {
                    while(prev != s.end())
                    {
                        prev->second = next->second;
                        prev = s.find(prev->first - 1);
                    }
                    s.insert(make_pair(target,prev->second));
                }
                else s.insert(make_pair(target,next->second));
            }
        }
        for(auto iter=s.begin();iter!=s.end();iter++)
        {
            //printf("%lld %lld/",iter->first,*(iter->second));
        }
        //printf("\n");
    }
    return answer;
}
