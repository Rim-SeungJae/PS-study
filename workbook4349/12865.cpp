int w[110], v[110], selected[110], mem[100010][110];
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }
    for(int i=1;i<=k;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		if(i-w[j]>=0) mem[i][j] =  max(v[j] + mem[i-w[j]][j-1], mem[i][j-1]);
			else mem[i][j] = mem[i][j-1];
		}
	}
	/*
	for(int i=0;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			printf("%d ",mem[i][j]);
		}
		printf("\n");
	}
	*/
    printf("%d",mem[k][n]);
}
/*
knapsack problem, dynamic programming
*/ 
