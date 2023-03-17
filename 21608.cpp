#include<cstdio>

int like[440][4],arr[22][22],n,order[440];

bool inRange(int a)
{
	if(a>=0 && a<n) return true;
	else return false;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n*n;i++)
	{
		int a;
		scanf("%d",&a);
		order[i] = a;
		scanf("%d %d %d %d",&like[a][0],&like[a][1],&like[a][2],&like[a][3]);
	}
	for(int t = 0;t<n*n;t++)
	{
		int student = order[t];
		int r = -1, c = -1, like_max = -1,empty_max=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]!=0) continue;
				int like_cnt=0,empty_cnt=0;
				if(inRange(i-1))
				{
					if(arr[i-1][j] == 0) empty_cnt++;
					if(arr[i-1][j] == like[student][0] || arr[i-1][j] == like[student][1] || arr[i-1][j] == like[student][2] || arr[i-1][j] == like[student][3])
					{
						like_cnt++;
					}
				}
				if(inRange(i+1))
				{
					if(arr[i+1][j] == 0) empty_cnt++;
					if(arr[i+1][j] == like[student][0] || arr[i+1][j] == like[student][1] || arr[i+1][j] == like[student][2] || arr[i+1][j] == like[student][3])
					{
						like_cnt++;
					}
				}
				if(inRange(j-1))
				{
					if(arr[i][j-1] == 0) empty_cnt++;
					if(arr[i][j-1] == like[student][0] || arr[i][j-1] == like[student][1] || arr[i][j-1] == like[student][2] || arr[i][j-1] == like[student][3])
					{
						like_cnt++;
					}
				}
				if(inRange(j+1))
				{
					if(arr[i][j+1] == 0) empty_cnt++;
					if(arr[i][j+1] == like[student][0] || arr[i][j+1] == like[student][1] || arr[i][j+1] == like[student][2] || arr[i][j+1] == like[student][3])
					{
						like_cnt++;
					}
				}
				if(like_cnt>like_max)
				{
					like_max = like_cnt;
					empty_max = empty_cnt;
					r = i;
					c = j;
				}
				else if(like_cnt == like_max)
				{
					if(empty_cnt > empty_max)
					{
						empty_max = empty_cnt;
						r = i;
						c = j;
					}
				}
			}
		}
		arr[r][c] = student;
		//printf("%d %d:%d\n",r,c,student);
	}
	int result=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int cnt=0;
			for(int k=0;k<4;k++)
			{
				if(inRange(i-1) && arr[i-1][j] == like[arr[i][j]][k]) cnt++;
				if(inRange(i+1) && arr[i+1][j] == like[arr[i][j]][k]) cnt++;
				if(inRange(j-1) && arr[i][j-1] == like[arr[i][j]][k]) cnt++;
				if(inRange(j+1) && arr[i][j+1] == like[arr[i][j]][k]) cnt++;
			}
			switch(cnt)
			{
				case 1:
					result+=1;
					break;
				case 2:
					result+=10;
					break;
				case 3:
					result+=100;
					break;
				case 4:
					result+=1000;
					break;
			}
		}
	}
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d",result);
}
/*
구현, 시뮬레이션
배열의 크기에 주의
*/ 
