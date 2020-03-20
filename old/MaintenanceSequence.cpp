#include <cstdio>
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int MAXN=100001;
int n,m;
long long a[MAXN],mul[MAXN*4],add[MAXN*4],sum[MAXN*4],p;
long long read()
{
	long long x=0,k=1;
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
void setup(int k,int l,int r)
{
	mul[k]=1;
	add[k]=0;
	if (l==r)
	{
		sum[k]=a[l];
		return;
	}
	int mid=l+r>>1;
	setup(lson,l,mid);
	setup(rson,mid+1,r);
	sum[k]=(sum[lson]+sum[rson])%p;
}
inline void pushdown(int k,int l,int r,int mid)
{
	if (add[k]==0&&mul[k]==1) return;
	sum[lson]=(sum[lson]*mul[k]%p+(mid-l+1)*add[k])%p;
	sum[rson]=(sum[rson]*mul[k]%p+(r-(mid+1)+1)*add[k])%p;
	mul[lson]=mul[lson]*mul[k]%p;
	mul[rson]=mul[rson]*mul[k]%p;
	add[lson]=((add[lson]*mul[k])%p+add[k])%p;
	add[rson]=((add[rson]*mul[k])%p+add[k])%p;
	add[k]=0,mul[k]=1;
}
void multiply(int k,int l,int r,int x,int y,long long v)
{
	if (x<=l&&r<=y)
	{
		mul[k]=(mul[k]*v)%p;
		sum[k]=(sum[k]*v)%p;
		add[k]=(add[k]*v)%p;
		return;
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	if (x<=mid) multiply(lson,l,mid,x,y,v);
	if (mid<y) multiply(rson,mid+1,r,x,y,v);
	sum[k]=(sum[lson]+sum[rson])%p;
}
void plus(int k,int l,int r,int x,int y,long long v)
{
	if (x<=l&&r<=y)
	{
		add[k]=(add[k]+v)%p;
		sum[k]=(sum[k]+(r-l+1)*v)%p;
		return;
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	if (x<=mid) plus(lson,l,mid,x,y,v);
	if (mid<y) plus(rson,mid+1,r,x,y,v);
	sum[k]=(sum[lson]+sum[rson])%p;
}
long long query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return sum[k]%p;
	int mid=l+r>>1;
	long long res=0;
	pushdown(k,l,r,mid);
	if (x<=mid) res=(res+query(lson,l,mid,x,y))%p;
	if (mid<y) res=(res+query(rson,mid+1,r,x,y))%p;
	return res%p;
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read(); p=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	setup(1,1,n);
	m=read();
	for (int i=1;i<=m;i++)
	{
		int swi,l,r;
		long long c;
		swi=read(); l=read(); r=read();
		if (swi==1)
		{
			c=read();
			multiply(1,1,n,l,r,c);
		}
		else if (swi==2)
		{
			c=read();
			plus(1,1,n,l,r,c);
		}
		else
		{
			write(query(1,1,n,l,r));
			putchar('\n');
		}
	}
}
