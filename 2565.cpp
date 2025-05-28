#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    sort(arr.begin(), arr.end());
    vector<int> dp;
    dp.push_back(arr[0].second);
    for(int i=1;i<n;i++)
    {
        if(arr[i].second > dp.back())
        {
            dp.push_back(arr[i].second);
        }
        else
        {
            auto it = lower_bound(dp.begin(), dp.end(), arr[i].second);
            *it = arr[i].second;
        }
    }
    printf("%d\n", n - dp.size());
}