#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXM=100010;
const int MAXN=100010;
const int LOGN=18;
struct Edge{
	int nxt,to;
}edge[MAXM*2];
struct Node{
	int ls,rs,pos,dat;
	Node(){
		ls=rs=pos=dat=0;
	}
}node[MAXN*50];
int n,m,t,cnt_edge,head[MAXN],depth[MAXN],f[MAXN][LOGN];
int x[MAXN],y[MAXN],z[MAXN],val[MAXN],d;
int ans[MAXN],root[MAXN];
bool vis[MAXN];
int num;
int max(int a,int b)
{
	return a>b?a:b;
}
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
		if (edge[i].to!=pre)
			dfs(edge[i].to,u,dep+1);
}
inline void init()
{
	for (int j=0;1<<(j+1)<n;j++)
		for (int i=1;i<=n;i++)
			if (f[i][j]==0) f[i][j+1]=0;
			else f[i][j+1]=f[f[i][j]][j];
}
inline void discrete()
{
	sort(val+1,val+1+m);
	d=unique(val+1,val+1+m)-val-1;
}
int query(int x)
{
	return lower_bound(val+1,val+1+d,x)-val;
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
void insert(int k,int l,int r,int x,int v)
{
	if (l==r)
	{
		node[k].dat+=v;
		node[k].pos=node[k].dat?l:0;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid)
	{
		if (!node[k].ls) node[k].ls=++num;
		insert(node[k].ls,l,mid,x,v);
	}
	else
	{
		if (!node[k].rs) node[k].rs=++num;
		insert(node[k].rs,mid+1,r,x,v);
	}
	node[k].dat=max(node[node[k].ls].dat,node[node[k].rs].dat);
	node[k].pos=node[node[k].ls].dat>=node[node[k].rs].dat?node[node[k].ls].pos:node[node[k].rs].pos;
}
int merge(int p,int q,int l,int r)
{
	if (!p) return q;
	if (!q) return p;
	if (l==r)
	{
		node[p].dat+=node[q].dat;
		node[p].pos=node[p].dat?l:0;
		return p;
	}
	int mid=l+r>>1;
	node[p].ls=merge(node[p].ls,node[q].ls,l,mid);
	node[p].rs=merge(node[p].rs,node[q].rs,mid+1,r);
	node[p].dat=max(node[node[p].ls].dat,node[node[p].rs].dat);
	node[p].pos=node[node[p].ls].dat>=node[node[p].rs].dat?node[node[p].ls].pos:node[node[p].rs].pos;
	return p;
}
void sdfs(int pos)
{
	for (int i=head[pos];i;i=edge[i].nxt)
	{
		if (depth[edge[i].to]<=depth[pos]) continue;
		sdfs(edge[i].to);
		root[pos]=merge(root[pos],root[edge[i].to],1,d);
	}
	ans[pos]=node[root[pos]].pos;
}
int read()
{
	int x=0;
	char a=getchar();
	while (a<'0'||a>'9')
	{
		a=getchar();
	}
	while ('0'<=a&&a<='9')
	{
		x=x*10+a-'0';
		a=getchar();
	}
	return x;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	//scanf("%d%d",&n,&m);
	n=read(); m=read();
	for (int i=1;i<n;i++)
	{
		int a,b;
		//scanf("%d%d",&a,&b);
		a=read(); b=read();
		add(a,b); add(b,a);
	}
	for (int i=1;i<=m;i++)
	{
		//scanf("%d%d%d",&x[i],&y[i],&z[i]);
		x[i]=read(); y[i]=read(); z[i]=read();
		val[i]=z[i];
	}
	t=int(log(double(n))/log(2.0))+1;
	dfs(1,0,1);
	init();
	discrete();
	for (int i=1;i<=n;i++)
		root[i]=++num;
	for (int i=1;i<=m;i++)
	{
		int X=x[i],Y=y[i],Z=query(z[i]);
		int p=lca(X,Y);
		insert(root[X],1,d,Z,1);
		insert(root[Y],1,d,Z,1);
		insert(root[p],1,d,Z,-1);
		if (f[p][0]) insert(root[f[p][0]],1,d,Z,-1);
	}
	sdfs(1);
	for (int i=1;i<=n;i++)
		printf("%d\n",val[ans[i]]);
}
