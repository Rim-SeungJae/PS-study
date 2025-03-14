#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main()
{
    int arr[10001];
    int n;
    scanf("%d",&n);
    unordered_map<int,int> um;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        auto pos = um.find(arr[i]);
        if(pos != um.end())
        {
            (*pos).second = (*pos).second + 1;
        }
        else{
            um.insert(make_pair(arr[i],1));
        }
    }
    vector<int> v(arr,arr+n);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int ans = 0;
    for(int i=0;i<v.size();i++)
    {
        int target = -v[i];
        int l=0,r=v.size()-1;
        while(l<=r)
        {
            if(l == i && um)
            {
                l++;
                continue;
            }
            if(r == i)
            {
                r--;
                continue;
            }
            if(l == r && um[l] < 2)
            {
                break;
            }
            if(v[l] + v[r] == target)
            {
                ans+=um[v[l]] * um[v[r]] * um[v[i]];
                r--;
                l++;
            }
            else if(v[l] + v[r] > target)
            {
                r--;
            }
            else{
                l++;
            }
        }
    }
    ans/=3;
    printf("%d",ans);
}