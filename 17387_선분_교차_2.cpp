#include<cstdio>
#include<cmath>

using namespace std;

int ccw(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
	long long v_x1 = x2-x1,v_y1 = y2-y1,v_x2 = x3-x2,v_y2 = y3-y2;
	long long ccw = v_x1*v_y2 - v_x2*v_y1
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
	
	if(ccw1 * ccw2 == 0 && ccw3 * ccw4 == 0)
	{
			if(y1>=y3&&y1<=y4) result = true;
			else if(y1<=y3&&y1>=y4) result = true;
			else if(y2<=y3&&y2>=y4) result = true;
			else if(y2<=y3&&y2>=y4) result = true;
			else if(y3>=y1&&y3<=y2) result = true;
			else if(y3<=y1&&y3>=y2) result = true;
			else if(y4<=y1&&y4>=y2) result = true;
			else if(y4<=y1&&y4>=y2) result = true;
			else if(x1>=x3&&x1<=x4) result = true;
			else if(x1<=x3&&x1>=x4) result = true;
			else if(x2<=x3&&x2>=x4) result = true;
			else if(x2<=x3&&x2>=x4) result = true;
			else if(x3>=x1&&x3<=x2) result = true;
			else if(x3<=x1&&x3>=x2) result = true;
			else if(x4<=x1&&x4>=x2) result = true;
			else if(x4<=x1&&x4>=x2) result = true;
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
	if(flag1&&flag2) printf("1");
	else printf("0");
}
