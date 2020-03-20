#include <cstdio>
using namespace std;
double H,h,D;
double S(double x)
{
	double delta=H*x/(H-h)-D;
	if (delta<=0) return (H/(H-h)-1)*x;
	return D+H-(x+(D*H-D*h)/x);
}
int main()
{
	//freopen("in.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lf%lf%lf",&H,&h,&D);
		double l=0,r=D,esc=1e-7;
		while (r-l>=esc)
		{
			double m1=l+(r-l)/3;
			double m2=r-(r-l)/3;
			if (S(m1)<S(m2)) l=m1;
			else r=m2;
		}
		printf("%.3lf\n",S(r));
	}
}
