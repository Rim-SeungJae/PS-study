#include <string>
#include <vector>

using namespace std;

int solution(int number, int n, int m) {
    int answer = 0;
    answer = number%n==0 && number%m==0;
    return answer;
}
