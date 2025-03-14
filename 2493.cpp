#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

int main()
{
    int n;
    stack<pair<int,int>> st;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int cur;
        scanf("%d",&cur);
        while(!st.empty() && cur > st.top().first)
        {
            st.pop();
        }
        if(!st.empty())
        {
            printf("%d ",st.top().second + 1);
            st.push(make_pair(cur,i));
        }
        else
        {
            printf("0 ");
            st.push(make_pair(cur,i));
        }
    }
}