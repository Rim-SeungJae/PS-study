#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int h,w;
    scanf("%d %d",&h,&w);
    int arr[505],water[505] = {0,};
    for(int i=0;i<w;i++) scanf("%d",&arr[i]);
    int highest = arr[0];
    for(int i=0;i<w;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j] >= min(arr[i],highest)) break;
            water[j] = min(arr[i],highest) - arr[j];
        }
        if(arr[i] > highest) highest = arr[i];
    }
    int sum=0;
    for(int i=0;i<w;i++) sum+=water[i];
    printf("%d",sum);
}