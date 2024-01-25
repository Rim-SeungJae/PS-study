#include<iostream>
#include<queue>
#include<algorithm>
#include<array>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int test_case;
	int T;
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
        int n,a[11],k;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        cin >> k;
        /*
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push(make_pair(0,make_pair(1,0)));
        int result;
        while(!pq.empty())
        {
            auto tmp = pq.top();
            int dist = tmp.first, d = tmp.second.first, x = tmp.second.second;
            if(x == k)
            {
                result = dist;
                break;
            }
            pq.pop();
            pq.push(make_pair(dist+1,make_pair(d,x+d)));
            for(int i=0;i<n;i++)
            {
                if((long long)d * a[i] + x <= k && (k-x)%(d*a[i]) == 0 ) pq.push(make_pair(dist,make_pair(d * a[i],x)));
            }
        }
        */
       
        int result;
        deque<array<int,3>> dq;
        array<int,3> arr = {0,1,0};
        dq.push_back(arr);
        while(!dq.empty())
        {
            auto tmp = dq.front();
            dq.pop_front();
            int dist = tmp[0], d = tmp[1], x = tmp[2];
            if(x == k)
            {
                result = dist;
                break;
            }
            dq.push_back(array<int,3>({dist+1,d,x+d}));
            for(int i=0;i<n;i++)
            {
                if((long long)d * a[i] + x <= k && (k-x)%(d*a[i]) == 0)
                {
                    dq.push_front(array<int,3>({dist,d*a[i],x}));
                }
            }

        }
        
        cout << '#' <<test_case << ' ' << result << '\n';
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}