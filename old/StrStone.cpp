#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
typedef set<pair<int,int> >::iterator It;
const int MAXN=1e5+1;
const int LOGN=20;
int n,m,t,dfn[MAXN],depth[MAXN],f[MAXN][LOGN],cnt;
ll ans,dist[MAXN];
set <pair<int,int> > s;
It it,l,r;
vector <pair<int,ll> > e[MAXN];
void sdfs(int u,int pre,int dep)
{
	depth[u]=dep;
	f[u][0]=pre;
	dfn[u]=++cnt;
	for (int i=0;i<e[u].size();i++)
		if (e[u][i].first!=pre)
		{
			dist[e[u][i].first]=dist[u]+e[u][i].second;
			sdfs(e[u][i].first,u,dep+1);
		}
}
inline void init()
{
	for (int j=0;1<<(j+1)<n;j++)
		for (int i=1;i<=n;i++)
			if (f[i][j]==0) f[i][j+1]=0;
			else f[i][j+1]=f[f[i][j]][j];
}
int lca(int a,int b)
{
	if (depth[a]>depth[b]) swap(a,b);
	for (int i=t;i>=0;i--)
		if (depth[f[b][i]]>=depth[a])
			b=f[b][i];
	if (a==b) return a;
	for (int i=t;i>=0;i--)
		if (f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	return f[a][0];
}
ll path(int x,int y)
{
	return dist[x]+dist[y]-(dist[lca(x,y)]<<1);
}
inline void insert(int x)
{
	s.insert(make_pair(dfn[x],x));
	it=s.find(make_pair(dfn[x],x));
	l=it==s.begin()?--s.end():--it;
	it=s.find(make_pair(dfn[x],x));
	r=it==--s.end()?s.begin():++it;
	it=s.find(make_pair(dfn[x],x));
	ans=ans-path((*l).second,(*r).second);
	ans=ans+path((*l).second,(*it).second)+path((*it).second,(*r).second);
}
inline void remove(int x)
{
	it=s.find(make_pair(dfn[x],x));
	l=it==s.begin()?--s.end():--it;
	it=s.find(make_pair(dfn[x],x));
	r=it==--s.end()?s.begin():++it;
	it=s.find(make_pair(dfn[x],x));
	ans=ans-path((*l).second,(*it).second)-path((*it).second,(*r).second);
	ans=ans+(path((*l).second,(*r).second));
	s.erase(make_pair(dfn[x],x));
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b; ll dis;
		scanf("%d%d%lld",&a,&b,&dis);
		e[a].push_back(make_pair(b,dis));
		e[b].push_back(make_pair(a,dis));
	}
	t=int(log(double(n))/log(2.0))+1;
	sdfs(1,0,0);
	init();
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		char a;
		int x;
		scanf(" %c",&a);
		if (a=='?') printf("%lld\n",ans>>1);
		else if (a=='+')
		{
			scanf("%d",&x);
			insert(x);
		}
		else if (a=='-')
		{
			scanf("%d",&x);
			remove(x);
		}
	}
}
