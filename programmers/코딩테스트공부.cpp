#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 2000000000;
    int alp_req_max = alp, cop_req_max = cop;
    for(int i=0;i<problems.size();i++)
    {
        if(alp_req_max < problems[i][0]) alp_req_max = problems[i][0];
        if(cop_req_max < problems[i][1]) cop_req_max = problems[i][1];
    }
    int dp[200][200];
    fill(&dp[0][0],&dp[199][200],2000000000);
    dp[alp][cop] = 0;
    for(int i=alp;i<=alp_req_max;i++)
    {
        for(int j=cop;j<=cop_req_max;j++)
        {
            int x,y;
            x = min(alp_req_max,i+1);
            if(dp[x][j] > dp[i][j] + 1)
            {
                dp[x][j] = dp[i][j] + 1;
            }
            y = min(cop_req_max,j+1);
            if(dp[i][y] > dp[i][j] + 1)
            {
                dp[i][y] = dp[i][j] + 1;
            }
            for(int k = 0;k<problems.size();k++)
            {
                int alp_req = problems[k][0],cop_req = problems[k][1],alp_rwd = problems[k][2],cop_rwd = problems[k][3],cost = problems[k][4];
                x = min(alp_req_max,i + alp_rwd);
                y = min(cop_req_max,j + cop_rwd);
                if(dp[x][y] > dp[i][j] + cost && i>=alp_req && j>=cop_req)
                {
                    dp[x][y] = dp[i][j] + cost;
                }
            }
        }
    }
    answer = dp[alp_req_max][cop_req_max];
    return answer;
}

int main()
{
    vector<vector<int>> problems({{10,15,2,1,2},{20,20,3,3,4}});
    printf("%d ",solution(10,10,problems));
}