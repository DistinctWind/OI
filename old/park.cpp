#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=100010;
const int MAXM=200010;
int t,n,m,k,p,ans;
bool vis[MAXN];
int cntEdge,head[MAXN],nxt[MAXM<<1],ver[MAXM<<1],dis[MAXM<<1],dst[MAXN];
inline void add(int from,int to,int d)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
	dis[cntEdge]=d;
}
inline void setup()
{
	memset(head,0,sizeof(head));
	memset(nxt,0,sizeof(nxt));
	memset(ver,0,sizeof(ver));
	memset(dis,0,sizeof(dis));
	cntEdge=0; ans=0;
}
inline void spfa()
{
	memset(dst,0x3f,sizeof(dst));
	memset(vis,0,sizeof(vis));
	dst[1]=0;
	queue <int> q;
	q.push(1); vis[1]=true;
	while (!q.empty())
	{
		int x=q.front(); q.pop(); vis[x]=false;
		for (int i=head[x],y;i;i=nxt[i])
		{
			y=ver[i];
			if (dst[y]>dst[x]+dis[i])
			{
				dst[y]=dst[x]+dis[i];
				if (!vis[y])
				{
					vis[y]=true;
					q.push(y);
				}
			}
		}
	}
}
void dfs(int x,int step)
{
	if (step+dst[x]>dst[n]+k) return;
	if (x==1)
	{
		ans=(ans+1)%p;
		return;
	}
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (vis[y]) continue;
		vis[y]=true;
		dfs(y,step+dis[i]);
		vis[y]=false;
	}
}
int main()
{
	freopen("park.in","r",stdin);
	freopen("park.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		setup();
		scanf("%d%d%d%d",&n,&m,&k,&p);
		for (int i=1,u,v,d;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&d);
			add(u,v,d); add(v,u,d);
		}
		spfa();
		memset(vis,0,sizeof(vis));
		vis[n]=true;
		dfs(n,0);
		printf("%d\n",ans);
	}
}
