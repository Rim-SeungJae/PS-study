#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<cmath>

using namespace std;
using ii = pair<int,int>;

vector<int> parent;

void Union(int a,int b)
{
    parent[b] = a;
}

int Find(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++) parent.push_back(i);
    vector<pair<double,double>> stars;
    for(int i=0;i<n;i++)
    {
        double tmp1,tmp2;
        scanf("%lf %lf",&tmp1,&tmp2);
        stars.push_back(make_pair(tmp1,tmp2));
    }
    priority_queue<tuple<double,int,int>> pq;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            double dist = sqrt(pow(stars[i].first - stars[j].first,2) + pow(stars[i].second - stars[j].second,2));
            pq.push(make_tuple(-dist,i,j));
        }
    }
    double ans = 0;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        double c;
        c = -get<0>(pq.top());
        a = get<1>(pq.top());
        b = get<2>(pq.top());
        pq.pop();

        a = Find(a);
        b = Find(b);
        if(a == b)
        {
            i--;
            continue;
        }
        else
        {
            Union(a,b);
            ans += c;
        }
    }
    printf("%.2lf",ans);

}