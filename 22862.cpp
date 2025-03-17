#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> s(n);
    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        s[i] = tmp;
    }
    int l,r,maxLen=0,eraseCnt=k;
    l = r = 0;
    if(s[l]%2!=0) eraseCnt--;
    while(l<=r && r<n)
    {
        if(eraseCnt>=0)
        {
            if(r-l+1-k+eraseCnt>maxLen) maxLen = r-l+1-k+eraseCnt;
            r++;
            if(s[r]%2!=0) eraseCnt--;
        }
        else
        {
            if(s[l]%2!=0) eraseCnt++;
            l++;
        }
    }
    printf("%d",maxLen);
}