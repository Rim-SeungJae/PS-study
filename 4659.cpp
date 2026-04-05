#include<cstdio>
#include<string>

using namespace std;

bool isMoeum(char a)
{
    return a == 'a' || a == 'e' || a == 'o' || a == 'u' || a == 'i';
}

int main()
{
    while(true)
    {
        char tmp[22];
        scanf("%s",tmp);
        string str(tmp);
        if(str == "end") break;

        bool hasAEIOU = false, has3row = false, hasDouble = false;
        int rowCnt = 0;
        for(int i=0;i<str.length();i++)
        {
            if(isMoeum(str[i])) hasAEIOU = true;
            if(i>0 && isMoeum(str[i]) == isMoeum(str[i-1])) rowCnt++;
            else rowCnt = 0;
            if(rowCnt>=2) has3row = true;
            if(i>0 && str[i]!='e' && str[i]!='o' && str[i] == str[i-1]) hasDouble = true;
        }

        if(hasAEIOU && !has3row && !hasDouble) printf("<%s> is acceptable.\n",str.c_str());
        else printf("<%s> is not acceptable.\n",str.c_str());
    }
}