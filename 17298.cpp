#include<cstdio>
#include<vector>
#include<cmath>
#include<stack>

using namespace std;

int A[1000001],NGE[1000001]={0,};

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    stack<pair<int,int>> s;
    s.push(make_pair(A[0],0));
    for(int i=1;i<n;i++)
    {
        pair<int,int> cur = s.top();
        while(cur.first < A[i])
        {
            NGE[cur.second] = A[i];
            s.pop();
            if(s.empty()) break;
            cur = s.top();
        }
        s.push(make_pair(A[i],i));
    }
    for(int i=0;i<n;i++)
    {
        if(NGE[i] == 0) printf("-1 ");
        else printf("%d ",NGE[i]);
    }
}