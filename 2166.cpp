#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

const double PI = atan(1) * 4;

int main()
{
	int n;
	pair<int,int> v[10010];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		v[i].first = x;
		v[i].second = y;
	}
	double area = 0;
	for(int i=1;i<n-1;i++)
	{
		//printf("%d %d",v[0].second - v[i].second,v[0].first - v[i].first);
		double seta1,seta2;
		if((v[0].first - v[i].first)!=0)
		{
			seta1 = atan2((v[i].second - v[0].second) , (v[i].first - v[0].first));
		}
		else seta1 = PI/2 * ((v[0].second - v[i].second)>0?-1:1);
		if(v[0].first - v[i+1].first!=0)
		{
			seta2 = atan2((v[i+1].second - v[0].second) , (v[i+1].first - v[0].first));
		}
		else seta2 = PI/2 * ((v[0].second - v[i+1].second)>0?-1:1);
		double seta = seta1 - seta2;
		double len1 = sqrt(((double)v[0].second - v[i].second)*((double)v[0].second - v[i].second)+((double)v[0].first - v[i].first)*((double)v[0].first - v[i].first));
		double len2 = sqrt(((double)v[0].second - v[i+1].second)*((double)v[0].second - v[i+1].second)+((double)v[0].first - v[i+1].first)*((double)v[0].first - v[i+1].first));
		//printf("%lf %lf %lf %lf\n",seta1,seta2,len2,len1 * len2 * sin(seta));
		area += len1 * len2 * sin(seta) /2;
	}
	if(area<0) area = -area;
	printf("%.1lf",area);
}
/*
외적을 이용한 다각형의 넓이
*/ 
