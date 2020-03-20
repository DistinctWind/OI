#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN=10010;
const int MAXM=50010;
const int LOGN=20;
const int inf=0x3f3f3f3f;
struct Edge{
	int nxt,to,dis;
}edge[MAXM<<1];
struct fEdge{
	int a,b,dis;
}fedge[MAXM];
int cnt_edge,head[MAXN];
int n,m,q;
int fa[MAXN],f[MAXN][LOGN],w[MAXN][LOGN],depth[MAXN];
bool vis[MAXN];
bool cmp(fEdge a,fEdge b)
{
	return a.dis>b.dis;
}
inline void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
int find(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline void kruskal()
{
	for (int i=1;i<=m;i++)
	{
		int a=fedge[i].a;
		int b=fedge[i].b;
		if (find(a)!=find(b))
		{
			fa[find(a)]=find(b);
			add(a,b,fedge[i].dis);
			add(b,a,fedge[i].dis);
		}
	}
}
void dfs(int x,int d)
{
	depth[x]=d;
	for (int i=head[x];i;i=edge[i].nxt)
	{
		int y=edge[i].to;
		if (vis[y]) continue;
		vis[y]=true;
		f[y][0]=x; w[y][0]=edge[i].dis;
		dfs(y);
	}
}
long long lca(int a,int b)
{
	long long res=inf;
	if (depth[a]>depth[b]) swap(a,b);
	for (int i=LOGN-1;i>=0;i--)
		if (depth[f[b][i]]>=depth[a])
			b=f[b][i],res=min(res,w[b][i]);
	if (a==b) return res;
	for (int i=LOGN-1;i>=0;i--)
		if (f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i],res=min(res,min(w[a][i],w[b][i]));
	return min(res,)
}
inline void setup()
{
	for (int i=1;i<=n;i++) fa[i]=i;
	kruskal();
	for (int i=1;i<=n;i++)
	{
		if (vis[i]) continue;
		dfs(i,1);
		f[i][0]=i; w[i][0]=inf;
	}
	for (int i=1;i<LOGN;i++)
	{
		for (int j=1;j<=n;j++)
		{
			f[j][i]=f[f[j][i-1]][i-1];
			w[j][i]=min(w[f[j][i-1]][i-1],w[j][i-1]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&fedge[i].a,&fedge[i].b,&fedge[i].dis);
	sort(fedge+1,fedge+1+m,cmp);
	setup();
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%lld\n",lca(a,b));
	}
}
/* Mid-2 TLE 20
#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=10010;
const int MAXM=50010;
struct Edge{
	int nxt,to,dis;
}edge[MAXM<<1];
int cnt_edge,head[MAXN];
int n,m,q,sr;
bool vis[MAXN];
inline void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
bool check(int a,int b,int w)
{
	memset(vis,0,sizeof(vis));
	queue <int> q;
	q.push(a); vis[a]=true;
	while (!q.empty())
	{
		int h=q.front(); q.pop();
		if (h==b) return true;
		for (int i=head[h];i;i=edge[i].nxt)
		{
			if (w<=edge[i].dis&&!vis[edge[i].to])
			{
				vis[edge[i].to]=true;
				q.push(edge[i].to);
			}
		}
	}
	return false;
}
inline void solve(int a,int b)
{
	int l=0,r=sr,ans=-1;
	while (l<=r)
	{
		int mid=l+r>>1;
		if (check(a,b,mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
}
int main()
{
	//freopen("truck.in","r",stdin);
	//freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		add(a,b,dis); add(b,a,dis);
		sr=max(sr,dis);
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		solve(a,b);
	}
}
*/
