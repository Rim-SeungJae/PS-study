#include<cstdio>

bool ladder[11][33];
int n,m,h,min_cnt = 4;

void bt(int depth,int prev_x,int prev_y)
{
	if(depth>=min_cnt) return;
	int pos[11];
	for(int i=0;i<n;i++)
	{
		pos[i] = i;
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(ladder[j][i])
			{
				int tmp = pos[j];
				pos[j] = pos[j+1];
				pos[j+1] = tmp;
			}
		}
	}
	bool isSuccess = true;
	for(int i=0;i<n;i++)
	{
		if(pos[i] != i) isSuccess = false;
	}
	if(isSuccess)
	{
		/*
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<n-1;j++)
			{
				printf("%d ",ladder[j][i]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		min_cnt = depth;
		return;
	}
	for(int i=prev_x;i<n-1;i++)
	{
		for(int j = (i==prev_x ? prev_y+1 : 0);j<h;j++)
		{
			if(ladder[i][j]) continue;
			if(i-1>=0 && ladder[i-1][j]) continue;
			if(i+1<n && ladder[i+1][j]) continue;
			ladder[i][j] = true;
			bt(depth+1,i,j);
			ladder[i][j] = false;
		}
	}
}

int main()
{
	scanf("%d %d %d",&n,&m,&h);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		ladder[b-1][a-1] = true;
	}
	bt(0,0,-1);
	if(min_cnt>=4) printf("-1");
	else printf("%d",min_cnt);
}
/*
백트래킹
재귀를 활용한 DFS 방식의 백트래킹은 시간이 오래걸린다
설치하는 사다리 개수를 0개에서 3개로 하나씩 늘려가면서 각각의 경우를 탐색하면
시간을 줄일 수 있다. 
*/ 
