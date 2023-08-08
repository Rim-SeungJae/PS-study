#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = 0;
    for(int i=0;i<control.length();i++)
    {
        switch(control[i])
        {
            case 'w':
                n++;
                break;
            case 's':
                n--;
                break;
            case 'a':
                n-=10;
                break;
            case 'd':
                n+=10;
                break;
        }
    }
    answer = n;
    return answer;
}
