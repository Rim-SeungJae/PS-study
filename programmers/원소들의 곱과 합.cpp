#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int mult = 1;
    int sum = 0;
    for(int i=0;i<num_list.size();i++)
    {
        mult *= num_list[i];
    }
    for(int i=0;i<num_list.size();i++)
    {
        sum += num_list[i];
    }
    sum *= sum;
    answer = mult < sum;
    return answer;
}
