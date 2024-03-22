#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1,0,0,-1}, dy[4] = {0,-1,1,0};
string dd[4] = {"d","l","r","u"},rdd[4] = {"u","r","l","d"};

string result = "";

void dfs(int n, int m, int curx, int cury, int r, int c, int k,string d)
{
    if(result.length() != 0) return;
    if(k - d.length() < abs(curx-r) + abs(cury-c)) return;
    if(d.length() == k)
    {
        if(curx == r && cury == c) result = d;
        return;
    }
    for(int i=0;i<4;i++)
    {
        if(curx+dx[i]>=0 && curx+dx[i]<n && cury+dy[i]>=0 && cury+dy[i]<m)
        {
            d.append(dd[i]);
            dfs(n,m,curx+dx[i],cury+dy[i],r,c,k,d);
            if(result.length() != 0) return;
            d.pop_back();
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int cnt = k - abs(x-r) - abs(y-c);
    if(cnt<0 || cnt%2!=0) return "impossible";
    dfs(n,m,x-1,y-1,r-1,c-1,k,"");
    answer = result;
    if(answer.length() == 0) answer = "impossible";
    return answer;
}

int main()
{
    printf("%s",solution(3, 	4, 	2, 	3, 	3, 	1, 	5).c_str());
}