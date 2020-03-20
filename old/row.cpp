#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=3e5+10;
const int maxm=8e6+10;
struct Tree{
	int ls,rs,sz;
	ll val;
}tree[maxm];
int n,m,q,limit,now,tot;
int root[maxn],cnt[maxn];
int read()
{
	int s=0;
	char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') 
	{
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
void build(int &u,int l,int r)
{
	u=++tot;
	tree[u].ls=tree[u].rs=tree[u].sz=0;
	if (now==n+1)
	{
		if (r<=n) tree[u].sz=r-l+1;
		if (l<=n) tree[u].sz=n-l+1;
	}
	else
	{
		if (r<=m-1) tree[u].sz=r-l+1;
		if (l<=m-1) tree[u].sz=m-l;
	}
	return;
}
ll query(int &u,int l,int r,int x)
{
	if (!u)
	{
		build(u,l,r);
		if (l==r)
		{
			if (now==n+1) tree[u].val=(ll)(m*l);
			else tree[u].val=(ll)((now-1)*m+l);
		}
	}
	--tree[u].sz;
	if (l==r) return tree[u].val;
	int mid=l+r>>1;
	if (tree[u].ls)
	{
		if (x<=tree[tree[u].ls].sz) return query(tree[u].ls,l,mid,x);
		return query(tree[u].rs,mid+1,r,x-tree[tree[u].ls].sz);
	}
	else
	{
		if (x<=mid-l+1) return query(tree[u].ls,l,mid,x);
		return query(tree[u].rs,mid+1,r,x+l-mid-1);
	}
	return 0;
}
void update(int &u,int l,int r,int x,ll val)
{
	if (!u)
	{
		build(u,l,r);
		if (l==r) tree[u].val=val;
	}
	++tree[u].sz;
	if (l==r) return;
	int mid=l+r>>1;
	if (x<=mid) update(tree[u].ls,l,mid,x,val);
	else update(tree[u].rs,mid+1,r,x,val);
	return;
}
int main()
{
	int x,y;
	freopen("in.txt","r",stdin);
	n=read(); m=read(); q=read();
	limit=max(n,m)+q;
	for (int i=1;i<=q;++i)
	{
		ll tmp;
		x=read(); y=read();
		if (y==m)
		{
			now=n+1;
			tmp=query(root[now],1,limit,x);
		}
		else
		{
			now=x;
			tmp=query(root[now],1,limit,y);
		}
		printf("%lld\n",tmp);
		now=n+1;
		++cnt[now];
		update(root[now],1,limit,n+cnt[now],tmp);
		if (y!=m)
		{
			now=n+1;
			tmp=query(root[now],1,limit,x);
			now=x;
			++cnt[now];
			update(root[now],1,limit,m-1+cnt[now],tmp);
		}
	}
	return 0;
}
