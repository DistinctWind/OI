#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int MAXN=1e5+1;
struct Tree{
	long long dat,sum;
}t[MAXN*4];
long long num[MAXN];
int n,m;
void build(int k,int l,int r)
{
	if (l==r)
	{
		t[k].dat=t[k].sum=num[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
	t[k].dat=max(t[k<<1].dat,t[k<<1|1].dat);
}
void modify(int k,int l,int r,int x,int y)
{
	if (t[k].dat<=1) return;
	if (l==r&&x<=l&&l<=y)
	{
		t[k].dat=t[k].sum=(long long)floor(sqrt(t[k].sum));
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) modify(k<<1,l,mid,x,y);
	if (mid<y) modify(k<<1|1,mid+1,r,x,y);
	t[k].dat=max(t[k<<1].dat,t[k<<1|1].dat);
	t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
}
long long query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y)
	{
		return t[k].sum;
	}
	int mid=l+r>>1;
	long long res=0;
	if (x<=mid) res+=query(k<<1,l,mid,x,y);
	if (mid<y) res+=query(k<<1|1,mid+1,r,x,y);
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&num[i]);
	build(1,1,n);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		if (x==1) printf("%lld\n",query(1,1,n,l,r));
		else modify(1,1,n,l,r);
	}
}
