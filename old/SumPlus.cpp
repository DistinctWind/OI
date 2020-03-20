#include <cstdio>
using namespace std;
const int MAXN=1e5+1;
int n,m,p;
long long num[MAXN],mul[MAXN*4],add[MAXN*4],sum[MAXN*4];
long long read()
{
	long long x=0,k=1;
	char a=getchar();
	while (a<'0'||'9'<a)
	{
		if (a=='-') k=-1;
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
		x=-x;
		putchar('-');
	}
	if (x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
}
void setup(int k,int l,int r)
{
	add[k]=0; mul[k]=1;
	if (l==r)
	{
		sum[k]=num[l];
		return;
	}
	else
	{
		int mid=l+r>>1;
		setup(k*2,l,mid);
		setup(k*2+1,mid+1,r);
		sum[k]=sum[k*2]+sum[k*2+1];
	}
	sum[k]=sum[k]%p;
}
inline void pushdown(int k,int l,int r,int mid)
{
	sum[k*2]=(sum[k*2]*mul[k]+(mid-l+1)*add[k])%p;
	sum[k*2+1]=(sum[k*2+1]*mul[k]+(r-(mid+1)+1)*add[k])%p;
	mul[k*2]=(mul[k*2]*mul[k])%p;
	mul[k*2+1]=(mul[k*2+1]*mul[k])%p;
	add[k*2]=(add[k*2]*mul[k]+add[k])%p;
	add[k*2+1]=(add[k*2+1]*mul[k]+add[k])%p;
	mul[k]=1; add[k]=0;
}
void multiply(int k,int l,int r,int x,int y,long long v)
{
	if (y<l||r<x) return;
	if (x<=l&&r<=y)
	{
		sum[k]=(sum[k]*v)%p;
		add[k]=(add[k]*v)%p;
		mul[k]=(mul[k]*v)%p;
		return;
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	multiply(k*2,l,mid,x,y,v);
	multiply(k*2+1,mid+1,r,x,y,v);
	sum[k]=(sum[k*2]+sum[k*2+1])%p;
}
void add_plus(int k,int l,int r,int x,int y,long long v)
{
	if (y<l||r<x) return;
	if (x<=l&&r<=y)
	{
		sum[k]=(sum[k]+(r-l+1)*v)%p;
		add[k]=(add[k]+v)%p;
		return;
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	add_plus(k*2,l,mid,x,y,v);
	add_plus(k*2+1,mid+1,r,x,y,v);
	sum[k]=(sum[k*2]+sum[k*2+1])%p;
}
long long query(int k,int l,int r,int x,int y)
{
	if (y<l||r<x) return 0;
	if (x<=l&&r<=y) return sum[k]%p;
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	return (query(k*2,l,mid,x,y)+query(k*2+1,mid+1,r,x,y))%p;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	n=read(); m=read(); p=read();
	for (int i=1;i<=n;i++)
		num[i]=read();
	setup(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int k=read(),l,r;
		long long x;
		if (k==1)
		{
			l=read(); r=read(); x=read();
			multiply(1,1,n,l,r,x);
		}
		else if (k==2)
		{
			l=read(); r=read(); x=read();
			add_plus(1,1,n,l,r,x);
		}
		else if (k==3)
		{
			l=read(); r=read();
			write(query(1,1,n,l,r));
			putchar('\n');
		}
	}	
}
//LGOJ https://www.luogu.org/problem/P3373
