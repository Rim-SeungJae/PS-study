#include<cstdio>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
    int g;
    scanf("%d",&g);
    int l=1,r=1;
    set<int> s;
    for(int i=1;i<=g;i++)
    {
        if((g + i * i)%(2*i) == 0 && (g + i * i)/(2*i) - i>0) s.insert((g + i * i)/(2*i));
    }
    for(auto iter=s.begin();iter!=s.end();iter++)
    {
        printf("%d\n",*iter);
    }
    if(s.empty()) printf("-1");
}