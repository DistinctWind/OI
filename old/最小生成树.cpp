#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=5010;
const int MAXM=200010;
int n,m,cnt;
int cntEdge,head[MAXN],nxt[MAXM<<1],ver[MAXM<<1];
int fa[MAXN];
int ans;
bool vis[MAXN];
struct Edge{
	int a,b,dis;
}edge[MAXM];
bool cmp(Edge a,Edge b)
{
	return a.dis<b.dis;
}
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
void dfs(int x)
{
	vis[x]=true;
	cnt++;
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (vis[y]) continue;
		dfs(y);
	}
}
inline void setup()
{
	for (int i=1;i<=n;i++)
		fa[i]=i;
}
int find(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline void merge(int x,int y)
{
	int f1=find(x);
	int f2=find(y);
	if (f1!=f2) fa[f1]=f2;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y); add(y,x);
		edge[i].a=x,edge[i].b=y,edge[i].dis=z;
	}
	dfs(1);
	if (cnt<n)
	{
		printf("orz\n");
		return 0;
	}
	setup();
	sort(edge+1,edge+1+m,cmp);
	for (int i=1;i<=m;i++)
	{
		if (find(edge[i].a)!=find(edge[i].b))
		{
			merge(edge[i].a,edge[i].b);
			ans+=edge[i].dis;
		}
	}
	printf("%d",ans);
}
