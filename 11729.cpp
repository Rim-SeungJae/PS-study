#include<cstdio>

using namespace std;

void hanoi(int k,int src,int dst,int empty)
{
    if(k <= 0) return;
    hanoi(k-1,src,empty,dst);
    printf("%d %d\n",src,dst);
    hanoi(k-1,empty,dst,src);
}

int cnt(int k)
{
    if(k==1) return 1;
    return cnt(k-1) * 2 + 1;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",cnt(n));
    hanoi(n,1,3,2);
}