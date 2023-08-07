#include <string>
#include <vector>
#include <deque>

using namespace std;

string toLower(string a)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] += 'a' - 'A';
        }
    }
    return a;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;
    for(int i=0;i<cities.size();i++)
    {
        string cur = toLower(cities[i]);
        auto iter = dq.begin();
        for(;iter!=dq.end();++iter)
        {
            if(*iter == cur)
            {
                answer+=1;
                dq.erase(iter);
                dq.push_back(cur);
                break;
            }
        }
        if(iter == dq.end())
        {
            answer+=5;
            dq.push_back(cur);
        }
        if(dq.size() > cacheSize) dq.pop_front();
    }
    return answer;
}
/*
쉬운 구현
*/ 
