#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, bool flag) {
    int answer = 0;
    answer = a + (flag?1:-1) * b;
    return answer;
}
