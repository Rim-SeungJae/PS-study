#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int dirr[4] = {0,1,0,-1},dirc[4] = {-1,0,1,0};
vector<int> marbles;
vector<pair<int,int>> blizzard;
int n,m;

bool isneg(int a)
{
	return a<0;
}

int main()
{
	int arr[100][100];
	int cnt[4]={0,};
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int r,c,d=0,i;
	r = c = n/2;
	marbles.push_back(arr[r][c]);
	for(i=1;i<n;i++)
	{
		int j;
		for(j=0;j<i;j++)
		{
			r+=dirr[d];
			c+=dirc[d];
			if(!arr[r][c]) break;
			marbles.push_back(arr[r][c]);
		}
		if(j!=i) break;
		d = (d+1)%4;
		for(j=0;j<i;j++)
		{
			r+=dirr[d];
			c+=dirc[d];
			if(!arr[r][c]) break;
			marbles.push_back(arr[r][c]);
		}
		if(j!=i) break;
		d = (d+1)%4;
	}
	if(i==n)
	{
		for(int i=0;i<n-1;i++)
		{
			r+=dirr[d];
			c+=dirc[d];
			if(!arr[r][c]) break;
			marbles.push_back(arr[r][c]);
		}
	}
	/*
	for(int i=0;i<marbles.size();i++)
	{
		printf("%d ",marbles[i]);
	}
	printf("\n");
	*/
	for(int t=0;t<m;t++)
	{
		// 1
		int d,s;
		scanf("%d %d",&d,&s);
		for(int i=1;i<2*s;i+=2)
		{
			switch(d)
			{
				case 3:
					if(i*i + i/2 >= marbles.size())
					{
						i = 2*s;
						break;
					}
					marbles[i*i + i/2] = -1;
					break;
				case 2:
					if(i*i + i + (i+1)/2 >= marbles.size())
					{
						i = 2*s;
						break;
					}
					marbles[i*i + i + (i+1)/2] = -1;
					break;
				case 4:
					if(i*i + 2*i + 1 + (i+1)/2 >= marbles.size())
					{
						i = 2*s;
						break;
					}
					marbles[i*i + 2*i + 1 + (i+1)/2] = -1;
					break;
				case 1:
					if(i*i + 3*i + 2 + (i+1)/2 >= marbles.size())
					{
						i = 2*s;
						break;
					}
					marbles[i*i + 3*i + 2 + (i+1)/2] = -1;
					break;
			}
		}
		marbles.erase(remove_if(marbles.begin(),marbles.end(),isneg),marbles.end());
		/*
		for(int i=0;i<marbles.size();i++)
		{
			printf("%d ",marbles[i]);
		}
		printf("\n");
		*/
		// 2
		bool isBroke;
		do{
			bool visited[2500] = {0,};
			isBroke=false;
			for(int i=0;i<marbles.size();i++)
			{
				if(!visited[i])
				{
					visited[i]=true;
					int j;
					for(j=i+1;j<marbles.size() && marbles[j] == marbles[i];j++)
					{
						visited[j] = true;
					}
					if(j-i>3)
					{
						cnt[marbles[i]]+=j-i;
						isBroke = true;
						for(int k=i;k<j;k++)
						{
							marbles[k] = -1;
						}
					}
				}
			}
			marbles.erase(remove_if(marbles.begin(),marbles.end(),isneg),marbles.end());
		}while(isBroke);
		/*
		for(int i=0;i<marbles.size();i++)
		{
			printf("%d ",marbles[i]);
		}
		printf("\n");
		*/
		// 3
		vector<int> new_marbles;
		bool visited[2500] = {0,};
		new_marbles.push_back(0);
		for(int i=1;i<marbles.size();i++)
		{
			if(!visited[i])
			{
				visited[i]=true;
				int j;
				for(j=i+1;j<marbles.size() && marbles[j] == marbles[i];j++)
				{
					visited[j] = true;
				}
				new_marbles.push_back(j-i);
				new_marbles.push_back(marbles[i]);
			}
		}
		marbles = new_marbles;
		if(marbles.size()>n*n) marbles.erase(marbles.begin()+n*n,marbles.end());
		/*
		for(int i=0;i<marbles.size();i++)
		{
			printf("%d ",marbles[i]);
		}
		printf("\n");
		*/
		
	}
	printf("%d",cnt[1] + 2*cnt[2] + 3*cnt[3]);
}
/*
벡터에 접근할 때 범위 초과에 주의하자
(71~113의 조건문들을 보자) 
*/ 
