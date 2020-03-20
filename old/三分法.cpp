#include <cstdio>
using namespace std;
const int MAXN=15;
const double esc=1e-9;
int n;
double a[MAXN],l,r;
double calc(double x)
{
	double res=a[n]*x+a[n-1];
	for (int i=n-2;i>=0;i--)
		res=res*x+a[i];
	return res;
}
int main()
{
	scanf("%d%lf%lf",&n,&l,&r);
	for (int i=n;i>=0;i--)
		scanf("%lf",&a[i]);
	while (r-l>=esc)
	{
		double m1=l+(r-l)/3,m2=r-(r-l)/3;
		if (calc(m1)<calc(m2)) l=m1;
		else r=m2;
	}
	printf("%.5lf",l);
}
