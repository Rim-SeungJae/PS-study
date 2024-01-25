#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>

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
        int n,m;
        cin >> n >> m;
        int c1,c2;
        cin >> c1 >> c2;
        vector<int> v1(n);
        vector<int> v2(m);
        set<int> s2;
        for(int i=0;i<n;i++) cin >> v1[i];
        for(int i=0;i<m;i++) cin >> v2[i];
        sort(v2.begin(),v2.end());
        
        int min = 999999999, cnt = 0;
        for(int i=0;i<v1.size();i++)
        {
            int target = v1[i];
            int l = 0,r = v2.size()-1;
            while(l<=r)
            {
                int mid = l + (r - l)/2;
                if(v2[mid] == target)
                {
                    if(min == 0) cnt++;
                    else{
                        min = 0;
                        cnt =1;
                    }
                    break;
                }
                else if(v2[mid] > target)
                {
                    r = mid - 1;
                    if(min == v2[mid] - target) cnt++;
                    else if(min > v2[mid] - target)
                    {
                        min = v2[mid] - target;
                        cnt = 1;
                    }
                }
                else
                {
                    l = mid + 1;
                    if(min == target - v2[mid]) cnt++;
                    else if(min > target - v2[mid])
                    {
                        min = target - v2[mid];
                        cnt = 1;
                    }
                }
            }
        }
        
        cout << '#' << test_case << ' ' << min + abs(c1-c2) << ' ' << cnt << '\n';
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}