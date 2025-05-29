#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    char s_input[1000001], explode_input[101];
    scanf("%s %s", s_input, explode_input);

    string s(s_input);
    string explode(explode_input);
    stack<char> st;

    for(int i=0;i<s.size();i++)
    {
        st.push(s[i]);
        if(s[i] == explode.back())
        {
            stack<char> temp;
            for(int j=0;j<explode.size();j++)
            {
                if(st.empty() || st.top() != explode[explode.size() - 1 - j])
                {
                    while(!temp.empty())
                    {
                        st.push(temp.top());
                        temp.pop();
                    }
                    break;
                }
                temp.push(st.top());
                st.pop();
            }
        }
    }

    if (st.empty())
    {
        printf("FRULA\n");
    }
    else
    {
        string result;
        while(!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        printf("%s\n", result.c_str()); 
    }
}