#include<cstdio>
#include<vector>
#include<algorithm>

//using namespace std;

bool visited[11][11];
int max;
bool is_first = true;

void backtrack(int arr[][11],int n,int m, int sum,int k,int cnt)
{
	if(cnt == k)
	{
		if(sum > max) max=sum;
		if(is_first)
		{
			max = sum;
			is_first=false;
		}
		return;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visited[i][j])
			{
				if(i-1>=0 && visited[i-1][j] == true) continue;
				if(i+1<n && visited[i+1][j] == true) continue;
				if(j-1>=0 && visited[i][j-1] == true) continue;
				if(j+1<m && visited[i][j+1] == true) continue;
				visited[i][j] = true;
				backtrack(arr,n,m,sum+arr[i][j],k,cnt+1);
				visited[i][j] = false;
			}
		}
	}
}

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int arr[11][11];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	backtrack(arr,n,m,0,k,0);
	printf("%d",max);
}
/*
브루트포스
기초적인 백트랙킹 문제.
주어지는 값이 음수일 수 있으므로 max 변수의 값 설정에 주의하자.
*/ 
