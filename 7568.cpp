#include<cstdio>
#include<vector>
#include<algorithm>
#include<tuple>

using namespace std;

int main()
{
    vector<pair<int,int>> v;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v.push_back(make_pair(x,y));
    }

    for(int i=0;i<n;i++)
    {
        int cnt = 0;
        for(int j=0;j<n;j++)
        {
            if(v[i].first < v[j].first && v[i].second < v[j].second) cnt++;
        }
        printf("%d ",cnt+1);
    }
}