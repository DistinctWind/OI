#include <cstdio>
using namespace std;
const int MAXN=500010;
int n,m;
long long c[MAXN];
long long read()
{
	long long x=0,k=1; char a=getchar();
	while (a<'0'||a>'9') k=(a=='-'?-1:1),a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return k*x;
}
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,long long val)
{
	for (;x<=n;x+=lowbit(x))
		c[x]+=val;
}
long long query(int x)
{
	long long res=0;
	for (;x>=1;x-=lowbit(x))
		res+=c[x];
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read(); m=read();
	for (int i=1,tmp;i<=n;i++)
	{
		tmp=read();
		update(i,tmp);
	}
	for (int i=1;i<=m;i++)
	{
		long long x,y,z;
		z=read(); x=read(); y=read();
		if (z==1) update(x,y);
		else printf("%lld\n",(long long)query(y)-query(x-1));
	}
}
