#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    vector<int> road;
    vector<int> oil;
    int min,n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        road.push_back(tmp);
    }
    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        oil.push_back(tmp);
    }
    long long int sum=0;
    min = 2000000000;
    for(int i=0;i<n-1;i++)
    {
        if(min>oil[i]) min = oil[i];
        sum+=(long long)min*road[i];
    }
    printf("%lld",sum);
}