#include <cstdio>
#define int long long
using namespace std;
const int MAXN=1e6+10;
long long c[2][MAXN];
long long a[MAXN],sum[MAXN];
int n,q;
long long read()
{
	long long x=0,k=1;
	char a=getchar();
	while (a<'0'||'9'<a)
	{
		if (a=='-')
			k=-1;
		a=getchar();
	}
	while ('0'<=a&&a<='9')
	{
		x=x*10+a-'0';
		a=getchar();
	}
	return k*x;
}
void write(long long x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x>9)
		write(x/10);
	putchar(x%10+'0');
}
int lowbit(int x)
{
	return x&(-x);
}
void insert(int swi,int pos,long long x)
{
	for (;pos<=n;pos+=lowbit(pos))
		c[swi][pos]+=x;
}
long long query(int swi,int pos)
{
	long long res=0;
	for (;pos>0;pos-=lowbit(pos))
		res+=c[swi][pos];
	return res;
}
main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	n=read(); q=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		sum[i]=sum[i-1]+a[i];
	}
	for (int i=1;i<=q;i++)
	{
		int swi,l,r,x;
		swi=read(); swi--;
		if (swi==0)
		{
			l=read(); r=read(); x=read();
			insert(0,l,x);
			insert(0,r+1,-x);
			insert(1,l,l*x);
			insert(1,r+1,-(r+1)*x);
		}
		else if (swi==1)
		{
			l=read(); r=read();
			long long ans=sum[r]+(r+1)*query(0,r)-query(1,r);
			ans-=sum[l-1]+l*query(0,l-1)-query(1,l-1);
			printf("%lld\n",ans);
		}
	}
}
