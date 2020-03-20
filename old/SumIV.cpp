#include <cstdio>
using namespace std;
const int MAXN=100001;
int n,m;
long long add[MAXN*4],sum[MAXN*4];
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int read()
{
	int x=0,k=1;
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
		write(x/10);
	putchar(x%10+'0');
}
void modify(int k,int l,int r,int x,int y,int v)
{
	if (x<=l&&r<=y)
	{
		add[k]+=v;
		return;
	}
	sum[k]+=(min(r,y)-max(l,x)+1)*v;
	int mid=l+r>>1;
	if (x<=mid) modify(k*2,l,mid,x,y,v);
	if (mid<y) modify(k*2+1,mid+1,r,x,y,v);
}
long long query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return sum[k]+(r-l+1)*add[k];
	int mid=l+r>>1;
	long long res=(min(r,y)-max(l,x)+1)*add[k];
	if (x<=mid) res+=query(k*2,l,mid,x,y);
	if (mid<y) res+=query(k*2+1,mid+1,r,x,y);
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read(); m=read();
	for (int i=1;i<=n;i++)
	{
		int tmp=read();
		modify(1,1,n,i,i,tmp);
	}
	for (int i=1;i<=m;i++)
	{
		int k,l,r,x;
		k=read();
		if (k==1)
		{
			l=read(); r=read(); x=read();
			modify(1,1,n,l,r,x);
		}
		else if (k==2)
		{
			l=read(); r=read();
			write(query(1,1,n,l,r));
			putchar('\n');
		}
	}
}
//LGOJ https://www.luogu.org/problem/P3372
