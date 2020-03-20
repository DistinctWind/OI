#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int MAXN=5e5+10;
const int MAXM=5e5+10;
const int MAXL=5e5+10;
struct Rect{
	int x,y1,y2,k,id;
}rec[(MAXN+MAXM)<<1];
bool cmp(Rect a,Rect b)
{
	return a.x<b.x;
}
struct Tree{
	int l,r,ltag,stag;
	long long sum,len;
	int size(){
		return r-l+1;
	}
	Tree operator += (const Tree &b) {
		sum+=b.sum; len+=b.len;
		return *this;
	}
}tree[MAXL<<2];
int n,m,w,l,tot;
long long ans[MAXM];
int read()
{
	int x=0; 
	char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9')
	{
		x=x*10+a-'0';
		a=getchar();
	}
	return x;
}
void build(int k,int l,int r)
{
	tree[k].l=l,tree[k].r=r;
	if (l==r)
	{
		tree[k].ltag=tree[k].stag=tree[k].sum=tree[k].len=0;
		return;
	}
	int mid=l+r>>1;
	if (l<=mid) build(lson,l,mid);
	if (mid<r) build(rson,mid+1,r);
}
void pushdown(int k)
{
	if (tree[k].ltag)
	{
		int tag=tree[k].ltag;
		tree[lson].ltag+=tag;
		tree[rson].ltag+=tag;
		tree[lson].len+=tag*tree[lson].size();
		tree[rson].len+=tag*tree[rson].size();
		tree[k].ltag=0;
	}
	if (tree[k].stag)
	{
		int tag=tree[k].stag;
		tree[lson].stag+=tag;
		tree[rson].stag+=tag;
		tree[lson].sum+=tag*tree[lson].size();
		tree[rson].sum+=tag*tree[rson].size();
		tree[k].stag=0;
	}
}
void pushup(int k)
{
	tree[k].len=tree[lson].len+tree[rson].len;
	tree[k].sum=tree[lson].sum+tree[rson].sum;
}
void modify(int k,int x,int y,int val,int coef)
{
	if (x<=tree[k].l&&tree[k].r<=y)
	{
		tree[k].ltag+=coef;
		tree[k].stag+=coef*val;
		tree[k].len+=coef*tree[k].size();
		tree[k].sum+=coef*val*tree[k].size();
		return;
	}
	int mid=tree[k].l+tree[k].r>>1;
	pushdown(k);
	if (x<=mid) modify(lson,x,y,val,coef);
	if (mid<y) modify(rson,x,y,val,coef);
	pushup(k);
}
Tree query(int k,int x,int y)
{
	if (x<=tree[k].l&&tree[k].r<=y) return tree[k];
	Tree res;
	res.len=res.sum=0;
	int mid=tree[k].l+tree[k].r>>1;
	pushdown(k);
	if (x<=mid) res+=query(lson,x,y);
	if (mid<y) res+=query(rson,x,y);
	return res;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	clock_t start,end;
	start=clock();
	n=read(); m=read(); w=read(); l=read();
	for (int i=1,x1,y1,x2,y2;i<=n;i++)
	{
		x1=read(); y1=read(); x2=read(); y2=read();
		tot++; rec[tot].x=x1,rec[tot].y1=y1+1,rec[tot].y2=y2,rec[tot].k=1,rec[tot].id=0;
		tot++; rec[tot].x=x2,rec[tot].y1=y1+1,rec[tot].y2=y2,rec[tot].k=-1,rec[tot].id=0;
	}
	for (int i=1,x1,y1,x2,y2;i<=m;i++)
	{
		x1=read(); y1=read(); x2=read(); y2=read();
		tot++; rec[tot].x=x1,rec[tot].y1=y1+1,rec[tot].y2=y2,rec[tot].k=-1,rec[tot].id=i;
		tot++; rec[tot].x=x2,rec[tot].y1=y1+1,rec[tot].y2=y2,rec[tot].k=1,rec[tot].id=i;
	}
	sort(rec+1,rec+1+tot,cmp);
	build(1,0,l);
	for (int i=1;i<=tot;i++)
	{
		if (!rec[i].id) modify(1,rec[i].y1,rec[i].y2,rec[i].x,rec[i].k);
		else
		{
			Tree res=query(1,rec[i].y1,rec[i].y2);
			ans[rec[i].id]+=rec[i].k*(res.len*rec[i].x-res.sum);
		}
	}
	for (int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
	end=clock();
	printf("Time=%.3lf",(double)(end-start)/CLOCKS_PER_SEC);
}
