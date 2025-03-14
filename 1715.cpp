#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int n;
    priority_queue<int> pq;
    long long cnt = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        pq.push(-tmp);
    }
    while(pq.size()>1)
    {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        cnt += a+b;
        pq.push(-(a+b));
    }
    printf("%lld",cnt);
}