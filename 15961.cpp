#include<cstdio>
#include<unordered_set>
#include<vector>

using namespace std;

int main()
{
    int n,d,k,c;
    scanf("%d %d %d %d",&n,&d,&k,&c);
    vector<int> cnt(d+1,0);
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        v.push_back(tmp);
    }
    int total=0;
    for(int i=0;i<k;i++)
    {
        if(cnt[v[i]] == 0) total++;
        cnt[v[i]]++;
    }
    if(cnt[c] == 0) total++;
    cnt[c]++;
    int max = total;
    int l=0,r=k-1;
    if(cnt[v[l]] == 1)
    {
        total--;
    }
    cnt[v[l++]]--;
    cnt[v[++r]]++;
    if(cnt[v[r]] == 1)
    {
        total++;
    }
    while(l!=0)
    {
        if(total > max) max = total;
        if(cnt[v[l]] == 1)
        {
            total--;
        }
        cnt[v[l++]]--;
        l %= n;
        cnt[v[(++r)%n]]++;
        r %= n;
        if(cnt[v[r]] == 1)
        {
            total++;
        }
    }
    printf("%d",max);
}