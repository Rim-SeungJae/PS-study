#include <iostream>
using namespace std;
int main(){
    long long n;
    long long num = 1;
    int cnt = 1;
    while(cin >> n){
        num = 1;
        cnt = 1;
        while(1){
            num = num % n;
            if(num == 0){
                break;
            }
            num = (num * 10)%n + 1%n;
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
/*
백준 4375
1로 이루어진 배수 찾기. (n*10+1)%n == ((n*10)%n + 1%n)%n 임을 이용,
오버플로우가 나지 않도록 제어하는 것이 핵심. 
*/ 
