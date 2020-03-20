#include <cstdio>
#include <cstring>
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int MAXN=25010;
const int MAXR=1e6+10;
struct Range{
	int l,r;
}ran[MAXN];
int f[MAXR];
int data[MAXN<<2],add[MAXN<<2];
bool cmp(Range a,Range b)
{
	return a.r<b.r;
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		data[k]=0x3f3f3f3f;
		return ;
	}
	int mid=l+r>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
}
void modify(int k,int l,int r,int x,int v)
{
	if (l==r&&l==x)
	{
		data[k]=min(data[k],v);
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) modify(lson,l,mid,x,v);
	else if (mid<y) modify(rson,mid+1,r,x,v);
	data[k]=min(data[lson],data[rson]);
}
int query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y)
		return data[k];
	int mid=l+r>>1;
	int res=0x3f3f3f3f;
	if (x<=mid) res=min(res,query(lson,l,mid,x,y));
	if (mid<=y) res=min(res,query(lson,mid+1,r,x,y));
	return res;
}
inline void solve()
{
	build(1,1,r);
	sort(ran+1,ran+1+n,cmp);
	memset(f,0x3f,sizeof(f));
	modify(1,1,n,l-1,0);
	for (int i=1;i<=n;i++)
	{
		int res=query(1,1,n,ran[i].l-1,ran[i].r-1);
		modify()
	}
}
int main()
{
	
} 
