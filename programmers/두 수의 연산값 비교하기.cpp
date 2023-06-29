#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0,tmp1,tmp2;
    tmp1 = atoi((to_string(a) + to_string(b)).c_str());
    tmp2 = 2 * a * b;
    answer = (tmp1>tmp2?tmp1:tmp2);
    return answer;
}
