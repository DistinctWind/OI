#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int MAXN=101;
int n,m,t,num;
double a[MAXN*2],ans;
struct Line{
	double x,y1,y2;
	int k;
	friend bool operator < (Line a,Line b)
	{
		return a.x<b.x;
	}
}lin[MAXN*2];
struct Tree{
	int c;
	double len,cnt;
}tree[MAXN*8];
inline void setup()
{
	m=0,t=0,ans=0;
	memset(lin,0,sizeof(lin));
	memset(tree,0,sizeof(tree));
	memset(a,0,sizeof(a));
}
inline void readiscrete()
{
	for (int i=1;i<=n;i++)
	{
		double x1,y1,x2,y2;
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		a[++t]=y1; lin[t].x=x1,lin[t].y1=y1,lin[t].y2=y2,lin[t].k=1;
		a[++t]=y2; lin[t].x=x2,lin[t].y1=y1,lin[t].y2=y2,lin[t].k=-1;
	}
	sort(a+1,a+1+t);
	sort(lin+1,lin+1+t);
	m=unique(a+1,a+1+t)-a-1;
}
int q(double x)
{
	return lower_bound(a+1,a+1+m,x)-a;
}
double raw(int x)
{
	return a[x];
}
void build(int k,int l,int r)
{
	tree[k].len=tree[k].cnt=0;
	if (l==r)
		return;
	int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
}
void modify(int k,int l,int r,int x,int y,int v)
{
	if (x<=l&&r<=y)
	{
		tree[k].cnt+=v;
		if (tree[k].cnt>0) tree[k].len=raw(r+1)-raw(l);
		else tree[k].len=0;
	}
	if (l==r) return;
	int mid=l+r>>1;
	if (x<=mid) modify(lson,l,mid,x,y,v);
	if (mid<y) modify(rson,mid+1,r,x,y,v);
	if (tree[k].cnt>0) tree[k].len=raw(r+1)-raw(l);
	else tree[k].len=tree[lson].len+tree[rson].len;
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d",&n),n!=0)
	{
		setup();
 		readiscrete();
		build(1,1,m-1);
		for (int i=1;i<t;i++)
		{
			modify(1,1,m,q(lin[i].y1),q(lin[i].y2)-1,lin[i].k);
			ans=ans+tree[1].len*(lin[i+1].x-lin[i].x);
		}
		printf("Test case #%d\n",++num);
		printf("Total explored area: %.2lf\n\n",ans);
	}
} 
