#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    char arr[100001];
    int cnt[26]={0,},alphas = 0;
    scanf("%s",arr);
    int len = strlen(arr);
    int l=0,r=0;
    cnt[arr[0] - 'a']++;
    alphas++;
    int maxLen = 0;
    while(l<=r && r<len)
    {
        if(alphas<=n)
        {
            if(maxLen < r-l+1) maxLen = r-l+1;
            r++;
            if(r>=len) break;
            cnt[arr[r] - 'a']++;
            if(cnt[arr[r] - 'a'] == 1) alphas++;
        }
        else
        {
            cnt[arr[l] - 'a']--;
            if(cnt[arr[l] - 'a'] == 0) alphas--;
            l++;
        }
    }
    printf("%d",maxLen);
}