#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;
const int MAXN=1e5+10;
const int MAXM=7e6+10;
typedef long long ll;
ll n,m,q,u,v,t,cnt;
ll delta;
ll a[MAXN];
queue <ll> Q,q1,q2;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&q,&u,&v,&t);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++)
		Q.push(a[i]);
	for (int i=1;i<=m;i++)
	{
		ll t1,t2,t0,res,x1,x2;
		t0=t1=t2=res=-inf;
		if (!Q.empty()) t0=Q.front();
		if (!q1.empty()) t1=q1.front();
		if (!q2.empty()) t2=q2.front();
		res=max(t0,max(t1,t2));
		if (!Q.empty()&&res==t0) Q.pop();
		else if (!q1.empty()&&res==t1) q1.pop();
		else if (!q2.empty()&&res==t2) q2.pop();
		res=res+delta;
		x1=floor((ll)u*res/v); x2=res-floor((ll)u*res/v);
		q1.push(x1-delta-q);
		q2.push(x2-delta-q);
		delta+=q;
		if (cnt<floor(i/t)) cnt++,printf("%lld ",res);
	}
	putchar('\n');
	cnt=0;
	for (int i=1;i<=n+m;i++)
	{
		ll t1,t2,t0,res;
		t0=t1=t2=res=-inf;
		if (!Q.empty()) t0=Q.front();
		if (!q1.empty()) t1=q1.front();
		if (!q2.empty()) t2=q2.front();
		res=max(t0,max(t1,t2));
		if (!Q.empty()&&res==t0) Q.pop();
		else if (!q1.empty()&&res==t1) q1.pop();
		else if (!q2.empty()&&res==t2) q2.pop();
		res=res+delta;
		if (cnt<floor(i/t)) cnt++,printf("%lld ",res);
	}
}
