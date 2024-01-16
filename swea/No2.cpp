#include<iostream>
#include<list>
#include<iterator>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n,m,l;
        cin >> n >> m >> l;
        list<int> lt;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            lt.push_back(tmp);
        }
        for(int i=0;i<m;i++)
        {
            char cmd;
            cin >> cmd;

            if(cmd == 'I')
            {
                int x,y;
                cin >> x >> y;
                auto it = lt.begin();
                advance(it,x);
                lt.insert(it,y);

            }
            if(cmd == 'D')
            {
                int x;
                cin >> x;
                auto l = lt.begin();
                advance(l,x);
                lt.erase(l);
            }
            if(cmd == 'C')
            {
                int x,y;
                cin >> x >> y;
                auto it = lt.begin();
                advance(it,x);
                *it = y;
            }
            /*
            for(auto iter=lt.begin();iter!=lt.end();iter++)
            {
                cout << ' ' << *iter;
            }
            cout << '\n';
            */
        }
        int cnt=0;
        auto iter=lt.begin();
        for(;iter!=lt.end();iter++)
        {
            if(cnt==l) break;
            cnt++;
        }
        cout << '#' << test_case << ' ';
        if(iter == lt.end())
        {
            cout << -1 << '\n';
        }
        else{
            cout << *iter << '\n';
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}