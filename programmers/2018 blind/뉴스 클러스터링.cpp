#include <string>
#include <unordered_set>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int str1_n=0,str2_n=0,inter=0,uni=0;
    unordered_multiset<string> ms;
    for(int i=0;i<str1.length()-1;i++)
    {
        if(isalpha(str1[i]) && isalpha(str1[i+1]))
        {
            str1_n++;
            char tmp[3] = {char(tolower(str1[i])),char(tolower(str1[i+1])),0};
            string word(tmp);
            ms.insert(word);
        }
    }
    
    for(int i=0;i<str2.length()-1;i++)
    {
        if(isalpha(str2[i]) && isalpha(str2[i+1]))
        {
            str2_n++;
            char tmp[3] = {char(tolower(str2[i])),char(tolower(str2[i+1])),0};
            string word(tmp);
            auto target = ms.find(word);
            if(target != ms.end())
            {
                inter++;
                ms.erase(target);
            }
        }
    }
    //printf("%d %d %d",inter,str1_n,str2_n);
    if(str1_n + str2_n - inter == 0) answer = 65536;
    else answer = double(inter)/(str1_n+str2_n-inter) * 65536;
    return answer;
}
/*
쉬운 구현.
string 라이브러리의 다양한 함수들을 활용할것
*/ 
