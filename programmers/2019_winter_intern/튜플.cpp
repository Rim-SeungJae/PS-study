#include <string>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> arr[550];
    bool mem[100010]={0,};
    int i=1;
    while(i<s.length()-1)
    {
        if(s[i]=='{')
        {
            vector<int> tmp;
            while(s[i]!='}')
            {
                i++;
                if(s[i]<='9' && s[i]>='0')
                {
                    int a=0;
                    while(s[i]<='9' && s[i]>='0')
                    {
                        a*=10;
                        a+=s[i] - '0';
                        i++;
                    }
                    tmp.push_back(a);
                }
            }
            arr[tmp.size()] = tmp;
        }
        i++;
    }
    i=1;
    while(!arr[i].empty())
    {
        for(int j=0;j<arr[i].size();j++)
        {
            //printf("%d ",arr[i][j]);
            if(!mem[arr[i][j]])
            {
                answer.push_back(arr[i][j]);
                mem[arr[i][j]] = true;
            }
        }
        //printf("\n");
        i++;
    }
    return answer;
}
