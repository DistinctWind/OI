#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=1e5+10;
const int MAXM=5e5+10;
int n,m,s;
int cntEdge,head[MAXN],nxt[MAXM<<1],ver[MAXM<<1],dis[MAXM<<1];
int dist[MAXN];
bool vis[MAXN];
struct State{
	int pos,val;
};
bool operator < (State a,State b)
{
	return a.val>b.val;
}
inline void add(int from,int to,int d)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
	dis[cntEdge]=d;
}
inline int read()
{
	int x=0,k=1; char a=getchar();
	while (a<'0'||a>'9') {if (a=='-') k=-1; a=getchar();}
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return k*x;
}
inline void spfa()
{
	queue <int> q;
	memset(dist,0xef,sizeof(dist));
	dist[s]=0; vis[s]=true;
	q.push(s);
	while (!q.empty())
	{
		int x=q.front(); q.pop(); vis[x]=false;
		for (int i=head[x],y;i;i=nxt[i])
		{
			y=ver[i];
			if (dist[y]>dist[x]+dis[i])
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
void dijstra()
{
	priority_queue <State> q;
	q.push(State{s,0});
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	/*for (int i=1;i<n;i++)
	{
		pair<int,int> h=q.top();
		while (!q.empty()&&vis[h.second]) q.pop(),h=q.top();
		int x=h.second;
		vis[x]=true;
		for (int i=head[x],y;i;i=nxt[i])
		{
			y=ver[i];
			dist[y]=min(dist[y],dist[x]+dis[i]);
		}
	}*/
	while (!q.empty())
	{
		State h=q.top();
		q.pop();
		if (vis[h.pos]) continue;
		int x=h.pos;
		vis[x]=true;
		for (int i=head[x],y;i;i=nxt[i])
		{
			y=ver[i];
			if (dist[y]>dist[x]+dis[i])
			{
				dist[y]=dist[x]+dis[i];
				q.push(State{y,dist[y]});
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read(); m=read(); s=read();
	for (int i=1,x,y,z;i<=m;i++)
	{
		x=read(); y=read(); z=read();
		add(x,y,z);
	}
	dijstra();
	for (int i=1;i<=n;i++)
	{
		if (dist[i]==0x3f3f3f3f) printf("%d ",0x7fffffff);
		else printf("%d ",dist[i]);
	}
}
