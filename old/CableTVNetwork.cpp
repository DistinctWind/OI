#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
const int MAXN=10010;
const int MAXM=10010;
const int inf=0x3f3f3f3f;
int n,m,a[MAXM],b[MAXM];
int s,t,ans,d[MAXN];
int cnt_edge,head[MAXN];
struct Edge{
	int nxt,to,dis;
}edge[MAXM<<1];
int min(int a,int b)
{
	return a<b?a:b;
}
int read()
{
	int x=0;
	char a=getchar();
	while (a<'0'||'9'<a) a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
inline void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
	
	cnt_edge++;
	edge[cnt_edge].nxt=head[to];
	head[to]=cnt_edge;
	edge[cnt_edge].to=from;
	edge[cnt_edge].dis=0;
}
bool bfs()
{
	queue <int> q;
	q.push(s);
	memset(d,0,sizeof(d));
	d[s]=1;
	while (!q.empty())
	{
		int h=q.front(); q.pop();
		for (int i=head[h];i;i=edge[i].nxt)
			if (edge[i].dis&&!d[edge[i].to])
			{
				q.push(edge[i].to);
				d[edge[i].to]=d[h]+1;
				if (edge[i].to==t) return true;
			}
	}
	return false;
}
int dinic(int x,int flow)
{
	if (x==t) return flow;
	int rest=flow,k;
	for (int i=head[x];i&&rest;i=edge[i].nxt)
	{
		if (edge[i].dis&&d[edge[i].to]==d[x]+1)
		{
			k=dinic(edge[i].to,min(rest,edge[i].dis));
			if (!k) d[edge[i].to]=0;
			edge[i].dis-=k;
			edge[i^1].dis+=k;
			rest-=k;
		}
	}
	return flow-rest;
}
inline void solve()
{
	ans=inf;
	for (s=0;s<n;s++)
		for (t=0;t<n;t++)
			if (s!=t)
			{
				memset(head,0,sizeof(head));
				memset(edge,0,sizeof(edge));
				cnt_edge=1;
				for (int i=0;i<n;i++)
					if (i!=s&&i!=t) add(i,i+n,1);
					else add(i,i+n,inf);
				for (int i=1;i<=m;i++)
				{
					add(a[i]+n,b[i],inf);
					add(b[i]+n,a[i],inf);
				}
				int nowans=0;
				while (bfs())
				{
					int tmp;
					while (tmp=dinic(s,inf)) nowans+=tmp;
				}
				ans=min(ans,nowans);
			}
	if (n<=1||ans==inf)
	{
		printf("%d\n",n);
		return;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		for (int i=1;i<=m;i++)
		{
			a[i]=read(); b[i]=read();
		}
		solve();
	}
}
