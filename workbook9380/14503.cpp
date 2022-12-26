#include<cstdio>

int arr[55][55];

void prt(int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int n,m,r,c,d,dirx[4] = {-1,0,1,0},diry[4] = {0,1,0,-1};
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&r,&c,&d);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int cnt=0;
	while(true)
	{
		//prt(n,m);
		if(arr[r][c] != 2)
		{
			arr[r][c] = 2;
			cnt++;
		}
		if(r+dirx[(d+3)%4]>=0 && r+dirx[(d+3)%4]<n && c+diry[(d+3)%4]>=0 && c+diry[(d+3)%4]<m && arr[r+dirx[(d+3)%4]][c+diry[(d+3)%4]] == 0)
		{
			d = (d+3)%4;
			r += dirx[d];
			c += diry[d];
			continue;
		}
		else
		{
			if((r-1<0 || arr[r-1][c]!=0) && (r+1>=n || arr[r+1][c]!=0) && (c-1<0 || arr[r][c-1]!=0) && (c+1>=m || arr[r][c+1]!=0))
			{
				if(r-dirx[d]>=0 && r-dirx[d]<n && c-diry[d]>=0 && c-diry[d]<m && arr[r-dirx[d]][c-diry[d]] == 1)
				{
					break;
				}
				else
				{
					r -= dirx[d];
					c -= diry[d];
					continue;
				}
			}
			else
			{
				d = (d+3)%4;
				continue;
			}
		}
	}
	printf("%d",cnt);
}
/*
구현
방향을 나타낼 때 배열을 활용하자(dirx, diry 배열을 참고할 것) 
*/ 
