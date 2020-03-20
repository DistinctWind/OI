#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int MAXN=10001;
int n,w,h,tot,ans;
int d[MAXN*2];
struct Line{
	int x,y1,y2,b;
	friend bool operator < (Line a,Line b)
	{
		if (a.x==b.x) return a.b>b.b;
		else return a.x<b.x;
	}
}lin[MAXN<<1];
struct Tree{
	int dat,add;
}t[MAXN<<3];
int q(int x)
{
	return lower_bound(d+1,d+1+tot,x)-d;
}
int raw(int x)
{
	return d[x];
}
inline void setup()
{
	tot=0,ans=0;
	memset(d,0,sizeof(d));
	memset(lin,0,sizeof(lin));
	memset(t,0,sizeof(t));
}
inline void readiscrete()
{
	for (int i=1;i<=n;i++)
	{
		int x,y,b;
		scanf("%d%d%d",&x,&y,&b);
		d[++tot]=y; lin[tot].x=x,lin[tot].y1=y,lin[tot].y2=y+h-1,lin[tot].b=b;
		d[++tot]=y+h-1; lin[tot].x=x+w-1,lin[tot].y1=y,lin[tot].y2=y+h-1,lin[tot].b=-b;
	}
	sort(d+1,d+1+tot);
	sort(lin+1,lin+1+tot);
	tot=unique(d+1,d+1+tot)-d-1;
}
void build(int k,int l,int r)
{
	t[k].dat=t[k].add=0;
	if (l==r) return;
	int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
}
inline void pushdown(int k,int l,int r,int mid)
{
	if (t[k].add==0) return;
	t[lson].add+=t[k].add;
	t[lson].dat+=t[k].add;
	t[rson].add+=t[k].add;
	t[rson].dat+=t[k].add;
	t[k].add=0;
}
void addplus(int k,int l,int r,int x,int y,int v)
{
	if (x<=l&&r<=y)
	{
		t[k].add+=v;
		t[k].dat+=v;
		return;
	}
	int mid=l+r>>1;
	pushdown(k,l,r,mid);
	if (x<=mid) addplus(lson,l,mid,x,y,v);
	if (mid<y) addplus(rson,mid+1,r,x,y,v);
	t[k].dat=max(t[lson].dat,t[rson].dat);
}
inline void solve()
{
	for (int i=1;i<=2*n;i++)
	{
		addplus(1,1,tot-1,q(lin[i].y1),q(lin[i].y2)-1,lin[i].b);
		ans=max(ans,t[1].dat);
	}
	printf("%d\n",ans);
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d%d%d",&n,&w,&h)!=EOF)
	{
		setup();
		readiscrete();
		build(1,1,tot-1);
		solve();
	}
}
