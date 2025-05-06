#include <cstdio>
#include <vector>
#include <algorithm>
#include<unordered_map>

using namespace std;

unordered_map<int,int> um;
vector<int> a;

void increment(int val)
{
    auto target = um.find(val);
    if(target == um.end())
    {
        um[val] = 1;
    }
    else{
        (*target).second++;
    }
}

void decrement(int val)
{
    auto target = um.find(val);
    (*target).second--;
    if((*target).second == 0)
    {
        um.erase(target);
    }

}

int main()
{
    int n,d,k,c;
    scanf("%d %d %d %d",&n,&d,&k,&c);
    a.assign(n,0);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int l=0,r=k-1;
    for(int i=l;i<=r;i++)
    {
        increment(a[i]);
    }
    increment(c);
    int max = um.size();
    for(int i=0;i<n;i++)
    {
        decrement(a[l]);
        l++;
        r++;
        l%=n;
        r%=n;
        increment(a[r]);
        if(max < um.size()) max = um.size();
    }
    printf("%d",max);
}