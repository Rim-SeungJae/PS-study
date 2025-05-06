#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,h;
    scanf("%d %d",&n,&h);
    vector<int> top(n/2),bottom(n/2);
    for(int i=0;i<n/2;i++)
    {
        scanf("%d",&bottom[i]);
        scanf("%d",&top[i]);
    }
    sort(bottom.begin(),bottom.end());
    sort(top.begin(),top.end());
    
    int min = 2000000000;
    int routes = 0;
    for(int i=0;i<h;i++)
    {
        int cnt=0;
        int l=0,r=n/2-1;
        int tmp=0;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(bottom[mid] < i+1)
            {
                l = mid+1;
                continue;
            }
            else{
                tmp = n/2-mid;
                r = mid-1;
                continue;
            }
        }
        cnt += tmp;
        tmp=0;
        l=0,r=n/2-1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(h-top[mid] > i)
            {
                l = mid+1;
                continue;
            }
            else{
                tmp = n/2-mid;
                r = mid-1;
                continue;
            }
        }
        cnt += tmp;
        if(cnt < min)
        {
            min = cnt;
            routes=1;
        }
        else if(cnt == min)
        {
            routes++;
        }
    }

    printf("%d %d",min,routes);

}