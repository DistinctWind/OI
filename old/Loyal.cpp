#include <cstdio>
#include <iostream>
#include <climits>
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int MAXM=100001;
long long a[MAXM],dat[MAXM*4];
int m,n;
void setup(int k,int l,int r)
{
	if (l==r) 
	{
		dat[k]=a[l];
		return;
	}
	int mid=l+r>>1;
	setup(lson,l,mid);
	setup(rson,mid+1,r);
	dat[k]=min(dat[lson],dat[rson]);
}
void modify(int k,int l,int r,int x,long long v)
{
	if (l==r&&l==x)
	{
		dat[k]=v;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) modify(lson,l,mid,x,v);
	if (mid<x) modify(rson,mid+1,r,x,v);
	dat[k]=min(dat[lson],dat[rson]);
}
long long query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y)
	{
		return dat[k];
	}
	int mid=l+r>>1;
	long long res=LLONG_MAX;
	if (x<=mid) res=min(res,query(lson,l,mid,x,y));
	if (mid<y) res=min(res,query(rson,mid+1,r,x,y));
	return res;
}
int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	setup(1,1,m);
	for (int i=1;i<=n;i++)
	{
		int swi,x,y;
		scanf("%d%d%d",&swi,&x,&y);
		if (swi==1) printf("%lld ",query(1,1,m,x,y));
		else modify(1,1,m,x,y);
	}
}
