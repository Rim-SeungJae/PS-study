#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
using ii = pair<int,int>;

int main()
{
    int x;
    while(scanf("%d",&x) != EOF)
    {
        x *= 10000000;
        int n;
        scanf("%d",&n);
        vector<int> sticks;
        for(int i=0;i<n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            sticks.push_back(tmp);
        }
        sort(sticks.begin(),sticks.end());
        int l=0,r=n-1;
        while(l<r)
        {
            if(x == sticks[r] + sticks[l])
            {
                printf("yes %d %d\n",sticks[l],sticks[r]);
                break;
            }
            else if(x < sticks[r] + sticks[l]) r--;
            else l++;
        }
        if(l>=r)
        {
            printf("danger\n");
        }
    }
}