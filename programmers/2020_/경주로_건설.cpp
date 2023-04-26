#include <string>
#include <vector>
#include <queue>

using namespace std;

int n;

const int dirr[4] = {0,1,0,-1}, dirc[4] = {1,0,-1,0};

struct Node{
    int r,c,d,cost;
};

bool inRange(int a)
{
    return a>=0 && a<n;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    queue<Node> q;
    vector<vector<int>> visited[4];
    for(int i=0;i<4;i++) visited[i].assign(n,vector<int>(n,0));
    Node init;
    init.r = 0;
    init.c = 0;
    init.d = 0;
    init.cost = 0;
    q.push(init);
    init.d = 1;
    q.push(init);
    visited[0][0][0] = visited[1][0][0]= visited[2][0][0]= visited[3][0][0]= 1;
    while(!q.empty())
    {
        Node cur = q.front();
        Node next;
        q.pop();
        for(int i=0;i<4;i++)
        {
            //if((i+2)%4 == cur.d) continue;
            if(inRange(cur.r+dirr[i]) && inRange(cur.c+dirc[i]) && !board[cur.r+dirr[i]][cur.c+dirc[i]] && (visited[i][cur.r+dirr[i]][cur.c+dirc[i]] == 0 || visited[i][cur.r+dirr[i]][cur.c+dirc[i]]>cur.cost+(i!=cur.d?600:100)) )
            {
                visited[i][cur.r+dirr[i]][cur.c+dirc[i]] = cur.cost+(i!=cur.d?600:100);
                next.r = cur.r+dirr[i];
                next.c = cur.c+dirc[i];
                next.d = i;
                next.cost = cur.cost+(i!=cur.d?600:100);
                q.push(next);
            }
        }
    }
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",visited[1][i][j]);
        }
        printf("\n");
    }
    */
    if(visited[0][n-1][n-1]!=0 && visited[1][n-1][n-1]!=0)
    {
        answer = (visited[0][n-1][n-1]<visited[1][n-1][n-1]?visited[0][n-1][n-1]:visited[1][n-1][n-1]);
    }
    else if(visited[0][n-1][n-1]==0) answer = visited[1][n-1][n-1];
    else answer = visited[0][n-1][n-1];
    return answer;
}
