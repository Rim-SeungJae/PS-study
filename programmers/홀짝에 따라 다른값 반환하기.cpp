#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++)
    {
        answer += (i%2 == n%2) * (i%2==0?i*i:i);
    }
    return answer;
}
