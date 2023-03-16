#include<cstdio>
#include<vector>

using namespace std;

vector<vector<bool>> blue,green;

int main()
{
	int n,score = 0;
	blue.assign(6,vector<bool>(4,0));
	green.assign(6,vector<bool>(4,0));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int t,x,y;
		scanf("%d %d %d",&t,&x,&y);
		if(t==1)
		{
			int r,c;
			// green
			r = 0;
			c = y;
			while(r+1<6 && green[r+1][c] == 0)
			{
				r++;
			}
			green[r][c] = 1;
			// blue
			r = 0;
			c = x;
			while(r+1<6 && blue[r+1][c] == 0)
			{
				r++;
			}
			blue[r][c] = 1;
		}
		else if(t==2)
		{
			int r,c;
			// green
			r = 0;
			c = y;
			while(r+1<6 && green[r+1][c] == 0 && green[r+1][c+1] == 0)
			{
				r++;
			}
			green[r][c] = 1;
			green[r][c+1] = 1;
			// blue
			r = 0;
			c = x;
			while(r+2<6 && blue[r+1][c] == 0 && blue[r+2][c] == 0)
			{
				r++;
			}
			blue[r][c] = 1;
			blue[r+1][c] = 1;
		}
		else if(t==3)
		{
			int r,c;
			// green
			r = 0;
			c = y;
			while(r+2<6 && green[r+1][c] == 0 && green[r+2][c] == 0)
			{
				r++;
			}
			green[r][c] = 1;
			green[r+1][c] = 1;
			// blue
			r = 0;
			c = x;
			while(r+1<6 && blue[r+1][c] == 0 && blue[r+1][c+1] == 0)
			{
				r++;
			}
			blue[r][c] = 1;
			blue[r][c+1] = 1;
		}
		for(int j=0;j<6;j++)
		{
			if(green[j][0] == 1 && green[j][1] == 1 && green[j][2] == 1 && green[j][3] == 1)
			{
				green.erase(green.begin()+j);
				score++;
				green.insert(green.begin(),vector<bool>(4,0));
			}
			if(blue[j][0] == 1 && blue[j][1] == 1 && blue[j][2] == 1 && blue[j][3] == 1)
			{
				blue.erase(blue.begin()+j);
				score++;
				blue.insert(blue.begin(),vector<bool>(4,0));
			}
		}
		while(green[1][0] == 1 || green[1][1] == 1 || green[1][2] == 1 || green[1][3] == 1)
		{
			green.erase(green.end()-1);
			green.insert(green.begin(),vector<bool>(4,0));
		}
		while(blue[1][0] == 1 || blue[1][1] == 1 || blue[1][2] == 1 || blue[1][3] == 1)
		{
			blue.erase(blue.end()-1);
			blue.insert(blue.begin(),vector<bool>(4,0));
		}
	}
	int cnt = 0;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(green[i][j]) cnt++;
			if(blue[i][j]) cnt++;
		}
	}
	printf("%d\n%d",score,cnt);
}
/*
구현, 시뮬레이션
*/ 
