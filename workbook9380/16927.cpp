#include<cstdio>
#include<algorithm>

int arr[310][310],result[310][310];

int main()
{
	int n,m,t;
	scanf("%d %d %d",&n,&m,&t);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<std::min(n,m)/2;i++)
	{
		int prev,cur,rot = t%(2*(n-2*i) + 2*(m-2*i) - 4);
		
		for(int j=0;j<2*(n-2*i) + 2*(m-2*i) - 4;j++)
		{
			int target = j+rot,target_x,target_y;
			target_x = target_y = i;
			if(target/(n-2*i))
			{
				target_x += (n-2*i) -1;
				target -= (n-2*i) -1;
			}
			else
			{
				target_x += target%(n-2*i);
				target -= target%(n-2*i);
			}
			if(target/(m-2*i))
			{
				target_y += (m-2*i) -1;
				target -= (m-2*i) -1;
			}
			else
			{
				target_y += target%(m-2*i);
				target -= target%(m-2*i);
			}
			if(target/(n-2*i))
			{
				target_x -= (n-2*i) -1;
				target -= (n-2*i) -1;
			}
			else
			{
				target_x -= target%(n-2*i);
				target -= target%(n-2*i);
			}
			if(target/(m-2*i))
			{
				target_y -= (m-2*i) -1;
				target -= (m-2*i) -1;
			}
			else
			{
				target_y -= target%(m-2*i);
				target -= target%(m-2*i);
			}
			if(target/(n-2*i))
			{
				target_x += (n-2*i) -1;
				target -= (n-2*i) -1;
			}
			else
			{
				target_x += target%(n-2*i);
				target -= target%(n-2*i);
			}
			if(target/(m-2*i))
			{
				target_y += (m-2*i) -1;
				target -= (m-2*i) -1;
			}
			else
			{
				target_y += target%(m-2*i);
				target -= target%(m-2*i);
			}
			if(target/(n-2*i))
			{
				target_x -= (n-2*i) -1;
				target -= (n-2*i) -1;
			}
			else
			{
				target_x -= target%(n-2*i);
				target -= target%(n-2*i);
			}
			if(target/(m-2*i))
			{
				target_y -= (m-2*i) -1;
				target -= (m-2*i) -1;
			}
			else
			{
				target_y -= target%(m-2*i);
				target -= target%(m-2*i);
			}
			int source = j,source_x,source_y;
			source_x = source_y = i;
			if(source/(n-2*i))
			{
				source_x += (n-2*i) -1;
				source -= (n-2*i) -1;
			}
			else
			{
				source_x += source%(n-2*i);
				source -= source%(n-2*i);
			}
			if(source/(m-2*i))
			{
				source_y += (m-2*i) -1;
				source -= (m-2*i) -1;
			}
			else
			{
				source_y += source%(m-2*i);
				source -= source%(m-2*i);
			}
			if(source/(n-2*i))
			{
				source_x -= (n-2*i) -1;
				source -= (n-2*i) -1;
			}
			else
			{
				source_x -= source%(n-2*i);
				source -= source%(n-2*i);
			}
			if(source/(m-2*i))
			{
				source_y -= (m-2*i) -1;
				source -= (m-2*i) -1;
			}
			else
			{
				source_y -= source%(m-2*i);
				source -= source%(m-2*i);
			}
			result[target_x][target_y] = arr[source_x][source_y];
			//printf("%d %d->%d %d\n",source_x,source_y,target_x,target_y);
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",result[i][j]);
		}
		printf("\n");	
	}
	
}
/*
더 깔끔한 풀이가 있으니 참고할것
*/ 
