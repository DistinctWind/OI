#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;
const int MAXN=5e4+1;
struct S{
	long long l,w;
	friend bool operator < (S x,S y)
	{
		if (x.l==y.l) return x.w>y.w;
		else return x.l>y.l;
	}
}t[MAXN],s[MAXN];
long long n,tot,q[MAXN];
long long f[MAXN];
double k(int pos1,int pos2)
{
	long long y=f[pos1]-f[pos2];
	long long x=-s[pos1+1].l+s[pos2+1].l;
	if (x==0) return LLONG_MAX;
	else return 1.0*y/x;
}
inline void dp()
{
	sort(t+1,t+1+n);
	s[0].w=-1;
	for (int i=1;i<=n;i++)
	{
		if (t[i].w<=s[tot].w) continue;
		s[++tot]=t[i];
	}
	int head=1,tail=1;
	for (int i=1;i<=tot;i++)
	{
		while (head<tail&&k(q[head+1],q[head])<s[i].w) 
			head++;
		f[i]=f[q[head]]+s[q[head]+1].l*s[i].w;
		while (head<tail&&k(q[tail],q[tail-1])>k(q[tail],i)) 
			tail--;
		q[++tail]=i;
	}
	printf("%lld",f[tot]);
}
/* In mess
inline void dp()
{
	sort(t+1,t+1+n);
	int tot=0;
	for (int i=1;i<=n;i++)
	{
		if (t[i].b<=s[tot].b) continue;
		s[++tot]=t[i];
	}
	int head=1,tail=0;
	for (int i=1;i<=tot;i++)
	{
		while (head<=tail&&(f[q[head]-1]-f[q[head+1]-1])>-s[i].a*(s[q[head]].a-s[q[head+1]].a)) head++;
		f[i]=f[q[head]]+s[i].a*s[q[head]].b;
		while (head<=tail&&(f[q[tail]]-f[q[tail-1]])*(s[i].b-s[q[tail]].b)<(f[i]-f[q[tail]])*(s[q[tail]].b-s[q[tail-1]].b)) tail--;
		q[++tail]=i;
	}
	printf("%lld",f[tot]);
}
/*Force DP 40;
inline void dp()
{
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			f[i]=min(f[i],f[j]+search_a(j+1,i)*search_b(j+1,i));
		}
	}
	printf("%d",f[n]);
}*/
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld%lld",&t[i].l,&t[i].w);
	dp();
}
//DHOJ http://47.104.154.247/problem.php?cid=1101&pid=2
