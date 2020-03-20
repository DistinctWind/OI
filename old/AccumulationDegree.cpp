#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=300010;
int t,n,deg[MAXN],dr[MAXN],f[MAXN],ans;
int cntEdge,head[MAXN],ver[MAXN<<1],nxt[MAXN<<1],dis[MAXN<<1];
inline void setup()
{
	cntEdge=ans=0;
	memset(head,0,sizeof(head));
	memset(ver,0,sizeof(ver));
	memset(nxt,0,sizeof(nxt));
	memset(dis,0,sizeof(dis));
	memset(deg,0,sizeof(deg));
	memset(dr,0,sizeof(dr));
	memset(f,0,sizeof(f));
}
inline void add(int from,int to,int d)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
	dis[cntEdge]=d;
}
void dfs1(int x,int fa)
{
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (y==fa) continue;
		dfs1(y,x);
		if (deg[y]>1) dr[x]+=min(dr[y],dis[i]);
		else dr[x]+=dis[i];
	}
}
void dfs2(int x,int fa)
{
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (y==fa) continue;
		if (deg[x]==1) f[y]=dr[y]+dis[i];
		else f[y]=dr[y]+min(f[x]-min(dr[y],dis[i]),dis[i]);
		dfs2(y,x);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while (t--)
	{
		setup();
		scanf("%d",&n);
		for (int i=1,u,v,d;i<n;i++)
		{
			scanf("%d%d%d",&u,&v,&d);
			add(u,v,d); add(v,u,d);
			deg[u]++,deg[v]++;
		}
		dfs1(1,0);
		f[1]=dr[1];
		dfs2(1,0);
		for (int i=1;i<=n;i++)
			ans=max(ans,f[i]);
		printf("%d\n",ans);
	}
}
