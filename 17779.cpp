#include<cstdio>
#include<algorithm>

int n,arr[22][22];

int diff(int x,int y,int d1,int d2)
{
	int cnt[6]={0,};
	int max=0,diff=0;
	//printf("%d %d %d %d\n",x,y,d1,d2);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i-j>=x-y && i-j<=x-y+d1+d1 && i+j>=x+y && i+j<=x+y+d2+d2)
			{
				cnt[5]+=arr[i][j];
				//printf("%d(5) ",arr[i][j]);
			}
			else{
				if(i<x+d1 && j<=y)
				{
					cnt[1]+=arr[i][j];
					//printf("%d(1) ",arr[i][j]);
				}
				if(i<=x+d2 && j>y)
				{
					cnt[2]+=arr[i][j];
					//printf("%d(2) ",arr[i][j]);
				}
				if(i>=x+d1 && j<y-d1+d2)
				{
					cnt[3]+=arr[i][j];
					//printf("%d(3) ",arr[i][j]);
				}
				if(i>x+d2 && j>=y-d1+d2)
				{
					cnt[4]+=arr[i][j];
					//printf("%d(4) ",arr[i][j]);
				}
			}
		}
		//printf("\n");
	}
	//printf("%d %d %d %d : %d %d %d %d %d\n",x,y,d1,d2,cnt[1],cnt[2],cnt[3],cnt[4],cnt[5]);
	std::sort(&cnt[1],&cnt[6],std::greater<int>());
	printf("%d %d %d %d : %d %d %d %d %d\n",x,y,d1,d2,cnt[1],cnt[2],cnt[3],cnt[4],cnt[5]);
	return cnt[1] - cnt[5];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int min = 100000000;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x=i,y=j;
			for(int k=1;x+k<=n-1;k++)
			{
				for(int l=1;x+k+l<=n;l++)
				{
					if(y-k<1 || y+l>n) break;
					int tmp = diff(x,y,k,l);
					if(min>tmp) min =tmp;
				}
			}
		}
	}
	printf("%d",min);
}
/*
구현, 시뮬레이션
한 구역이 여러개의 선거구에 동시에 속하는 경우가 있는데,
고려하지 않아도 정답처리된다. 
*/ 
