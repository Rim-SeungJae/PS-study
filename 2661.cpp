#include<cstdio>
#include<string>

using namespace std;

bool flg = false;

void bt(int n,string num)
{
    if(flg) return;
    if(num.length() == n)
    {
        printf("%s",num.c_str());
        flg = true;
        return;
    }
    for(int i=1;i<4;i++)
    {
        string tmp = to_string(i);
        string nnum = num;
        nnum.append(tmp);
        bool is_good = true;
        for(int j=1;j<=nnum.length()/2;j++)
        {
            string a = nnum.substr(nnum.length() - 2*j,j);
            string b = nnum.substr(nnum.length() - j,j);
            if(a==b) is_good = false;
        }
        if(is_good) bt(n,nnum);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    bt(n,string(""));
}