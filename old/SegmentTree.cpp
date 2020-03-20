#include <cstdio>
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int MAXN=100001;
long long sum[MAXN*4],add[MAXN*4],a[MAXN];
int n,m;
void setup(int k,int l,int r)
{
	if (l==r) 
	{
		sum[k]=a[l];
		return;
	}
	int mid=l+r>>1;
	setup(lson,l,mid);
	setup(rson,mid+1,r);
	sum[k]=sum[lson]+sum[rson];
}
inline void pushdown(int k,int l,int r,int mid)
{
	if (add[k]==0) return;
	add[lson]+=add[k];
	sum[lson]+=(mid-l+1)*add[k];
	add[rson]+=add[k];
	sum[rson]+=(r-(mid+1)+1)*add[k];
	add[k]=0;
}
void modify(int k,int l,int r,int x,int y,long long v)
{
	if (x<=l&&r<=y)
	{
		add[k]+=v;
		sum[k]+=(r-l+1)*v;
		return;
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	if (x<=mid) modify(lson,l,mid,x,y,v);
	if (mid<y) modify(rson,mid+1,r,x,y,v);
	sum[k]=sum[lson]+sum[rson];
	return;
}
long long query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y)
	{
		return sum[k];
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	long long res=0;
	if (x<=mid) res+=query(lson,l,mid,x,y);
	if (mid<y) res+=query(rson,mid+1,r,x,y);
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	setup(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int swi,x,y;
		scanf("%d%d%d",&swi,&x,&y);
		if (swi==1)
		{
			long long tmp;
			scanf("%lld",&tmp);
			modify(1,1,n,x,y,tmp);
		}
		else
		{
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
}
