#include <cstdio>
#include <climits>
#include <iostream>
#define lson k<<1
#define rson k<<1|1
#define INF 2311111
using namespace std;
const int MAXN=500001;
struct Tree{
	long long dat,sum,lmax,rmax;
}t[MAXN*4];
int n,q;
int num[MAXN];
inline void pushup(int k)
{
	t[k].sum=t[lson].sum+t[rson].sum;
	t[k].lmax=max(t[lson].lmax,t[lson].sum+t[rson].lmax);
	t[k].rmax=max(t[rson].rmax,t[lson].rmax+t[rson].sum);
	t[k].dat=max(max(t[lson].dat,t[rson].dat),t[lson].rmax+t[rson].lmax);
}
void setup(int k,int l,int r)
{
	if (l==r)
	{
		t[k].dat=t[k].sum=t[k].lmax=t[k].rmax=num[l];
		return;
	}
	int mid=l+r>>1;
	setup(lson,l,mid);
	setup(rson,mid+1,r);
	pushup(k);
}
void modify(int k,int l,int r,int x,long long v)
{
	if (l==r&&l==x)
	{
		t[k].dat=t[k].sum=t[k].lmax=t[k].rmax=v;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) modify(lson,l,mid,x,v);
	if (mid<x) modify(rson,mid+1,r,x,v);
	pushup(k);
}
Tree query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return t[k];
	Tree a,b,ans;
	a.dat=b.dat=a.sum=b.sum=a.lmax=b.lmax=a.rmax=b.rmax=-INF;
	ans.sum=0;
	int mid=l+r>>1;
	if (x<=mid)
	{
		a=query(k<<1,l,mid,x,y);
		ans.sum+=a.sum;
	}
	if (mid<y) 
	{
		b=query(k<<1|1,mid+1,r,x,y);
		ans.sum+=b.sum;
	}
	ans.dat=max(max(a.dat,b.dat),a.rmax+b.lmax);
	ans.lmax=max(a.lmax,a.sum+b.lmax);
	ans.rmax=max(b.rmax,a.rmax+b.sum);
	if (x>mid) ans.lmax=max(ans.lmax,b.lmax);
	if (mid>=y) ans.rmax=max(ans.rmax,a.rmax);
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	setup(1,1,n);
	for (int i=1;i<=q;i++)
	{
		int swi,x,y;
		scanf("%d%d%d",&swi,&x,&y);
		if (swi==2) modify(1,1,n,x,y);
		else 
		{
			if (x>y) swap(x,y);
			printf("%lld\n",query(1,1,n,x,y).dat);
		}
	}
}
