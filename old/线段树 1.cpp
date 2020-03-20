#include <cstdio>
#define lson k<<1
#define rson k<<1|1
using namespace std;
typedef long long ll;
const int MAXN=100010;
int n,m;
ll num[MAXN],add[MAXN<<2],sum[MAXN<<2];
void build(int k,int l,int r)
{
	if (l==r)
	{
		sum[k]=(ll)num[l];
		return;
	}
	int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	sum[k]=sum[lson]+sum[rson];
}
inline void pushdown(int k,int l,int r,int mid)
{
	if (add[k]==0) return;
	add[lson]+=add[k];
	sum[lson]+=(mid-l+1)*add[k];
	add[rson]+=add[k];
	sum[rson]+=(r-mid)*add[k];
	add[k]=0;
}
void modify(int k,int l,int r,int x,int y,ll val)
{
	if (x<=l&&r<=y)
	{
		sum[k]+=(r-l+1)*val;
		add[k]+=val;
		return;
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	if (x<=mid) modify(lson,l,mid,x,y,val);
	if (mid<y) modify(rson,mid+1,r,x,y,val);
	sum[k]=sum[lson]+sum[rson];
	return;
}
ll query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y)
	{
		return sum[k];
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	ll res=0;
	if (x<=mid) res+=query(lson,l,mid,x,y);
	if (mid<y) res+=query(rson,mid+1,r,x,y);
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",&num[i]);
	build(1,1,n);
	for (int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&z,&x,&y);
		if (z==1)
		{
			ll val;
			scanf("%lld",&val);
			modify(1,1,n,x,y,val);
		}
		else
		{
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
}
