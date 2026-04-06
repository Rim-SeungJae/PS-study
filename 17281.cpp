#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int>> players(n,vector<int>(9,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<9;j++) scanf("%d",&players[i][j]);
    }

    vector<int> order = {0,1,2,3,4,5,6,7,8};

    int mx = 0;

    do
    {
        if(order[3]!=0) continue;
        auto cur = order.begin();
        int score = 0;
        for(int i=0;i<n;i++)
        {
            int out = 0;
            bool roo[4] = {0,};
            while(out<3)
            {
                if(players[i][*cur] == 0)
                {
                    out++;
                }
                else{
                    roo[0] = true;
                    for(int j=3;j>=0;j--)
                    {
                        if(!roo[j]) continue;
                        int tmp = j+players[i][*cur];
                        roo[j] = false;
                        if(tmp>3) score++;
                        else roo[tmp] = true;
                    }
                }
                if(cur == order.end()-1) cur = order.begin();
                else cur++;
            }
        }

        mx = max(mx,score);

    }while(next_permutation(order.begin(),order.end()));

    printf("%d",mx);
}