#include<cstdio>
#include<algorithm>

using namespace std;

int arr[110][110];
bool placed[110];

int main()
{
	int n,l;
	scanf("%d %d",&n,&l);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		fill(placed,placed+n,false);
		int j;
		for(j=0;j<n-1;j++)
		{
			if(arr[i][j] < arr[i][j+1])
			{
				if(arr[i][j+1] - arr[i][j] > 1) break;
				for(int k=0;k<l;k++)
				{
					if(j-k<0 || arr[i][j-k]!=arr[i][j] || placed[j-k])
					{
						j=n;
						break;
					}
					else placed[j-k] = true;
				}
			}
			else if(arr[i][j] > arr[i][j+1])
			{
				if(arr[i][j] - arr[i][j+1] > 1) break;
				for(int k=1;k<=l;k++)
				{
					if(j+k>=n || arr[i][j+k]!=arr[i][j+1] || placed[j+k])
					{
						j=n;
						break;
					}
					else placed[j+k] = true;
				}
			}
		}
		if(j==n-1)
		{
			//printf("%d %d\n",i,j);
			cnt++;
		}
		fill(placed,placed+n,false);
		for(j=0;j<n-1;j++)
		{
			if(arr[j][i] < arr[j+1][i])
			{
				if(arr[j+1][i] - arr[j][i] > 1) break;
				for(int k=0;k<l;k++)
				{
					if(j-k<0 || arr[j-k][i]!=arr[j][i] || placed[j-k])
					{
						j=n;
						break;
					}
					else placed[j-k] = true;
				}
			}
			else if(arr[j][i] > arr[j+1][i])
			{
				if(arr[j][i] - arr[j+1][i] > 1) break;
				for(int k=1;k<=l;k++)
				{
					if(j+k>=n || arr[j+k][i]!=arr[j+1][i] || placed[j+k])
					{
						j=n;
						break;
					}
					else placed[j+k] = true;
				}
			}
		}
		if(j==n-1)
		{
			//printf("%d %d\n",i,j);
			cnt++;
		}
	}
	printf("%d",cnt);
} 
/*
구현
삼중 반복문을 이용하지 않는 풀이가 있으니 참고할것
*/ 
