#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
const int MAXN=1e4+10;
const int MAXM=1e5+10;
int n,m,val[MAXN];
int cntEdge,head[MAXN],nxt[MAXM],ver[MAXM],frm[MAXM];
int bcntEdge,bhead[MAXN],bnxt[MAXM],bver[MAXM];
int cntBlock,block[MAXN],bval[MAXN],deg[MAXN],dis[MAXN];
int cnt,dfn[MAXN],low[MAXN];
bool vis[MAXN];
stack<int> s;
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	frm[cntEdge]=from;
	ver[cntEdge]=to;
}
inline void badd(int from,int to)
{
	bcntEdge++;
	bnxt[bcntEdge]=bhead[from];
	bhead[from]=bcntEdge;
	bver[bcntEdge]=to;
}
void tarjan(int x)
{
	cnt++;
	dfn[x]=low[x]=cnt;
	vis[x]=true;
	s.push(x);
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if (vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if (dfn[x]==low[x])
	{
		cntBlock++;
		do
		{
			vis[s.top()]=false;
			block[s.top()]=cntBlock;
			bval[cntBlock]+=val[s.top()];
			s.pop();
		}
		while (!s.empty()&&vis[x]);
	}
}
void topsort()
{
	queue<int> q;
	for (int i=1;i<=cntBlock;i++)
		if (!deg[i])
			q.push(i);
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		dis[x]+=bval[x];
		for (int i=bhead[x],y;i;i=bnxt[i])
		{
			y=bver[i];
			dis[y]=max(dis[y],dis[x]);
			deg[y]--;
			if (deg[y]==0)
				q.push(y);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for (int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i])
			tarjan(i);
	for (int i=1;i<=m;i++)
	{
		int x=block[frm[i]],y=block[ver[i]];
		if (x==y) continue;
		badd(x,y);
		deg[y]++;
	}
	topsort();
	int ans=0;
	for (int i=1;i<=cntBlock;i++)
		if (dis[i]>ans)
			ans=dis[i];
	printf("%d",ans);
}
