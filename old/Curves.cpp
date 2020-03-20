#include <cstdio>
#define MAXN 100001
using namespace std;
struct function{
	int a,b,c;
	double cal(double x){
		return a*x*x+b*x+c;
	}
}s[MAXN];
int T,n;
double max(double a,double b)
{
	return a>b?a:b;
}
double f(double x)
{
	double ans=-1e10;
	for (int i=1;i<=n;i++)
		ans=max(ans,s[i].cal(x));
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
		double l=0,r=1000,esc=1e-11;
		while (r-l>esc)
		{
			double m1=l+(r-l)/3;
			double m2=r-(r-l)/3;
			if (f(m1)<=f(m2)) r=m2;
			else l=m1;
		}
		printf("%.4lf\n",f(l));
	}
}
