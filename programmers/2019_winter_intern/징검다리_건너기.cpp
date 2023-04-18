#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer;
    int area_max = 0;
    multiset<int> ms;
    
    for(int j=0;j<k;j++)
    {
        ms.insert(stones[j]);
    }
    answer = *ms.rbegin();
    int left = 0, right = k-1;
    while(right < stones.size()-1)
    {
        auto p = ms.find(stones[left]);
        ms.erase(p);
        ms.insert(stones[right+1]);
        left++;
        right++;
        if(*ms.rbegin()<answer) answer = *ms.rbegin();
    }
    return answer;
}
/*
연관컨테이너는 값을 단순 저장만 하는 것이 아니라,
항상 정렬된 결과를 얻을 수 있다는 사실을 기억하자
*/ 
