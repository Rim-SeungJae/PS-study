#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int search(int n,int remain,int row[],int dia1[],int dia2[])
{
    if(remain == 0)
    {
        return 1;
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
            sum += search(n,remain-1,row,dia1,dia2);
            row[row_idx] =0;
            dia1[row_idx+col_idx] = 0;
            dia2[row_idx-col_idx+n-1] = 0;
        }
    }
    return sum;
}

int solution(int n) {
    int answer = 0;
    int row[20] = {0,},dia1[100]={0,},dia2[100]={0,};
    answer = search(n,n,row,dia1,dia2);
    return answer;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",solution(n));
}
/*
백트래킹
같은 행,열,대각선에 하나의 퀸만 존재할 수 있다는 점을 이용해
경우의 수를 최대한 줄인다.
*/ 
