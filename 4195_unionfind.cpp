#include<cstdio>
#include<unordered_map>
#include<string>

using namespace std;

int num,parent[200001],h[200001],cnt[200001];

int find(int a)
{
    if(parent[a] != a) parent[a] = find(parent[a]);
    return parent[a];
}

void uni(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(h[a] > h[b])
    {
        parent[b] = a;
        cnt[a] += cnt[b];
    }
    else if(h[a] == h[b])
    {
        parent[b] = a;
        h[a]++;
        cnt[a] += cnt[b];
    }
    else{
        parent[a] = b;
        cnt[b] += cnt[a];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        num = 0;
        int f;
        scanf("%d",&f);
        /*
        for(int i=0;i<f;i++)
        {
            parent[i] = i;
            h[i] = 0;
            cnt[i] = 1;
        }
        */
        unordered_map<string,int> name2idx;
        for(int i=0;i<f;i++)
        {
            char tmp1[22],tmp2[22];
            string a,b;
            scanf("%s %s",tmp1,tmp2);
            a = string(tmp1);
            b = string(tmp2);
            if(name2idx.find(a) == name2idx.end())
            {
                name2idx.insert(make_pair(a,num));
                parent[num] = num;
                h[num] = 0;
                cnt[num] = 1;
                num++;
            }
            if(name2idx.find(b) == name2idx.end())
            {
                name2idx.insert(make_pair(b,num));
                parent[num] = num;
                h[num] = 0;
                cnt[num] = 1;
                num++;
            }
            int a_idx = (*name2idx.find(a)).second;
            int b_idx = (*name2idx.find(b)).second;
            uni(a_idx,b_idx);
            printf("%d\n",cnt[find(a_idx)]);
        }
    }
}