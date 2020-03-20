#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=50010;
const int MAXM=50010;
int n,m;
int cntEdge,head[MAXN],nxt[MAXM<<1],ver[MAXM<<1],dis[MAXM<<1];
int read()
{
	int x=0; char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
inline void add(int from,int to,int dist)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
	dis[cntEdge]=dist;
}
int s,maxv;
bool vis[MAXN];
struct State{
	int pos,len;
}start;
inline void fbfs()
{
	maxv=-1;
	queue <State> q;
	start.pos=1,start.len=0;
	q.push(start); vis[1]=true;
	while (!q.empty())
	{
		State h=q.front(); q.pop();
		int x=h.pos;
		for (int i=head[x],y;i;i=nxt[i])
		{
			y=ver[i];
			if (vis[y]) continue;
			vis[y]=true;
			State tmp;
			tmp.pos=y,tmp.len=h.len+dis[i];
			if (tmp.len>maxv) maxv=tmp.len,s=y;
			q.push(tmp);
		}
	}
}
inline void sbfs()
{
	maxv=-1; memset(vis,0,sizeof(vis));
	queue <State> q;
	start.pos=s,start.len=0;
	q.push(start); vis[s]=true;
	while (!q.empty())
	{
		State h=q.front(); q.pop();
		int x=h.pos;
		for (int i=head[x],y;i;i=nxt[i])
		{
			y=ver[i];
			if (vis[y]) continue;
			vis[y]=true;
			State tmp;
			tmp.pos=y,tmp.len=h.len+dis[i];
			if (tmp.len>maxv) maxv=tmp.len,s=y;
			q.push(tmp);
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(); m=read();
	for (int i=1,x,y,dist;i<n;i++)
	{
		x=read(); y=read(); dist=read();
		add(x,y,dist); add(y,x,dist);
	}
	fbfs();
	sbfs();
	if (m==1) printf("%d",maxv);
	else printf("%d",maxv/m+1);
}
