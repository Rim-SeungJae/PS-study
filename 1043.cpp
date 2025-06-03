#include<cstdio>
#include<vector>
#include<unordered_set>

using namespace std;

int main()
{
    int n,m;
    unordered_set<int> us;
    scanf("%d %d",&n,&m);
    int tmp;
    scanf("%d",&tmp);
    vector<int> smart(tmp);
    for(int i=0;i<tmp;i++)
    {
        scanf("%d",&smart[i]);
        us.insert(smart[i]);
    }
    vector<vector<int>> party(m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&tmp);
        party[i].assign(tmp,0);
        for(int j=0;j<tmp;j++)
        {
            scanf("%d",&party[i][j]);
        }
    }

    int prv_cnt = us.size(), cur_cnt = us.size();
    do
    {
        prv_cnt = cur_cnt;
        for(int i=0;i<party.size();i++)
        {
            bool is_smart = false;
            for(int j=0;j<party[i].size();j++)
            {
                if(us.find(party[i][j]) != us.end())
                {
                    is_smart = true;
                    break;
                }
            }
            if(is_smart)
            {
                for(int j=0;j<party[i].size();j++)
                {
                    us.insert(party[i][j]);
                }
            }
        }
        cur_cnt = us.size();
    }while(prv_cnt != cur_cnt);

    int ans = 0;
    for(int i=0;i<party.size();i++)
    {
        bool is_smart = false;
        for(int j=0;j<party[i].size();j++)
        {
            if(us.find(party[i][j]) != us.end())
            {
                is_smart = true;
                break;
            }
        }
        if(!is_smart) ans++;
    }
    printf("%d",ans);
}