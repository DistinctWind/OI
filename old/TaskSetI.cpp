#include <cstdio>
#include <limits.h>
using namespace std;
const int MAXN=5001;
int n,s,t[MAXN],c[MAXN];
long long sumt[MAXN],sumc[MAXN],f[MAXN];
long long min(long long a,long long b)
{
	return a<b?a:b;
}
inline void dp()
{
	f[1]=t[1]*c[1]+(sumc[n]-sumc[0])*s;
	for (int i=2;i<=n;i++)
	{
		f[i]=INT_MAX;
		for (int j=0;j<i;j++)
		{
			f[i]=min(f[i],f[j]+sumt[i]*(sumc[i]-sumc[j])+s*(sumc[n]-sumc[j]));
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i],&c[i]);
		sumt[i]=sumt[i-1]+t[i];
		sumc[i]=sumc[i-1]+c[i];
	}
	dp();
	printf("%lld",f[n]);
}
//LOJ https://loj.ac/problem/10184
//LGOJ https://www.luogu.org/problemnew/show/P2365
//JOYOI http://www.joyoi.cn/problem/tyvj-1098
