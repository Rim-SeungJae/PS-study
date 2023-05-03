#include <string>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

struct Node{
    int active,left,right;
    Node(int a,int b,int c)
    {
        active = a;
        left = b;
        right = c;
    }
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<Node> l;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        l.push_back(Node(1,i-1,i+1));
    }
    int idx = k;
    for(int i=0;i<cmd.size();i++)
    {
        int x=0,curleft,curright;
        switch(cmd[i][0])
        {
            case 'U':
                for(int j=2;j<cmd[i].length();j++)
                {
                    x*=10;
                    x+=cmd[i][j] - '0';
                }
                while(x)
                {
                    idx = l[idx].left;
                    x--;
                }
                break;
            case 'D':
                for(int j=2;j<cmd[i].length();j++)
                {
                    x*=10;
                    x+=cmd[i][j] - '0';
                }
                while(x)
                {
                    idx = l[idx].right;
                    x--;
                }
                break;
            case 'C':
                s.push(idx);
                l[idx].active = 0;
                curleft = l[idx].left, curright = l[idx].right;
                if(curleft>=0 && curleft<n) l[curleft].right = curright;
                if(curright>=0 && curright<n) l[curright].left = curleft;
                if(l[idx].right<n) idx = l[idx].right;
                else idx = l[idx].left;
                break;
            case 'Z':
                int val = s.top();
                s.pop();
                l[val].active = 1;
                curleft = l[val].left, curright = l[val].right;
                if(curleft>=0 && curleft<n) l[curleft].right = val;
                if(curright>=0 && curright<n) l[curright].left = val;
                break;
        }
        /*
        for(int j=0;j<n;j++)
        {
            printf("%d(%d,%d) ",l[j].active,l[j].left,l[j].right);
        }
        printf("%d\n",idx);
        */
    }
    for(int i=0;i<n;i++)
    {
        if(l[i].active)
        {
            answer.append("O");
        }
        else
        {
            answer.append("X");
        }
    }
    return answer;
}
/*
stl의 list, set 등을 이용해 실제로 데이터를 삽입하거나 삭제하는건 시간이 너무 오래걸린다.
*/ 
