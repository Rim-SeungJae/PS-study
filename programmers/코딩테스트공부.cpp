#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 2000000000;
    int alp_req_max = 0, cop_req_max = 0;
    for(int i=0;i<problems.size();i++)
    {
        if(alp_req_max < problems[i][0]) alp_req_max = problems[i][0];
        if(cop_req_max < problems[i][1]) cop_req_max = problems[i][1];
    }
    int dp[400][400];
    fill(&dp[0][0],&dp[399][400],2000000000);
    dp[alp][cop] = 0;
    for(int i=alp;i<=300;i++)
    {
        for(int j=cop;j<=300;j++)
        {
            if(i==alp&&j==cop) continue;
            if(i>alp && dp[i][j] > dp[i-1][j] + 1) dp[i][j] = dp[i-1][j] + 1;
            if(j>cop && dp[i][j] > dp[i][j-1] + 1) dp[i][j] = dp[i][j-1] + 1;
            for(int k = 0;k<problems.size();k++)
            {
                int alp_req = problems[k][0],cop_req = problems[k][1],alp_rwd = problems[k][2],cop_rwd = problems[k][3],cost = problems[k][4];
                if(i - alp_rwd >= alp_req && j - cop_rwd >= cop_req && dp[i][j] > dp[i-alp_rwd][j-cop_rwd] + cost) dp[i][j] = dp[i-alp_rwd][j-cop_rwd] + cost;
            }
        }
    }
    for(int i=alp_req_max;i<=300;i++)
    {
        for(int j=cop_req_max;j<=300;j++)
        {
            if(answer > dp[i][j]) answer = dp[i][j];
        }
    }
    return answer;
}