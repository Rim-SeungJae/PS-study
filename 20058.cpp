#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

int n,q,A[200][200],POW;
bool visited[200][200];

bool inRange(int a)
{
	return a>=0 && a<POW;
}

void spin(int r_begin,int r_end,int c_begin,int c_end,int l)
{
	// spin
	int new_A[200][200];
	if(r_end - r_begin == pow(2,l))
	{
		for(int i=0;i<r_end-r_begin;i++)
		{
			for(int j=0;j<c_end-c_begin;j++)
			{
				new_A[r_begin+j][c_end-1-i] = A[r_begin+i][c_begin+j];
			}
		}
		for(int i=0;i<r_end-r_begin;i++)
		{
			for(int j=0;j<c_end-c_begin;j++)
			{
				A[r_begin+i][c_begin+j] = new_A[r_begin+i][c_begin+j];
			}
		}
		return;
	}
	else
	{
		int r_mid = (r_begin+r_end)/2;
		int c_mid = (c_begin+c_end)/2;
		spin(r_begin,r_mid,c_begin,c_mid,l);
		spin(r_mid,r_end,c_begin,c_mid,l);
		spin(r_begin,r_mid,c_mid,c_end,l);
		spin(r_mid,r_end,c_mid,c_end,l);
	}
}

void melt()
{
	int new_A[200][200];
	for(int i=0;i<POW;i++)
	{
		for(int j=0;j<POW;j++)
		{
			int cnt=0;
			if(inRange(i-1) && A[i-1][j]!=0) cnt++;
			if(inRange(i+1) && A[i+1][j]!=0) cnt++;
			if(inRange(j-1) && A[i][j-1]!=0) cnt++;
			if(inRange(j+1) && A[i][j+1]!=0) cnt++;
			new_A[i][j] = A[i][j];
			if(cnt<3 && A[i][j]>0) new_A[i][j]=A[i][j]-1;
		}
	}
	copy(&new_A[0][0],&new_A[199][200],&A[0][0]);
}

int bfs(int src_r,int src_c)
{
	queue<pair<int,int>> q;
	q.push(make_pair(src_r,src_c));
	int cnt=0;
	while(!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		cnt++;
		if(inRange(r-1) && !visited[r-1][c] && A[r-1][c]!=0)
		{
			visited[r-1][c] = true;
			q.push(make_pair(r-1,c));
		}
		if(inRange(r+1) && !visited[r+1][c] && A[r+1][c]!=0)
		{
			visited[r+1][c] = true;
			q.push(make_pair(r+1,c));
		}
		if(inRange(c-1) && !visited[r][c-1] && A[r][c-1]!=0)
		{
			visited[r][c-1] = true;
			q.push(make_pair(r,c-1));
		}
		if(inRange(c+1) && !visited[r][c+1] && A[r][c+1]!=0)
		{
			visited[r][c+1] = true;
			q.push(make_pair(r,c+1));
		}
	}
	return cnt-1;
}

int main()
{
	scanf("%d %d",&n,&q);
	POW = pow(2,n);
	for(int i=0;i<POW;i++)
	{
		for(int j=0;j<pow(2,n);j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(int t=0;t<q;t++)
	{
		int l;
		scanf("%d",&l);
		spin(0,POW,0,POW,l);
		melt();
		/*
		for(int i=0;i<pow(2,n);i++)
		{
			for(int j=0;j<pow(2,n);j++)
			{
				printf("%d ",A[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
	}
	
	int sum = 0;
	for(int i=0;i<POW;i++)
	{
		for(int j=0;j<POW;j++)
		{
			sum+=A[i][j];
		}
	}
	int biggest = 0;
	for(int i=0;i<POW;i++)
	{
		for(int j=0;j<POW;j++)
		{
			if(!visited[i][j])
			{
				int tmp = bfs(i,j);
				if(tmp>biggest) biggest = tmp;
			}
		}
	}
	printf("%d\n%d",sum,biggest);
	
}
/*
반복문에  pow함수를 사용한 풀이에서는 시간초과가 난다
*/ 
