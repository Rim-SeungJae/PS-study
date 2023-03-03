#include<cstdio>
#include<vector>

using namespace std;

class Cloud{
	public:
		int r=0;
		int c=0;
		Cloud(int r,int c)
		{
			this->r = r;
			this->c = c;
		}
		Cloud()
		{
			r=c=0;
		}
};

int N,M;
const int dirr[8] = {0,-1,-1,-1,0,1,1,1}, dirc[8] = {-1,-1,0,1,1,1,0,-1};

bool inRange(int a)
{
	if(a>=0 && a<N) return true;
	else return false;
}

int main()
{
	vector<Cloud> clouds;
	clouds.push_back(Cloud(N-1,0));
	clouds.push_back(Cloud(N-1,1));
	clouds.push_back(Cloud(N-2,0));
	clouds.push_back(Cloud(N-2,1));
	int arr[50][50];
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<M;i++)
	{
		// 1 & 2 & 4
		int d,s;
		bool dis[55][55] = {0,};
		scanf("%d %d",&d,&s);
		d--;
		for(int j=0;j<clouds.size();j++)
		{
			int& r = clouds[j].r;
			int& c = clouds[j].c;
			r = ((r + dirr[d] * s) % N + N)%N;
			c = ((c + dirc[d] * s) % N + N)%N;
			dis[r][c] = true;
			arr[r][c] += 1;
		}
		
		//4
		for(int j=0;j<clouds.size();j++)
		{
			int& r = clouds[j].r;
			int& c = clouds[j].c;
			int copy_cnt=0;
			if(inRange(r - 1) && inRange(c - 1) && arr[r-1][c-1] != 0) copy_cnt++;
			if(inRange(r - 1) && inRange(c + 1) && arr[r-1][c+1] != 0) copy_cnt++;
			if(inRange(r + 1) && inRange(c - 1) && arr[r+1][c-1] != 0) copy_cnt++;
			if(inRange(r + 1) && inRange(c + 1) && arr[r+1][c+1] != 0) copy_cnt++;
			arr[r][c] += copy_cnt;
		}
		
		//3
		clouds.clear();
		
		//5
		for(int j=0;j<N;j++)
		{
			for(int k=0;k<N;k++)
			{
				if(arr[j][k] >= 2 && !dis[j][k])
				{
					clouds.push_back(Cloud(j,k));
					arr[j][k] -= 2;
				}
			}
		}
		/*
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		*/
	}
	int result=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			result += arr[i][j];
		}
	}
	printf("%d",result);
}
/*
비교적 간단한 상어문제
*/ 
