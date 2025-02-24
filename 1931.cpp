#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> meetings(n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        meetings[i] = make_pair(a,b);
    }
    sort(&meetings[0],&meetings[n],cmp);
    int curTime = 0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(meetings[i].first >= curTime)
        {
            curTime = meetings[i].second;
            cnt++;
        }
    }
    printf("%d",cnt);
}