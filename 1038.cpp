#include<cstdio>
#include<queue>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n==0)
    {
        printf("0");
    }
    else{
        queue<long long int> q;
        for(int i=1;i<10;i++)
        {
            q.push(i);
        }
        int cnt = 1;
        long long ans = -1;
        while(!q.empty())
        {
            long long int num = q.front();
            q.pop();
            if(cnt == n)
            {
                ans = num;
                break;
            }
            int last_digit = num%10;
            for(int i=0;i<last_digit;i++)
            {
                q.push(num*10 + i);
            }
            cnt++;
        }
        printf("%lld",ans);
    }
}