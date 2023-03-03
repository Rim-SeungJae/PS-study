#include<cstdio>
#include<vector>

using namespace std;

class Tornado{
	public:
		int r=0;
		int c=0;
		int d=0;
		Tornado(int r,int c)
		{
			this->r = r;
			this->c = c;
			this->d = 0;
		}
		Tornado()
		{
			r=c=d=0;
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
	Tornado T;
	int arr[555][555];
	bool visited[555][555] = {0,};
	scanf("%d",&N);
	T = Tornado(N/2,N/2);
	visited[N/2][N/2] = true;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int result = 0;
	while(true)
	{
		// tornado move
		T.r = T.r + dirr[T.d];
		T.c = T.c + dirc[T.d];
		visited[T.r][T.c] = true;
		
		// sand blow
		int sand = arr[T.r][T.c],beta = 0;
		int r=(T.d+2)%8,l = (T.d+6)%8,f = T.d,rf = (T.d+1)%8,lf = (T.d+7)%8,rb = (T.d+3)%8,lb = (T.d+5)%8;
		if(inRange(T.r+dirr[f] * 2) && inRange(T.c + dirc[f] * 2))
		{
			arr[T.r+dirr[f] * 2][T.c + dirc[f] * 2] += sand*5/100;
		}
		else result += sand*5/100;
		beta += sand*5/100;
		if(inRange(T.r+dirr[r]) && inRange(T.c + dirc[r]))
		{
			arr[T.r+dirr[r]][T.c + dirc[r]] += sand*7/100;
		}
		else result += sand*7/100;
		beta += sand*7/100;
		if(inRange(T.r+dirr[r] * 2) && inRange(T.c + dirc[r] * 2))
		{
			arr[T.r+dirr[r] * 2][T.c + dirc[r] * 2] += sand*2/100;
		}
		else result += sand*2/100;
		beta += sand*2/100;
		if(inRange(T.r+dirr[l]) && inRange(T.c + dirc[l]))
		{
			arr[T.r+dirr[l]][T.c + dirc[l]] += sand*7/100;
		}
		else result += sand*7/100;
		beta += sand*7/100;
		if(inRange(T.r+dirr[l] * 2) && inRange(T.c + dirc[l] * 2))
		{
			arr[T.r+dirr[l] * 2][T.c + dirc[l] * 2] += sand*2/100;
		}
		else result += sand*2/100;
		beta += sand*2/100;
		if(inRange(T.r+dirr[lf]) && inRange(T.c + dirc[lf]))
		{
			arr[T.r+dirr[lf]][T.c + dirc[lf]] += sand*10/100;
		}
		else result += sand*10/100;
		beta += sand*10/100;
		if(inRange(T.r+dirr[rf]) && inRange(T.c + dirc[rf]))
		{
			arr[T.r+dirr[rf]][T.c + dirc[rf]] += sand*10/100;
		}
		else result += sand*10/100;
		beta += sand*10/100;
		if(inRange(T.r+dirr[lb]) && inRange(T.c + dirc[lb]))
		{
			arr[T.r+dirr[lb]][T.c + dirc[lb]] += sand/100;
		}
		else result += sand/100;
		beta += sand/100;
		if(inRange(T.r+dirr[rb]) && inRange(T.c + dirc[rb]))
		{
			arr[T.r+dirr[rb]][T.c + dirc[rb]] += sand/100;
		}
		else result += sand/100;
		beta += sand/100;
		if(inRange(T.r+dirr[f]) && inRange(T.c + dirc[f]))
		{
			arr[T.r+dirr[f]][T.c + dirc[f]] += sand - beta;
		}
		else result += sand - beta;
		
		arr[T.r][T.c] = 0;
		
		// turn around
		if(inRange(T.r + dirr[(T.d+6)%8]) && inRange(T.c + dirc[(T.d+6)%8]) && !visited[T.r + dirr[(T.d+6)%8]][T.c + dirc[(T.d+6)%8]])
		{
			T.d = (T.d+6)%8;
		}
		/*
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				printf("%d ",visited[i][j]);
			}
			printf("\n");
		}
		printf("%d %d %d\n",T.r,T.c,T.d);
		*/
		if(T.r == 0 && T.c == 0) break;
	}

	printf("%d",result);
}
/*
구현, 시뮬레이션
*/ 
