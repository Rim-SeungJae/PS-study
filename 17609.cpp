#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char str[100001];
        scanf("%s",str);
        int l = 0,r = strlen(str)-1;
        bool flg = false;

        while(l<=r)
        {
            if(str[l] == str[r])
            {
                l++;
                r--;
            }
            else if(str[l+1] == str[r] && (l + 2 > r || str[l + 2] == str[r - 1]) && !flg)
            {
                l++;
                flg = true;
            }
            else if(str[l] == str[r-1] && (l + 1 > r - 2 || str[l + 1] == str[r - 2]) && !flg)
            {
                r--;
                flg = true;
            }
            else break;
        }

        if(l<=r) printf("2\n");
        else printf("%d\n",flg);
    }
}
