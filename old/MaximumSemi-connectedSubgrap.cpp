#include <cstdio>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int MAXN=100010;
const int MAXM=1000010;
struct Edge{
	int nxt,to;
}edgeo[MAXM],edgen[MAXM];
int n,m;
int cnt_edgeo,heado[MAXN];
int cnt_edgen,headn[MAXN];
int dfn[MAXN],low[MAXN],b[MAXN],t,cnt_block;
int in[MAXN],root[MAXN];
bool is[MAXN];
set <pair<int,int> > judge;
stack <int> s;
vector <int> vec[MAXN];
ll x,ans[MAXN],dis[MAXN],ans1,ans2;
inline void addo(int from,int to)
{
	cnt_edgeo++;
	edgeo[cnt_edgeo].nxt=heado[from];
	heado[from]=cnt_edgeo;
	edgeo[cnt_edgeo].to=to;
}
inline void addn(int from,int to)
{
	cnt_edgen++;
	edgen[cnt_edgen].nxt=headn[from];
	headn[from]=cnt_edgen;
	edgen[cnt_edgen].to=to;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++t;
	is[x]=true;
	s.push(x);
	for (int i=heado[x];i;i=edgeo[i].nxt)
	{
		if (!dfn[edgeo[i].to])
		{
			tarjan(edgeo[i].to);
			if (low[edgeo[i].to]<low[x])
				low[x]=low[edgeo[i].to];
		}
		else if (is[edgeo[i].to]&&low[edgeo[i].to]<low[x])
			low[x]=low[edgeo[i].to];
	}
	if (dfn[x]==low[x])
	{
		cnt_block++;
		int i;
		do
		{
			i=s.top(); s.pop();
			b[i]=cnt_block;
			is[i]=false;
			vec[cnt_block].push_back(i);
		}
		while (dfn[i]!=low[i]);
	}
}
inline void minify()
{
	for (int i=1;i<=n;i++)
		if (!dfn[i])
			tarjan(i);
	for (int i=1;i<=n;i++)
	{
		for (int j=heado[i];j;j=edgeo[j].nxt)
		{
			if (b[i]==b[edgeo[j].to]) continue;
			if (judge.count(make_pair(b[i],b[edgeo[j].to]))==1) continue;
			judge.insert(make_pair(b[i],b[edgeo[j].to]));
			addn(b[i],b[edgeo[j].to]);
			in[b[edgeo[j].to]]++;	
		}
	}
}
inline void topsort()
{
	queue <int> q;
	for (int i=1;i<=cnt_block;i++)
	{
		if (in[i]==0)
			q.push(i),dis[i]=vec[i].size(),ans[i]=1;
	}
	while (!q.empty())
	{
		int h=q.front(); q.pop();
		for (int i=headn[h];i;i=edgen[i].nxt)
		{
			if (dis[edgen[i].to]<dis[h]+vec[edgen[i].to].size())
				dis[edgen[i].to]=dis[h]+vec[edgen[i].to].size(),ans[edgen[i].to]=ans[h];
			else if (dis[edgen[i].to]==dis[h]+vec[edgen[i].to].size())
				ans[edgen[i].to]=(ans[edgen[i].to]%x+ans[h]%x)%x;
			in[edgen[i].to]--;
			if (in[edgen[i].to]==0)
				q.push(edgen[i].to);
		}
	}
}
inline void solve()
{
	for (int i=1;i<=cnt_block;i++)
	{
		if (dis[i]>ans1)
		{
			ans1=dis[i];
			ans2=ans[i];
		}
		else if (dis[i]==ans1)
			ans2=(ans2%x+ans[i]%x)%x;
	}
	printf("%lld\n%lld",ans1,ans2);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%lld",&n,&m,&x);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		addo(a,b);
	}
	minify();
	topsort();
	solve();
}
//LOJ https://loj.ac/problem/10092
//LGOJ https://www.luogu.org/problem/P2272
