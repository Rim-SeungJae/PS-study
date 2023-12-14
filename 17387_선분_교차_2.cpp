#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	long long x1,x2,x3,x4,y1,y2,y3,y4;
	scanf("%lld %lld %lld %lld\n%lld %lld %lld %lld",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	long double grad1,grad2,c1,c2;
	bool flag1=false,flag2=false,is_ver1=false,is_ver2=false;
	if(x1-x2==0) is_ver1 =true;
	else
	{
		grad1 = (double)(y1-y2) / (x1-x2);
	}
	if(x3-x4==0) is_ver2=true;
	else
	{
		grad2 = (double)(y3-y4)/(x3-x4);
	}
	if(grad1 == grad2)
	{
		if(is_ver1)
		{
			if(x1 != x3) flag1 = flag2 = false;
			else if(y1>=y3&&y1<=y4) flag1 = flag2 = true;
			else if(y1<=y3&&y1>=y4) flag1 = flag2 = true;
			else if(y2<=y3&&y2>=y4) flag1 = flag2 = true;
			else if(y2<=y3&&y2>=y4) flag1 = flag2 = true;
			else if(y3>=y1&&y3<=y2) flag1 = flag2 = true;
			else if(y3<=y1&&y3>=y2) flag1 = flag2 = true;
			else if(y4<=y1&&y4>=y2) flag1 = flag2 = true;
			else if(y4<=y1&&y4>=y2) flag1 = flag2 = true;
		}
		else if(grad1 == 0)
		{
			if(y1 != y3) flag1 = flag2 = false;
			else if(x1>=x3&&x1<=x4) flag1 = flag2 = true;
			else if(x1<=x3&&x1>=x4) flag1 = flag2 = true;
			else if(x2<=x3&&x2>=x4) flag1 = flag2 = true;
			else if(x2<=x3&&x2>=x4) flag1 = flag2 = true;
			else if(x3>=x1&&x3<=x2) flag1 = flag2 = true;
			else if(x3<=x1&&x3>=x2) flag1 = flag2 = true;
			else if(x4<=x1&&x4>=x2) flag1 = flag2 = true;
			else if(x4<=x1&&x4>=x2) flag1 = flag2 = true;
		}
		else
		{
			c1 = y1 - grad1 * x1;
			c2 = y3 - grad2 * x3;
			if(abs(c1-c2)>0.000000001) flag1 = flag2 = false;
			else if(x1>=x3&&x1<=x4) flag1 = flag2 = true;
			else if(x1<=x3&&x1>=x4) flag1 = flag2 = true;
			else if(x2<=x3&&x2>=x4) flag1 = flag2 = true;
			else if(x2<=x3&&x2>=x4) flag1 = flag2 = true;
			else if(x3>=x1&&x3<=x2) flag1 = flag2 = true;
			else if(x3<=x1&&x3>=x2) flag1 = flag2 = true;
			else if(x4<=x1&&x4>=x2) flag1 = flag2 = true;
			else if(x4<=x1&&x4>=x2) flag1 = flag2 = true;
		}
	}
	else if(is_ver1)
	{
		c2 = y3 - grad2 * x3;
		long double y_meet;
		y_meet = grad2 * x1 + c2;
		if(y_meet>=y1&&y_meet<=y2) flag1 = flag2 = true;
		else if(y_meet<=y1&&y_meet>=y2) flag1 = flag2 = true;
		/*
		c2 = y3 - grad2 * x3;
		if((x3-x1)*(x4-x1)<=0) flag1 = true;
		if((grad2 * x1 + c2 - y1)*(grad2 * x2 + c2 - y2)<=0) flag2 = true;
		*/
	}
	else if(is_ver2)
	{
		c1 = y1 - grad1 * x1;
		long double y_meet;
		y_meet = grad1 * x3 + c1;
		if(y_meet>=y3&&y_meet<=y4) flag1 = flag2 = true;
		else if(y_meet<=y3&&y_meet>=y4) flag1 = flag2 = true;
		/*
		c1 = y1 - grad1 * x1;
		if((grad1 * x3 + c1 - y3)*(grad1 * x4 + c1 - y4)<=0) flag1 = true;
		if((x1-x3)*(x2-x3)<=0) flag2 = true;
		*/
	}
	else
	{
		c1 = y1 - grad1 * x1;
		c2 = y3 - grad2 * x3;
		long double x_meet;
		x_meet = (c2 - c1) / (grad1 - grad2);
		if(x_meet>=x3&&x_meet<=x4)
		{
			if(x_meet>=x1&&x_meet<=x2) flag1 = flag2 = true;
			else if(x_meet<=x1&&x_meet>=x2) flag1 = flag2 = true;
		}
		else if(x_meet<=x3&&x_meet>=x4)
		{
			if(x_meet>=x1&&x_meet<=x2) flag1 = flag2 = true;
			else if(x_meet<=x1&&x_meet>=x2) flag1 = flag2 = true;
		}
		/*
		if((grad1 * x3 + c1 - y3)*(grad1 * x4 + c1 - y4)<=0) flag1 = true;
		if((grad2 * x1 + c2 - y1)*(grad2 * x2 + c2 - y2)<=0) flag2 = true;
		*/
		//printf("%d %d %d %d\n",(grad1 * x3 + c1 - y3),(grad1 * x4 + c1 - y4),(grad2 * x1 + c2 - y1),(grad2 * x2 + c2 - y2));
	}
	if(flag1&&flag2) printf("1");
	else printf("0");
}
