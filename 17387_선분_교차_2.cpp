#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int ccw(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
	long long v_x1 = x2-x1,v_y1 = y2-y1,v_x2 = x3-x2,v_y2 = y3-y2;
	long long ccw = v_x1*v_y2 - v_x2*v_y1;
	if(ccw>0) return 1;
	else if(ccw==0) return 0;
	else return -1;
}

int main()
{
	long long x1,x2,x3,x4,y1,y2,y3,y4;
	scanf("%lld %lld %lld %lld\n%lld %lld %lld %lld",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	int ccw1,ccw2,ccw3,ccw4;
	ccw1 = ccw(x1,y1,x2,y2,x3,y3);
	ccw2 = ccw(x1,y1,x2,y2,x4,y4);
	ccw3 = ccw(x3,y3,x4,y4,x1,y1);
	ccw4 = ccw(x3,y3,x4,y4,x2,y2);
	bool result =false;
	if(ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0)
	{
			if(x1>x2)
			{
				swap(x1,x2);
				swap(y1,y2);
			}
			else if(x1==x2 && y1>y2)
			{
				swap(x1,x2);
				swap(y1,y2);
			}
			if(x3>x4)
			{
				swap(x3,x4);
				swap(y3,y4);
			}
			else if(x3==x4 && y3>y4)
			{
				swap(x3,x4);
				swap(y3,y4);
			}
			if((x2>x3?true:(x2==x3?y2>=y3:false))&&(x1<x4?true:(x1==x4?y1<=y4:false))) result = true;
	}
	else if(ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0)
	{
		result = true;
		/*
		if((grad1 * x3 + c1 - y3)*(grad1 * x4 + c1 - y4)<=0) flag1 = true;
		if((grad2 * x1 + c2 - y1)*(grad2 * x2 + c2 - y2)<=0) flag2 = true;
		*/
		//printf("%d %d %d %d\n",(grad1 * x3 + c1 - y3),(grad1 * x4 + c1 - y4),(grad2 * x1 + c2 - y1),(grad2 * x2 + c2 - y2));
	}
	if(result) printf("1");
	else printf("0");
}
/*
의외로 애먹은 문제.
기울기(함수)를 이용하려 풀이할 경우 부동소수점 오류로 인해서 정확한 풀이가 불가능
ccw라고 하는 외적을 이용한 알고리즘을 활용하여 풀어야 한다
그리고 또 한 직선상에 있는 두 개의 선분의 겹침 여부를 확인할 때는(26-49행)
pair 자료형을 활용하는 편이 편리하다.
*/ 
