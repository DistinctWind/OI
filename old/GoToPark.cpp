#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=100010;
const int MAXM=200010;
const int MAXK=51;
int t,n,m,k,mod,d[MAXN],f[MAXN][MAXK];
int cntEdge,head[MAXN],nxt[MAXM],ver[MAXM],dis[MAXM];
int rcntEdge,rhead[MAXN],rnxt[MAXM],rver[MAXM],rdis[MAXM];
bool vis[MAXN],fail,is[MAXN][MAXK];
int read()
{
	int x=0; char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
inline void setup()
{
	fail=false;
	memset(f,0,sizeof(f));
	memset(is,0,sizeof(is));
	memset(head,0,sizeof(head));
	memset(nxt,0,sizeof(nxt));
	memset(ver,0,sizeof(ver));
	memset(dis,0,sizeof(dis));
	memset(rhead,0,sizeof(rhead));
	memset(rnxt,0,sizeof(rnxt));
	memset(rver,0,sizeof(rver));
	memset(rdis,0,sizeof(rdis));
}
inline void add(int from,int to,int dist)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
	dis[cntEdge]=dist;
}
inline void radd(int from,int to,int dist)
{
	rcntEdge++;
	rnxt[cntEdge]=rhead[from];
	rhead[from]=rcntEdge;
	rver[cntEdge]=to;
	rdis[cntEdge]=dist;
}
inline void spfa()
{
	memset(d,0x3f,sizeof(d));
	d[1]=0;
	queue <int> q;
	q.push(1);
	while (!q.empty())
	{
		int x=q.front(); q.pop(); vis[x]=false;
		for (int i=head[x],y;i;i=nxt[i])
		{
			y=ver[i];
			if (d[y]>d[x]+dis[i])
			{
				d[y]=d[x]+dis[i];
				if (!vis[y])
				{
					vis[y]=true;
					q.push(y);
				}
			}
		}
	}
}
int dp(int u,int p)
{
	if (p<0) return 0;
	if (is[u][p])
	{
		fail=true;
		return 0;
	}
	if (f[u][p]) return f[u][p];
	is[u][p]=true;
	int ans=0;
	for (int i=rhead[u],v;i;i=rnxt[i])
	{
		v=rver[i];
		ans=(ans+dp(v,d[u]-d[v]+p-rdis[i]))%mod;
		if (fail) return 0;
	}
	is[u][p]=false;
	return f[u][p]=ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	t=read();
	while (t--)
	{
		setup();
		n=read(); m=read(); k=read(); mod=read();
		for (int i=1,x,y,d;i<=m;i++)
		{
			x=read(); y=read(); d=read();
			add(x,y,d); radd(y,x,d);
		}
		spfa();
		dp(1,0);
		f[1][0]=1;
		int ans=0;
		for (int i=0;i<=k;i++)
			ans=(ans+dp(n,i))%mod;
		if (fail) printf("-1\n");
		else printf("%d\n",ans);
	}
}
