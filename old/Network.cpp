#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN=100001;
const int MAXM=200001;
const int LOGN=19;
int head[MAXN],cnt_edge;
int n,m,t,ans;
int depth[MAXN],f[MAXN][LOGN],d[MAXN],sum[MAXN];
struct Edge{
	int nxt,to;
}edge[(MAXN+MAXM)<<1];
inline void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
}
void dfs(int u,int pre,int dep)
{
	depth[u]=dep;
	f[u][0]=pre;
	for (int i=head[u];i;i=edge[i].nxt)
	{
		if (edge[i].to!=pre)
		{
			dfs(edge[i].to,u,dep+1);
		}
	}
}
inline void init()
{
	for (int j=0;1<<j+1<n;j++)
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
void cdfs(int pos,int pre)
{
	for (int i=head[pos];i;i=edge[i].nxt)
	{
		if (edge[i].to!=pre)
		{
			cdfs(edge[i].to,pos);
			sum[pos]+=sum[edge[i].to];
		}
	}
	sum[pos]+=d[pos];
	if (pre!=0&&sum[pos]==0) ans+=m;
	else if (sum[pos]==1) ans++;
	else return;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b); add(b,a);
	}
	t=int(log(double(n))/log(2.0))+1;
	dfs(1,0,0);
	init();
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		d[a]++; d[b]++;
		d[lca(a,b)]-=2;
	}
	cdfs(1,0);
	printf("%d",ans);
}
