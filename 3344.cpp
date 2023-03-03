#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int row[100000] = {0,},dia1[200000]={0,},dia2[200000]={0,};
bool isFound = false; 

void search(int n,int remain)
{
    if(remain == 0)
    {
        for(int i=0;i<n;i++)
        {
        	printf("%d\n",row[i]);
		}
		isFound=true;
		return;
    }
    int col_idx = n-remain, sum=0;
    for(int i=0;i<n;i++)
    {
        int row_idx = i;
        if(row[row_idx] == 0 && dia1[row_idx+col_idx] == 0 && dia2[row_idx-col_idx+n-1] == 0)
        {
            row[row_idx] =col_idx+1;
            dia1[row_idx+col_idx] = 1;
            dia2[row_idx-col_idx+n-1] = 1;
            search(n,remain-1);
            if(isFound) return;
            row[row_idx] =0;
            dia1[row_idx+col_idx] = 0;
            dia2[row_idx-col_idx+n-1] = 0;
        }
    }
    return;
}

int main()
{
	int n;
	scanf("%d",&n);
	search(n,n);
}
