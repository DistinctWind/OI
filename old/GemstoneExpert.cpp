#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=200010;
const int MAXM=200010;
struct Stone{
	int h,x;
}s[MAXN];
struct Range{
	int id,l,r;
}r[MAXM];
int n,m,dis[MAXN],ans[MAXN],res[MAXN];
bool operator < (Stone a,Stone b)
{
	if (a.h==b.h) return a.x<b.x;
	else return a.h<b.h;
}
bool operator < (Range a,Range b)
{
	return a.r<b.r;
}
int lowbit(int x)
{
	return x&(-x);
}
void modify(int pos,int val)
{
	for (;pos>=1;pos-=lowbit(pos))
		res[pos]=min(res[pos],val);
}
int query(int pos)
{
	int tmp=0x3f3f3f3f;
	for (;pos<=n;pos+=lowbit(pos))
		tmp=min(tmp,res[pos]);
	return tmp;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&s[i].h);
		s[i].x=i;
	}
	sort(s+1,s+1+n);
	for (int i=2;i<=n;i++)
	{
		if (s[i].h==s[i-1].h) dis[s[i].x]=s[i].x-s[i-1].x;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&r[i].l,&r[i].r);
		r[i].id=i;
	}
	sort(r+1,r+1+m);
	memset(res,0x3f,sizeof(res));
	for (int i=1,j=1;i<=n;i++)
	{
		if (dis[i]) modify(i-dis[i],dis[i]);
		for (;r[j].r<=i&&j<=m;j++)
			ans[r[j].id]=query(r[j].l);
	}
	for (int i=1;i<=m;i++)
		if (ans[i]==0x3f3f3f3f) printf("-1\n");
		else printf("%d\n",ans[i]);
}
