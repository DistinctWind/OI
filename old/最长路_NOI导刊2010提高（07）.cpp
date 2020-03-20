#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=1510;
const int MAXM=50010;
int n,m,dist[MAXN];
int cntEdge,head[MAXN],nxt[MAXM],ver[MAXM],dis[MAXM];
bool vis[MAXN];
struct State{
	int x,d;
}start;
bool operator < (State a,State b)
{
	return a.d<b.d;
}
inline void add(int from,int to,int d)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
	dis[cntEdge]=d;
}
inline void fspfa()
{
	memset(dist,0xff,sizeof(dist));
	queue <int> q;
	dist[1]=0;
	q.push(1); vis[1]=true;
	while (!q.empty())
	{
		int x=q.front(); q.pop(); vis[x]=false;
		for (int i=head[x],y;i;i=nxt[i])
		{
			y=ver[i];
			if (dist[y]<dist[x]+dis[i])
			{
				dist[y]=dist[x]+dis[i];
				if (!vis[y])
				{
					vis[y]=true;
					q.push(y);
				}
			}
		}
	}
}
inline void dijstra()
{
	priority_queue <State> q;
	start.x=1,start.d=0;
	memset(dist,0xff,sizeof(dist));
	dist[1]=0;
	q.push(start);
	while (!q.empty())
	{
		State h=q.top(); q.pop();
		//if (vis[h.x]) continue;
		vis[h.x]=true;
		for (int i=head[h.x],y;i;i=nxt[i])
		{
			y=ver[i];
			if (dist[y]<dist[h.x]+dis[i])
			{
				dist[y]=dist[h.x]+dis[i];
				q.push(State{y,dist[y]});
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1,a,b,d;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&d);
		add(a,b,d);
	}
	//fspfa();
	dijstra();
	printf("%d",dist[n]);
}
