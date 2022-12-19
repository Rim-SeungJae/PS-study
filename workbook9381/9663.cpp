#include <cstdio>
#include <vector>

using namespace std;

bool isFound = false;
int row[10010],dia1[20020],dia2[20020];

void search(int n,int remain,vector<int> result)
{
	if(isFound) return;
    if(remain == 0)
    {
    	isFound=true;
    	for(int i=0;i<result.size();i++)
    	{
    		printf("%d\n",result[i]);
		}
        return;
    }
    int col_idx = n-remain, sum=0;
    for(int i=0;i<n;i++)
    {
        int row_idx = i;
        if(row[row_idx] == 0 && dia1[row_idx+col_idx] == 0 && dia2[row_idx-col_idx+n-1] == 0)
        {
            row[row_idx] =1;
            dia1[row_idx+col_idx] = 1;
            dia2[row_idx-col_idx+n-1] = 1;
            result.push_back(row_idx);
            search(n,remain-1,result);
            if(isFound) return;
            result.pop_back();
            row[row_idx] =0;
            dia1[row_idx+col_idx] = 0;
            dia2[row_idx-col_idx+n-1] = 0;
        }
    }
}

int main()
{
	int n;
	scanf("%d",&n);
	search(n,n,vector<int>());
}
/*
백트래킹
같은 행,열,대각선에 하나의 퀸만 존재할 수 있다는 점을 이용해
경우의 수를 최대한 줄인다.
*/ 
