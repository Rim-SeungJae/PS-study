#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int solution(int a, int b) {
    int answer = 0,tmp1,tmp2;
    string str;
    str = to_string(a) + to_string(b);
    tmp1 = atoi(str.c_str());
    str = to_string(b) + to_string(a);
    tmp2 = atoi(str.c_str());
    answer = (tmp1>tmp2?tmp1:tmp2);
    return answer;
}
