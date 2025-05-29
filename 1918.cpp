#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;

int main()
{
    int priority[256];
    priority['+'] = priority['-'] = 2;
    priority['*'] = priority['/'] = 1;
    string expression;
    cin >> expression;
    stack<char> symbols;
    stack<string> st;
    for(char c : expression)
    {
        if(c == '(')
        {
            symbols.push(c);
        }
        else if(c == ')')
        {
            while (!symbols.empty() && symbols.top() != '(')
            {
                string tmp1 = st.top(); st.pop();
                string tmp2 = st.top(); st.pop();
                char sym = symbols.top(); symbols.pop();

                tmp2.append(tmp1);
                tmp2.append(string(1,sym));
                st.push(tmp2);
            }
            if (!symbols.empty() && symbols.top() == '(')
                symbols.pop();
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (!symbols.empty() && symbols.top() != '(' && priority[symbols.top()] <= priority[c])
            {
                string tmp1 = st.top(); st.pop();
                string tmp2 = st.top(); st.pop();
                char sym = symbols.top(); symbols.pop();

                tmp2.append(tmp1);
                tmp2.append(string(1,sym));
                st.push(tmp2);
            }
            symbols.push(c);
        }
        else{
            st.push(string(1,c));
        }
    }
    while (!symbols.empty())
    {
        string tmp1 = st.top(); st.pop();
        string tmp2 = st.top(); st.pop();
        char sym = symbols.top(); symbols.pop();

        tmp2.append(tmp1);
        tmp2.append(string(1,sym));
        st.push(tmp2);
    }
    cout << st.top();
}