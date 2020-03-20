#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN=2010;
const int MAXM=3010;
int T,n,m;
int cntEdge,head[MAXN],ver[MAXM<<1],nxt[MAXM<<1],dis[MAXM<<1];
int distan[MAXN],cnt[MAXN];
bool vis[MAXN];
inline void setup()
{
	cntEdge=0;
	memset(head,0,sizeof(head));
	memset(ver,0,sizeof(ver));
	memset(nxt,0,sizeof(nxt));
	memset(dis,0,sizeof(dis));
}
inline void add(int from,int to,int dist)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
	dis[cntEdge]=dist;
}
bool spfa()
{
	memset(distan,0x3f,sizeof(distan));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	queue<int> q;
	q.push(1); vis[1]=true;
	distan[1]=0;
	while (!q.empty())
	{
		int x=q.front(); q.pop(); vis[x]=false;
		for (int i=head[x],y;i;i=nxt[i])
		{
			y=ver[i];
			if (distan[y]>distan[x]+dis[i])
			{
				cnt[y]++;
				if (cnt[y]>=n)
					return false;
				distan[y]=distan[x]+dis[i];
				if (!vis[y])
				{
					vis[y]=true;
					q.push(y);
				}
			}
		}
	}
	return true;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&T);
	while (T--)
	{
		setup();
		scanf("%d%d",&n,&m);
		for (int i=1,a,b,w;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&w);
			add(a,b,w);
			if (w>=0) add(b,a,w);
		}
		if (spfa()) printf("N0\n");
		else printf("YE5\n");
	}
}
