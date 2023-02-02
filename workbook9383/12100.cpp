#include<cstdio>
#include<algorithm>

int n,max;

void move(int dir,int arr[][20],int cnt)
{
	if(cnt>4) return;
	int next[20][20];
	std::fill(&next[0][0],&next[19][20],0);
	switch(dir)
	{
		case 0:
			for(int i=0;i<n;i++)
			{
				int target = 0;
				for(int j=0;j<n;j++)
				{
					if(arr[i][j]!=0)
					{
						if(next[i][target] == 0)
						{
							next[i][target] = arr[i][j];
							if(next[i][target]>max) max=next[i][target];
						}
						else
						{
							if(arr[i][j]!=next[i][target])
							{
								target++;
								if(next[i][target]==0)
								{
									next[i][target] = arr[i][j];
									if(next[i][target]>max)max=next[i][target];
								}
							}
							else
							{
								next[i][target] += arr[i][j];
								if(next[i][target]>max)max=next[i][target];
								target++;
							}
						}
					}
				}
			}
			break;
		case 1:
			for(int i=0;i<n;i++)
			{
				int target = 0;
				for(int j=0;j<n;j++)
				{
					if(arr[j][i]!=0)
					{
						if(next[target][i] == 0)
						{
							next[target][i] = arr[j][i];
							if(next[target][i]>max)max=next[target][i];
						}
						else
						{
							if(arr[j][i]!=next[target][i])
							{
								target++;
								if(next[target][i]==0)
								{
									next[target][i] = arr[j][i];
									if(next[target][i]>max)max=next[target][i];
								}
							}
							else
							{
								next[target][i] += arr[j][i];
								if(next[target][i]>max)max=next[target][i];
								target++;
							}
						}
					}
				}
			}
			break;
		case 2:
			for(int i=0;i<n;i++)
			{
				int target = n-1;
				for(int j=n-1;j>=0;j--)
				{
					if(arr[i][j]!=0)
					{
						if(next[i][target] == 0)
						{
							next[i][target] = arr[i][j];
							if(next[i][target]>max)max=next[i][target];
						}
						else
						{
							if(arr[i][j]!=next[i][target])
							{
								target--;
								if(next[i][target]==0)
								{
									next[i][target] = arr[i][j];
									if(next[i][target]>max)max=next[i][target];
								}
							}
							else
							{
								next[i][target] += arr[i][j];
								if(next[i][target]>max)max=next[i][target];
								target--;
							}
						}
					}
				}
			}
			break;
		case 3:
			for(int i=0;i<n;i++)
			{
				int target = n-1;
				for(int j=n-1;j>=0;j--)
				{
					if(arr[j][i]!=0)
					{
						if(next[target][i] == 0)
						{
							next[target][i] = arr[j][i];
							if(next[target][i]>max)max=next[target][i];
						}
						else
						{
							if(arr[j][i]!=next[target][i])
							{
								target--;
								if(next[target][i]==0)
								{
									next[target][i] = arr[j][i];
									if(next[target][i]>max)max=next[target][i];
								}
							}
							else
							{
								next[target][i] += arr[j][i];
								if(next[target][i]>max)max=next[target][i];
								target--;
							}
						}
					}
				}
			}
			break;
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",next[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	for(int i=0;i<4;i++)
	{
		move(i,next,cnt+1);
	}
}

int main()
{
	int arr[20][20];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<4;i++)
	{
		move(i,arr,0);
	}
	printf("%d",max);
}
/*
브루트포스
백트래킹의 탈출 조건에 유의할것
*/ 
