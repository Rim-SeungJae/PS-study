#include<cstdio>
#include<vector>

using namespace std;

bool check(vector<vector<bool>>& plane, int x, int y, int k) {
    for (int l = 0; l <= k; l++) {
        for (int m = 0; m <= k; m++) {
            if (x + l >= 10 || y + m >= 10 || plane[x + l][y + m] == 0) return false;
        }
    }
    return true;
}

int Min = 1000000000;

void bt(vector<vector<bool>>& plane,vector<int>& cnt)
{
    bool is_zero = true;
    int sum = 0;
    for(int i=0;i<5;i++) sum+=cnt[i];
    if(sum >= Min) return;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(plane[i][j])
            {
                is_zero = false;
                for(int k=0;k<5;k++)
                {
                    if(i+k<10 && j+k<10 && cnt[k]<5 && check(plane,i,j,k))
                    {
                        for(int ii=i;ii<=i+k;ii++)
                        {
                            for(int jj=j;jj<=j+k;jj++) plane[ii][jj] = 0;
                        }
                        cnt[k] += 1;
                        bt(plane,cnt);
                        cnt[k] -= 1;
                        for(int ii=i;ii<=i+k;ii++)
                        {
                            for(int jj=j;jj<=j+k;jj++) plane[ii][jj] = 1;
                        }
                    }
                }
                return;
            }
        }
    }
    if(is_zero && Min>sum)
    {
        Min = sum;
    }
}

int main()
{
    vector<vector<bool>> plane(10,vector<bool>(10,0));
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            plane[i][j] = tmp;
        }
    }
    vector<int> cnt(5,0);
    bt(plane,cnt);
    if(Min == 1000000000) printf("-1");
    else printf("%d",Min);
}