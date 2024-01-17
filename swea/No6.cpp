#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Node{
	public:
	int lc=0,rc=0,p=0,h=0,sub_size=0;
};

bool is_number(string str)
{
	if(str.size()==0) return false;
	int i;
	for(i=0;i<str.size();i++) if(!isdigit(str[i])) break;
	if(i==str.size()) return true;
	return false;
}

int init(int idx, Node * tree)
{
	tree[idx].h = tree[tree[idx].p].h+1;
	if(tree[idx].lc == 0) return tree[idx].sub_size = 1;
	else if(tree[idx].rc == 0) return tree[idx].sub_size = init(tree[idx].lc,tree) + 1;
	return tree[idx].sub_size = init(tree[idx].lc,tree) + init(tree[idx].rc,tree) + 1;
}

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
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        Node tree[10100];
		//int parent[10100][14];
        int v,e,x,y;
		cin >> v >> e >> x >> y;
		for(int i=0;i<e;i++)
		{
			int p,c;
			cin >> p >> c;
			if(tree[p].lc==0)
			{
				tree[p].lc = c;
				tree[c].p = p;
				//parent[c][0] = p;
				//tree[c].h = tree[p].h+1;
			}
			else
			{
				tree[p].rc = c;
				tree[c].p = p;
				//parent[c][0] = p;
				//tree[c].h = tree[p].h+1;
			}
		}
		init(1,tree);
		if(tree[x].h>tree[y].h) swap(x,y);
		while(tree[y].h!=tree[x].h)
		{
			y = tree[y].p;
		}
		while(x!=y)
		{
			x = tree[x].p;
			y = tree[y].p;
		}
        cout << '#' << test_case << ' ';
        cout << x << ' ' << tree[x].sub_size << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}