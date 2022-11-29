#include <cstdio>

int main()
{
	int n,max=0;
	char arr[55][55];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("\n");
		for(int j=0;j<n;j++)
		{
			scanf("%c",&arr[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			char cur = arr[i][j];
			int k;
			bool switched;
			switched = false;
			for(k=0;;k++)
			{
				if(i+k>=n) break;
				if(arr[i+k][j] != cur)
				{
					if(!switched && (j+1<n &&  arr[i+k][j+1] == cur || j-1>=0 && arr[i+k][j-1] == cur)) switched = true;
					else if(!switched && i+k+1<n && arr[i+k+1][j] == cur)
					{
						k++;
						break;
					}
					else break;
				}
			}
			if(max<k)
			{
				max=k;
			}
			switched = false;
			for(k=0;;k++)
			{
				if(i-k<0 ) break;
				if(arr[i-k][j] != cur)
				{
					if(!switched && (j+1<n && arr[i-k][j+1] == cur || j-1>=0 && arr[i-k][j-1] == cur)) switched = true;
					else if(!switched && i-k-1>=0 && arr[i-k-1][j] == cur)
					{
						k++;
						break;
					}
					else break;
				}
			}
			if(max<k)
			{
				max=k;
			}
			switched = false;
			for(k=0;;k++)
			{
				if( j+k>=n ) break;
				if(arr[i][j+k] != cur)
				{
					if(!switched && (i+1<n && arr[i+1][j+k] == cur || i-1>=0 && arr[i-1][j+k] == cur)) switched = true;
					else if(!switched && j+k+1<n && arr[i][j+k+1] == cur)
					{
						k++;
						break;
					}
					else break;
				}
			}
			if(max<k)
			{
				max=k;
			}
			switched = false;
			for(k=0;;k++)
			{
				if(j-k<0) break;
				if( arr[i][j-k] != cur)
				{
					if(!switched && (i+1<n && arr[i+1][j-k] == cur || i-1>=0 && arr[i-1][j-k] == cur)) switched = true;
					else if(!switched && j-k-1>=0 && arr[i][j-k-1] == cur)
					{
						k++;
						break;
					}
					else break;
				}
			}
			if(max<k)
			{
				max=k;
			}
		}
	}
	printf("%d",max);
}
/*
브루트포스 방식으로 문제를 해결한다.
주어진 사탕 배열의 모든 요소에 접근해서 4가지 방향으로 뻗어가면서(4번의 for문),
사탕의 위치를 1회 교환할 수 있다고 할 때(switched 변수) 최장거리를 구한다.
*/ 
