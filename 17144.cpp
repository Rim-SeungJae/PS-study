#include<cstdio>
#include<algorithm>

using namespace std;

int R,C,A[55][55],top_r=-1,down_r=-1;

bool in_R(int a)
{
	if(a>=0 && a<R) return true;
	else return false;
}
bool in_C(int a)
{
	if(a>=0 && a<C) return true;
	else return false;
}

int main()
{
	int T;
	scanf("%d %d %d",&R,&C,&T);
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			scanf("%d",&A[i][j]);
			if(A[i][j] == -1)
			{
				if(top_r==-1)
				{
					top_r = i;
				}
				else{
					down_r = i;
				}
			}
		}
	}
	for(int t=0;t<T;t++)
	{
		int new_A[55][55];
		copy(&A[0][0],&A[54][55],&new_A[0][0]);
		// 1
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if(A[i][j]>0)
				{
					if(in_R(i-1) && A[i-1][j]!=-1)
					{
						new_A[i][j] -= A[i][j]/5;
						new_A[i-1][j] += A[i][j]/5;
					}
					if(in_R(i+1) && A[i+1][j]!=-1)
					{
						new_A[i][j] -= A[i][j]/5;
						new_A[i+1][j] += A[i][j]/5;
					}
					if(in_C(j-1) && A[i][j-1]!=-1)
					{
						new_A[i][j] -= A[i][j]/5;
						new_A[i][j-1] += A[i][j]/5;
					}
					if(in_C(j+1) && A[i][j+1]!=-1)
					{
						new_A[i][j] -= A[i][j]/5;
						new_A[i][j+1] += A[i][j]/5;
					}
				}
			}
		}
		
		copy(&new_A[0][0],&new_A[54][55],&A[0][0]);
		
		// 2-1
		int wind_r = top_r, wind_c = 1,prev = A[wind_r][wind_c],cur;
		A[wind_r][wind_c] = 0;
		while(in_C(wind_c+1))
		{
			cur = A[wind_r][wind_c+1];
			A[wind_r][wind_c+1] = prev;
			prev = cur;
			wind_c++;
		}
		while(in_R(wind_r-1))
		{
			cur = A[wind_r-1][wind_c];
			A[wind_r-1][wind_c] = prev;
			prev = cur;
			wind_r--;
		}
		while(in_C(wind_c-1))
		{
			cur = A[wind_r][wind_c-1];
			A[wind_r][wind_c-1] = prev;
			prev = cur;
			wind_c--;
		}
		while(wind_r+1<top_r)
		{
			cur = A[wind_r+1][wind_c];
			A[wind_r+1][wind_c] = prev;
			prev = cur;
			wind_r++;	
		}

		// 2-2
		wind_r = down_r;
		wind_c = 1;
		prev = A[wind_r][wind_c];
		A[wind_r][wind_c] = 0;
		while(in_C(wind_c+1))
		{
			cur = A[wind_r][wind_c+1];
			A[wind_r][wind_c+1] = prev;
			prev = cur;
			wind_c++;
		}
		while(in_R(wind_r+1))
		{
			cur = A[wind_r+1][wind_c];
			A[wind_r+1][wind_c] = prev;
			prev = cur;
			wind_r++;
		}
		while(in_C(wind_c-1))
		{
			cur = A[wind_r][wind_c-1];
			A[wind_r][wind_c-1] = prev;
			prev = cur;
			wind_c--;
		}
		while(wind_r-1>down_r)
		{
			cur = A[wind_r-1][wind_c];
			A[wind_r-1][wind_c] = prev;
			prev = cur;
			wind_r--;	
		}
		/*
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				printf("%d ",A[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
	}
	int sum = 0;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(A[i][j]>0)sum+=A[i][j];
		}
	}
	printf("%d",sum);
}
/*
구현, 시뮬레이션
*/ 
