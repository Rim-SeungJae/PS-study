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
���� 4375
1�� �̷���� ��� ã��. (n*10+1)%n == ((n*10)%n + 1%n)%n ���� �̿�,
�����÷ο찡 ���� �ʵ��� �����ϴ� ���� �ٽ�. 
*/ 
