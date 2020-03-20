#include <cstdio>
#include <cmath>
using namespace std;
const double esc=1e-8;
double ax,ay,bx,by,cx,cy,dx,dy,p,q,r;
double dis(double x1,double y1,double x2,double y2)
{
	double dis_x=x1-x2,dis_y=y1-y2;
	return sqrt(dis_x*dis_x+dis_y*dis_y);
}
double f(double x1,double y1,double x2,double y2)
{
	return dis(x1,y1,x2,y2)/r+dis(x2,y2,dx,dy)/q;
}
double cal_cd(double x,double y)
{
	double lx=cx,ly=cy,rx=dx,ry=dy;
	while (dis(lx,ly,rx,ry)>esc)
	{
		double temp_x=(rx-lx)/3,temp_y=(ry-ly)/3;
		double lm_x=lx+temp_x,lm_y=ly+temp_y,rm_x=rx-temp_x,rm_y=ry-temp_y;
		double l_ans=f(x,y,lm_x,lm_y),r_ans=f(x,y,rm_x,rm_y);
		if (l_ans<r_ans) rx=rm_x,ry=rm_y;
		else lx=lm_x,ly=lm_y;
	}
	return f(x,y,lx,ly);
}
double cal_ab()
{
	double lx=ax,ly=ay,rx=bx,ry=by;
	while (dis(lx,ly,rx,ry)>esc)
	{
		double temp_x=(rx-lx)/3,temp_y=(ry-ly)/3;
		double lm_x=lx+temp_x,lm_y=ly+temp_y,rm_x=rx-temp_x,rm_y=ry-temp_y;
		double l_ans=cal_cd(lm_x,lm_y)+dis(ax,ay,lm_x,lm_y)/p,r_ans=cal_cd(rm_x,rm_y)+dis(ax,ay,rm_x,rm_y)/p;
		if (l_ans<r_ans) rx=rm_x,ry=rm_y;
		else lx=lm_x,ly=lm_y;
	}
	return cal_cd(lx,ly)+dis(ax,ay,lx,ly)/q;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
	printf("%.2lf",cal_ab());
}
//LOJ https://loj.ac/problem/10017
