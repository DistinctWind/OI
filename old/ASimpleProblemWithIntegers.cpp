#include <cstdio>
using namespace std;
const int MAXN=100001;
long long add[MAXN*4],sum[MAXN*4];
int n,q;
inline void Add(int k,int l,int r,long long v)
{
	add[k]+=v;
	sum[k]+=(r-l+1)*v;
}
inline void pushdown(int k,int l,int r,int mid)
{
	if (add[k]==0) return;
	Add(k<<1,l,mid,add[k]);
	Add((k<<1)+1,mid+1,r,add[k]);
	add[k]=0;
}
void modify(int k,int l,int r,int x,int y,long long v)
{
	if (x<=l&&r<=y) return Add(k,l,r,v);
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	if (x<=mid) modify(k<<1,l,mid,x,y,v);
	if (mid<y) modify((k<<1)+1,mid+1,r,x,y,v);
	sum[k]=sum[k<<1]+sum[(k<<1)+1];
}
long long query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return sum[k];
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	long long res=0;
	if (x<=mid) res+=query(k<<1,l,mid,x,y);
	if (mid<y) res+=query((k<<1)+1,mid+1,r,x,y);
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		long long tmp;
		scanf("%lld",&tmp);
		modify(1,1,n,i,i,tmp);
	}
	for (int i=1;i<=q;i++)
	{
		char swi;
		int l,r;
		long long x;
		scanf(" %c",&swi);
		if (swi=='Q')
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,1,n,l,r));
		}
		if (swi=='C')
		{
			scanf("%d%d%lld",&l,&r,&x);
			modify(1,1,n,l,r,x);
		}
	}
}
