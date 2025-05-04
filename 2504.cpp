#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>

using namespace std;

int main()
{
    stack<pair<bool,int>> st;
    char str[33];
    scanf("%s",str);
    int cur = 0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i] == ')')
        {
            int sum=0;
            while(!st.empty() && !st.top().first)
            {
                sum += st.top().second;
                st.pop();
            }
            if(st.empty())
            {
                printf("0");
                return 0;
            }
            char tmp = st.top().second;
            st.pop();
            if(tmp == '(')
            {
                if(sum == 0) st.push(make_pair(false,2));
                else st.push(make_pair(false,sum * 2));
            }
            else{
                printf("0");
                return 0;
            }
            
        }
        else if(str[i] == ']')
        {
            int sum=0;
            while(!st.empty() && !st.top().first)
            {
                sum += st.top().second;
                st.pop();
            }
            if(st.empty())
            {
                printf("0");
                return 0;
            }
            char tmp = st.top().second;
            st.pop();
            if(tmp == '[')
            {
                if(sum == 0) st.push(make_pair(false,3));
                else st.push(make_pair(false,sum * 3));
            }
            else{
                printf("0");
                return 0;
            }
            
        }
        else{
            st.push(make_pair(true,str[i]));
        }
    }

    int ans = 0;
    while(!st.empty())
    {
        if(st.top().first)
        {
            printf("0");
            return 0;
        }
        else{
            ans += st.top().second;
            st.pop();
        }
    }
    printf("%d",ans);
}