#include <cstdio>
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
const int MAXN=5e5+1;
int n,m,q[MAXN];
long long f[MAXN],s[MAXN];
long long pow(long long x)
{
	return x*x;
}
long long x(int j,int k)
{
	long long y=f[j]-f[k]+pow(s[j])-pow(s[k]);
	long long x=2*s[j]-2*s[k];
	if (x==0) return 0x3f3f3f3f3f3f3f;
	return y/x;
}
inline void dp()
{
	memset(f,0,sizeof(f));
	memset(q,0,sizeof(q));
	int head=1,tail=1;
	for (int i=1;i<=n;i++)
	{
		while (head<tail&&x(q[head+1],q[head])<s[i]) head++;
		f[i]=f[q[head]]+pow(s[i]-s[q[head]])+m;
		while (head<tail&&x(i,q[tail])<x(q[tail],q[tail-1])) tail--;
		q[++tail]=i;
	}
	printf("%lld\n",f[n]);
}
/*Force DP
inline void dp()
{
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			f[i]=min(f[i],f[j]+(sumc[i]-sumc[j])*(sumc[i]-sumc[j])+m);
		}
	}
	printf("%d\n",f[n]);
}*/
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		for (int i=1;i<=n;i++)
			scanf("%lld",&s[i]),s[i]+=s[i-1];
		dp();
	}
}
//LOJ https://loj.ac/problem/10191
//DHOJ http://47.104.154.247/problem.php?cid=1101&pid=0
