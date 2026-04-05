#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int life[22],joy[22];
    for(int i=1;i<=n;i++) scanf("%d",&life[i]);
    for(int i=1;i<=n;i++) scanf("%d",&joy[i]);
    int ks[100] = {0,};


    for(int i=1;i<=n;i++)
    {
        for(int j=99;j>=0;j--)
        {
            if(j-life[i]>=0)ks[j] = max(ks[j-life[i]] + joy[i], ks[j]);
        }
    }
    printf("%d",ks[99]);
}