#include <cstdio>
#include <iostream>
#include <limits.h>
#include <cstring>
using namespace std;
const int MAXN=3e3+1;
int n,m,q[MAXN];
long long s[MAXN],f[MAXN][MAXN];
long long pow(long long x)
{
	return x*x;
}
double slope(int u,int j,int k)
{
	return double(f[j][u]-f[k][u]+s[j]*s[j]-s[k]*s[k])/(double)(s[j]-s[k]);
}
inline void dp()
{
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		f[i][1]=pow(s[i]);
	}
	for (int t=2;t<=m;t++)
	{
		memset(q,0,sizeof(q));
		int head=1,tail=1;
		for (int i=1;i<=n;i++)
		{
			while (head<tail&&slope(t-1,q[head],q[head+1])<2*s[i]) head++;
			f[i][t]=f[q[head]][t-1]+pow(s[i]-s[q[head]]);
			while (head<tail&&slope(t-1,q[tail-1],q[tail])>slope(t-1,q[tail],i)) tail--;
			q[++tail]=i;
		}
	}
	long long ans=f[n][m]*m-pow(s[n]);
	printf("%lld",ans);
}
/*
inline void dp()
{
	memset(f,0x7f,sizeof(f));
	f[0][0]=0;
	for (int t=1;t<=m;t++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<i;j++)
				f[i][t]=min(f[i][t],f[j][t-1]+pow(s[i]-s[j]));
		}
	}
	printf("%lld",f[n][m]*m-pow(s[n]));
}*/
/*inline void dp()
{
	for (int t=1;t<=m;t++)
	{
		int head=1,tail=1;
		memset(q,0,sizeof(q));
		for (int i=1;i<=n;i++)
		{
			while (head<tail&&2*m*s[i]*(s[q[head+1]]-s[q[head]])>g[q[head+1]]+m*pow(s[q[head+1]])-(g[q[head]]-m*pow(s[q[head]]))) head++;
			f[i]=g[q[head]]+m*pow(s[i]-s[q[head]]);
			while (head<tail&&(g[i]+m*pow(s[i])-(g[q[tail]]+m*pow(s[q[tail]])))/(2*m*(s[i]-s[q[tail]]))>(g[q[tail]]+m*pow(s[q[tail]])-(g[q[tail-1]]+m*pow(s[q[tail-1]])))/(2*m*(s[q[tail]]-s[q[tail-1]]))) tail--;
			q[++tail]=i;
		}
		memcpy(g,f,sizeof(f));
	}
	printf("%lld",f[n]-pow(s[n]));
}*/
/*Fake DP Unaccepted;
inline void dp()
{
	memset(f,0x7f,sizeof(f));
	memset(g,0xff,sizeof(g));
	g[0]=0;
	for (int t=1;t<=m;t++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<i;j++)
			{
				f[i]=min(f[i],g[j]+m*pow(s[i]-s[j]));
			}
		}
		memcpy(g,f,sizeof(f));
	}
	printf("%lld",f[n]-pow(s[n]));
}*/
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
		s[i]+=s[i-1];
	}
	dp();
}
//DHOJ http://47.104.154.247/problem.php?cid=1101&pid=6
//LGOJ https://www.luogu.org/problemnew/show/P4072
