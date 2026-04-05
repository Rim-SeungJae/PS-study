#include<cstdio>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    vector<tuple<int,int,int>> v;
    tuple<int,int,int> target;
    for(int i=0;i<n;i++)
    {
        int a,b,c,ct;
        scanf("%d %d %d %d",&ct,&a,&b,&c);
        tuple<int,int,int> tp = make_tuple(a,b,c);
        v.push_back(tp);

        if(ct == k)
        {
            target = tp;
        }
    }

    sort(v.begin(),v.end(),greater<tuple<int,int,int>>());

    for(int i=0;i<v.size();i++)
    {
        if(v[i] == target)
        {
            printf("%d",i+1);
            return 0;
        }
    }
}