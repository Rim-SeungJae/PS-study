#include<iostream>

using namespace std;

int arr[100010],seg_min[400040],seg_max[400040];

void init_min(int idx,int l,int r)
{
    if(l == r)
    {
        seg_min[idx] = arr[l];
        return;
    }
    int mid = l+(r-l)/2;
    init_min(2*idx,l,mid);
    init_min(2*idx+1,mid+1,r);
    seg_min[idx] = min(seg_min[2*idx],seg_min[2*idx+1]);
}

void init_max(int idx,int l,int r)
{
    if(l == r)
    {
        seg_max[idx] = arr[l];
        return;
    }
    int mid = l+(r-l)/2;
    init_max(2*idx,l,mid);
    init_max(2*idx+1,mid+1,r);
    seg_max[idx] = max(seg_max[2*idx],seg_max[2*idx+1]);
}

void update_min(int target,int idx,int l,int r,int val)
{
    if(l>target || r<target) return;
    if(l == r)
    {
        seg_min[idx] = val;
        return;
    }
    int mid = l+(r-l)/2;
    update_min(target,2*idx,l,mid,val);
    update_min(target,2*idx+1,mid+1,r,val);
    seg_min[idx] = min(seg_min[2*idx],seg_min[2*idx+1]);
}

void umin(int target,int idx,int l,int r,int val)
{
    update_min( target, idx, l, r, val);
    arr[target] = val;
}

void update_max(int target,int idx,int l,int r,int val)
{
    if(l>target || r<target) return;
    if(l == r)
    {
        seg_max[idx] = val;
        return;
    }
    int mid = l+(r-l)/2;
    update_max(target,2*idx,l,mid,val);
    update_max(target,2*idx+1,mid+1,r,val);
    seg_max[idx]= max(seg_max[2*idx],seg_max[2*idx+1]);
}

void umax(int target,int idx,int l,int r,int val)
{
    update_max( target, idx, l, r, val);
    arr[target] = val;
}

int get_min(int begin,int end,int idx,int l,int r)
{
    if(l>end || r<begin) return 2000000000;
    if(begin<=l && r<=end) return seg_min[idx];
    int mid = l+(r-l)/2;
    return min(get_min(begin,end,2*idx,l,mid),get_min(begin,end,2*idx+1,mid+1,r));
}

int get_max(int begin,int end,int idx,int l,int r)
{
    if(l>end || r<begin) return -2000000000;
    if(begin<=l && r<=end) return seg_max[idx];
    int mid = l+(r-l)/2;
    return max(get_max(begin,end,2*idx,l,mid),get_max(begin,end,2*idx+1,mid+1,r));
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
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n,q;
        cin >> n >> q;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        init_max(1,0,n-1);
        init_min(1,0,n-1);
        cout << '#' << test_case;
        for(int i=0;i<q;i++)
        {
            int cmd;
            cin >> cmd;
            if(cmd == 0)
            {
                int idx,x;
                cin >> idx >> x;
                umin(idx,1,0,n-1,x);
                umax(idx,1,0,n-1,x);
            }
            else{
                int l,r;
                cin >> l >> r;
                cout << ' ' << get_max(l,r-1,1,0,n-1) - get_min(l,r-1,1,0,n-1);
            }
        }
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}