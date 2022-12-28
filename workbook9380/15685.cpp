#include<cstdio>
#include<vector>

using namespace std;

int dir_x[4] = {1,0,-1,0}, dir_y[4] = {0,-1,0,1};

int main()
{
	int n;
	bool arr[110][110] = {0,};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y,d,g;
		scanf("%d %d %d %d",&x,&y,&d,&g);
		vector<pair<int,int>> v;
		v.push_back(make_pair(x,y));
		v.push_back(make_pair(x+dir_x[d],y+dir_y[d]));
		arr[x][y] = arr[x+dir_x[d]][y+dir_y[d]] = 1;
		for(int j=0;j<g;j++)
		{
			int origin_x = v.back().first, origin_y = v.back().second, len = v.size()-1;;
			for(int k=len;k>=0;k--)
			{
				int new_x, new_y;
				new_x = -(v[k].second - origin_y) + origin_x;
				new_y =  (v[k].first - origin_x) + origin_y;
				v.push_back(make_pair(new_x,new_y));
				arr[new_x][new_y] = 1;
			}

		}

	}
	int cnt=0;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			if(arr[i][j] == 1 && arr[i+1][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j+1] == 1)
			{
				cnt++;
			}
		}
	}
	printf("%d",cnt);
}
/*
구현
평면좌표계의 회전변환 공식에 유의하자
x' = xcos0 - ysin0
y' = xsin0 + ycos0
회전변환 공식을 이용하지 않는 간단한 풀이도 있다! 
*/
 
