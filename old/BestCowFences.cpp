#include <cstdio>
#define MAXN 100001
using namespace std;
int n,L;
double a[MAXN],b[MAXN],sum[MAXN];
double min(double a,double b)
{
	return a>b?b:a;
}
double max(double a,double b)
{
	return a>b?a:b;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&L);
	for (int i=1;i<=n;i++)
		scanf("%lf",&a[i]);
	double l=-1e6,r=1e6;
	double esc=1e-5;
	while (r-l>esc)
	{
		double mid=(l+r)/2;
		for (int i=1;i<=n;i++)
			b[i]=a[i]-mid;
		for (int i=1;i<=n;i++)
			sum[i]=sum[i-1]+b[i];
		double ans=-1e6,min_val=1e6;
		for (int i=L;i<=n;i++)
		{
			min_val=min(min_val,sum[i-L]);
			ans=max(ans,sum[i]-min_val);
		}
		if (ans>=0) l=mid;
		else r=mid;
	}
	printf("%d",int(r*1000));
}
//LOJ https://loj.ac/problem/10012
