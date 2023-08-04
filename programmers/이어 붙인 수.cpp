#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int odd=0,even=0;
    for(auto i=num_list.begin();i!=num_list.end();i++)
    {
        if(*i%2==0)
        {
            even *= 10;
            even += *i;
        }
        else{
            odd *= 10;
            odd += *i;
        }
    }
    answer = odd + even;
    return answer;
}
