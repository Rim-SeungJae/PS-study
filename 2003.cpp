#include<cstdio>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[10001];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int l=0,r=0,cnt=0;
    int sum = arr[0];
    while(l<=r && r<n)
    {
        printf("%d %d\n",l,r);
        if(sum <= m)
        {
            if(sum == m) cnt++;
            r++;
            if(r>=n) break;
            sum += arr[r];
        }
        else{
            sum -= arr[l];
            l++;
            if(l>=n) break;
        }
    }
    printf("%d",cnt);
}