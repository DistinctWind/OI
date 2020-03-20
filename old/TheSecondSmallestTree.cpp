#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=100010;
const int MAXM=300010;
const int LOGN=18;
typedef long long ll;
struct Edge{
	int a,b;
	ll dis;
	bool used;
	Edge(){
		used=false;
	}
}edge[MAXM];
vector <pair<int,ll> > e[MAXN];
ll ans=LLONG_MAX;
int n,m,t;
int fa[MAXN],f[MAXN][LOGN],depth[MAXN];
ll g[MAXN][LOGN][2],sum;
int find(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(Edge a,Edge b)
{
	return a.dis<b.dis;
}
inline void setup()
{
	sort(edge+1,edge+1+m,cmp);
	for (int i=1;i<=n;i++)
		fa[i]=i;
}
inline void kruskal()
{
	setup();
	for (int i=1;i<=m;i++)
	{
		int x,y;
		x=find(edge[i].a);
		y=find(edge[i].b);
		if (x==y) continue;
		edge[i].used=true;
		fa[x]=y;
		sum+=edge[i].dis;
		e[edge[i].a].push_back(make_pair(edge[i].b,edge[i].dis));
		e[edge[i].b].push_back(make_pair(edge[i].a,edge[i].dis));
	}
}
void dfs(int u,int pre,int dep)
{
	depth[u]=dep;
	f[u][0]=pre;
	g[u][0][1]=LLONG_MIN;
	for (int i=0;i<e[u].size();i++)
	{
		if (e[u][i].first!=pre)
		{
			g[e[u][i].first][0][0]=e[u][i].second;
			dfs(e[u][i].first,u,dep+1);
		}
	}
}
inline void init()
{
	for (int j=0;1<<(j+1)<n;j++)
		for (int i=1;i<=n;i++)
		{
			if (f[i][j]==0) f[i][j+1]=0;
			else f[i][j+1]=f[f[i][j]][j];
			g[i][j+1][0]=max(g[i][j][0],g[f[i][j]][j][0]);
			if (g[i][j][0]==g[f[i][j]][j][0])
				g[i][j+1][1]=max(g[i][j][1],g[f[i][j]][j][1]);
			else if (g[i][j][0]<g[f[i][j]][j][0])
				g[i][j+1][1]=max(g[i][j][0],g[f[i][j]][j][1]);
			else if (g[i][j][0]>g[f[i][j]][j][0])
				g[i][j+1][1]=max(g[i][j][1],g[f[i][j]][j][0]);
		}
}
/*pair<ll,ll> lca(int a,int b)
{
	ll res1=(ll)LLONG_MIN+1,res2=LLONG_MIN;
	if (depth[a]>depth[b]) swap(a,b);
	for (int i=t;i>=0;i--)
		if (depth[f[b][i]]>=depth[a])
			b=f[b][i],res1=max(res1,g[b][i][0]),res2=max(res2,g[b][i][1]);
	if (a==b) return make_pair(res1,res2);
	for (int i=t;i>=0;i--)
		if (f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i],res1=max(max(g[a][i][0],g[b][i][0]),res1),res2=max(max(g[a][i][1],g[b][i][1]),res2);
	return make_pair(max(max(g[a][0][0],g[b][0][0]),res1),max(max(g[a][0][1],g[b][0][1]),res2));
}*/
pair<ll,ll> lca(int a,int b)
{
	ll res1=LLONG_MIN,res2=LLONG_MIN;
	if (depth[a]>depth[b]) swap(a,b);
	for (int i=t;i>=0;i--)
		if (depth[f[b][i]]>=depth[a])
		{
			res1=max(res1,g[b][i][0]);
			res2=max(res2,g[b][i][1]);
			if (res1>g[b][i][0])
				res2=max(res2,g[b][i][0]);
			b=f[b][i];
		}
	if (a==b) return make_pair(res1,res2);
	for (int i=t;i>=0;i--)
		if (f[a][i]!=f[b][i])
		{
			res1=max(res1,g[a][i][0]);
			res2=max(res2,g[a][i][1]);
			if (res1>g[a][i][0])
				res2=max(res2,g[a][i][0]);
			a=f[a][i];
			res1=max(res1,g[b][i][0]);
			res2=max(res2,g[b][i][1]);
			if (res2>g[b][i][0])
				res2=max(res2,g[a][i][0]);
			b=f[b][i];
		}
	res1=max(res1,g[a][0][0]);
	res2=max(res2,g[a][0][1]);
	if (res1>g[a][0][0])
		res2=max(res2,g[a][0][0]);
	res1=max(res1,g[b][0][0]);
	res2=max(res2,g[b][0][1]);
	if (res2>g[b][0][0])
		res2=max(res2,g[b][0][0]);
	return make_pair(res1,res2);
}
void solve()
{
	for (int i=1;i<=m;i++)
	{
		if (!edge[i].used)
		{
			pair <ll,ll> l=lca(edge[i].a,edge[i].b);
			if (edge[i].dis>l.first&&l.first!=LLONG_MIN) ans=min(ans,sum-l.first+edge[i].dis);
			if (edge[i].dis==l.first&&l.second!=LLONG_MIN) ans=min(ans,sum-l.second+edge[i].dis);
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y; ll val;
		scanf("%d%d%lld",&x,&y,&val);
		edge[i].a=x,edge[i].b=y,edge[i].dis=val;
	}
	kruskal();
	t=int(log(double(n))/log(2.0))+1;
	dfs(1,0,1);
	init();
	solve();
}
