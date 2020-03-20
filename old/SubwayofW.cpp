#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=1010;
const int MAXM=100010;
int n,m,ea[MAXM],eb[MAXM];
int ce,head[MAXN],ver[MAXM],nxt[MAXM];
int dis[MAXN];
bool vis[MAXN];
inline void add(int from,int to)
{
	ce++;
	nxt[ce]=head[from];
	head[from]=ce;
	ver[ce]=to;
}
inline int bfs(int s,int t)
{
	memset(vis,0,sizeof(vis));
	queue <int> q;
	dis[s]=0; vis[s]=true;
	for (int i=head[s],v;i;i=nxt[i])
	{
		v=ver[i];
		if (v==t) continue;
		dis[v]=1; vis[v]=true;
		q.push(v);
	}
	while (!q.empty())
	{
		int h=q.front(); q.pop();
		for (int i=head[h],v;i;i=nxt[i])
		{
			v=ver[i];
			if (vis[v]) continue;
			dis[v]=dis[h]+1; vis[v]=true;
			if (v==t) return dis[v];
			q.push(v);
		}
	}
	return -1;
}
int read()
{
	int x=0;
	char a=getchar();
	while (a<'0'||a>'9') a=getchar();
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
	n=read(); m=read();
	for (int i=1;i<=m;i++)
	{
		ea[i]=read(); eb[i]=read();
		add(ea[i],eb[i]);
	}
	for (int i=1,ans;i<=m;i++)
	{
		ans=bfs(ea[i],eb[i]);
		printf("%d",ans);
		
		if (i!=m) putchar(' ');
	}
}
