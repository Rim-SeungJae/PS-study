#include<cstdio>
#include<vector>
#include<string>
#include<deque>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=0;test<t;test++)
    {
        string p;
        char tmp[400040];
        scanf("%s",tmp);
        p = string(tmp);
        int n;
        scanf("%d",&n);
        deque<int> dq;
        scanf("%s",tmp);
        string arr(tmp);
        arr.erase(0,1);
        arr.erase(arr.length() - 1);
        arr+=",";
        int curPos = 0,targetPos = arr.find(",",curPos);
        while(curPos != targetPos && targetPos != string::npos)
        {
            int len = targetPos - curPos;
            int a = stoi(arr.substr(curPos,len));
            dq.push_back(a);
            curPos = targetPos+1;
            targetPos = arr.find(",",curPos);
        }
        bool isReverse = false;
        int i;
        for(i=0;i<p.length();i++)
        {
            if(p[i] == 'R')
            {
                isReverse = !isReverse;
            }
            else if(p[i] == 'D')
            {
                if(dq.empty()) break;
                if(isReverse)
                {
                    dq.pop_back();
                }
                else dq.pop_front();
            }
        }
        if(i != p.length()) printf("error\n");
        else
        {
            printf("[");
            while(!dq.empty())
            {
                if(isReverse)
                {
                    printf("%d",dq.back());
                    dq.pop_back();
                }
                else{
                    printf("%d",dq.front());
                    dq.pop_front();
                }
                if(!dq.empty()) printf(",");
            }
            printf("]\n");
        }
    }
}