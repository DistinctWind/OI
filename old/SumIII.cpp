#include <cstdio>
using namespace std;
const int MAXN=1e6+1;
int n,q;
long long add[MAXN*4],sum[MAXN*4];
int read()
{
	int x=0,k=1;
	char a=getchar();
	while (a<'0'||a>'9')
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
inline void Add(int k,int l,int r,int v)
{
	add[k]+=v;
	sum[k]+=(r-l+1)*v;
}
inline void pushdown(int k,int l,int r,int mid)
{
	if (add[k]==0) return;
	Add(k*2,l,mid,add[k]);
	Add(k*2+1,mid+1,r,add[k]);
	add[k]=0;
}
void modify(int k,int l,int r,int x,int y,int v)
{
	if (x<=l&&r<=y)
		return Add(k,l,r,v);
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	if (x<=mid) modify(k*2,l,mid,x,y,v);
	if (mid<y) modify(k*2+1,mid+1,r,x,y,v);
	sum[k]=sum[k*2]+sum[k*2+1];
}
long long query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return sum[k];
	int mid=l+r>>1;
	long long res=0;
	pushdown(k,l,r,mid);
	if (x<=mid) res+=query(k*2,l,mid,x,y);
	if (mid<y) res+=query(k*2+1,mid+1,r,x,y);
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	n=read(); q=read();
	for (int i=1;i<=n;i++)
	{
		int tmp=read();
		modify(1,1,n,i,i,tmp);
	}
	for (int i=1;i<=q;i++)
	{
		int k=read(),l,r,x;
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
//LOJ https://loj.ac/problem/132 AE
//LGOJ https://www.luogu.org/problem/P3372
