#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int MAXN=1001;
const int LOGN=15;
int n,q,t,dist[MAXN],f[MAXN][LOGN],depth[MAXN];
int head[MAXN],cnt_edge;
struct Edge{
	int nxt,to,dis;
}edge[MAXN*2];
inline void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
void dfs(int u,int pre,int dep)
{
	f[u][0]=pre;
	depth[u]=depth[pre]+1;
	for (int i=head[u];i;i=edge[i].nxt)
	{
		if (edge[i].to!=pre)
		{
			dist[edge[i].to]=dist[u]+edge[i].dis;
			dfs(edge[i].to,u,dep+1);
		}
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
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		add(a,b,dis); add(b,a,dis);
	}
	t=int(log(double(n))/log(2.0))+1;
	dfs(1,0,0);
	init();
	for (int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",dist[a]+dist[b]-dist[lca(a,b)]*2);
	}
}
//DHOJ http://47.104.154.247/problem.php?cid=1136&pid=2
