#include <cstdio>
#include <cmath>
#include <cstring>
#include <utility>
#include <iostream>
using namespace std;
const double esp=1e-8;
const int MAXN=20;
int t,n,cntPara,para[200],f[1<<MAXN];
double x[MAXN],y[MAXN];
int read()
{
	int x=0;char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
pair<double,double> calc(double o1,double p1,double q1,double o2,double p2,double q2)
{
	if (fabs(o1*p2-o2*p1)<esp||fabs(o2*p1-o1*p2)<esp) return make_pair(1,0);
	return make_pair((p1*q2-p2*q1)/(o1*p2-o2*p1),(o1*q2-o2*q1)/(o2*p1-o1*p2));
}
bool inc(double p,double q,pair<double,double> tmp)
{
	return fabs(p*p*tmp.first+p*tmp.second-q)<=esp;
}
inline void pre()
{
	memset(f,0x3f,sizeof(f));
	memset(para,0,sizeof(para));
	n=read(); read();
	for (int i=0;i<n;i++)
		scanf("%lf %lf",&x[i],&y[i]);
	cntPara=0;
	for (int i=0;i<n;i++)
	{
		para[cntPara++]=(1<<i);
		for (int j=i+1,vis=0;j<n;j++)
		{
			if ((vis>>j)&1) continue;
			pair<double,double> ans=calc(x[i]*x[i],x[i],-y[i],x[j]*x[j],x[j],-y[j]);
			//printf("%lf %lf\n",ans.first,ans.second);
			if (ans.first>=0) continue;
			para[cntPara]=(1<<i);
			for (int k=j;k<n;k++)
				if (inc(x[k],y[k],ans))
					para[cntPara]|=(1<<k),vis|=(1<<k);
			cntPara++;
		}
	}
}
inline void dp()
{
	f[0]=0;
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<cntPara;j++)
			f[i|para[j]]=min(f[i|para[j]],f[i]+1);
	printf("%d \n",f[(1<<n)-1]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	t=read();
	while (t--)
	{
		pre();
		dp();
	}
}
