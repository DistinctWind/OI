#include <cstdio>
#include <iostream>
#include <ctime>
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int MAXN=1e6+1;
int n,m,p,q,col[MAXN*4];
inline void pushdown(int k,int l,int r,int mid)
{
	if (col[k]!=-1)
		col[lson]=col[rson]=col[k];
}
void modify(int k,int l,int r,int x,int y,int c)
{
	if (x<=l&&r<=y)
	{
		col[k]=c;
		return;
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	if (x<=mid) modify(lson,l,mid,x,y,c);
	if (mid<y) modify(rson,mid+1,r,x,y,c);
	if ((col[lson]==col[rson]&&col[lson]==-1)||col[lson]!=col[rson]) col[k]=-1;
}
int query(int k,int l,int r,int x)
{
	if (col[k]!=-1) return col[k];
	int mid=l+r>>1;
	if (x<=mid) return query(lson,l,mid,x);
	if (mid<x) return query(rson,mid+1,r,x);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	clock_t start,end;
	start=clock();
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for (int i=1;i<=m;i++)
	{
		int l=(i*p+q)%n+1;
		int r=(i*q+p)%n+1;
		if (l<=r) modify(1,1,n,l,r,i);
		else modify(1,1,n,r,l,i);
	}
	for (int i=1;i<=n;i++)
		printf("%d\n",query(1,1,n,i));
	end=clock();
	printf("%.3lf",(double)(end-start)/CLOCKS_PER_SEC);
}
