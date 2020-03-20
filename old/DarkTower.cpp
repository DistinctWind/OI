#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN=1001;
const int MAXM=500010;
const long long mod=0x7fffffff;
int n,m,d[MAXN][MAXN];
int dist[MAXN];
long long ans=1;
bool vis[MAXN];
struct Node{
	int pos,dis;
}node[MAXN];
bool operator < (const Node &a,const Node &b)
{
	return a.dis>b.dis;
}
bool cmp(Node a,Node b)
{
	return a.dis<b.dis;
}
inline void dijkstra()
{
	memset(dist,0x3f,sizeof(dist));
	priority_queue <Node> q;
	dist[1]=0;
	q.push(Node{1,0});
	while (!q.empty())
	{
		int h=q.top().pos; q.pop();
		if (vis[h]) continue;
		vis[h]=true;
		for (int i=1;i<=n;i++)
		{
			if (dist[i]>dist[h]+d[i][h])
			{
				dist[i]=dist[h]+d[i][h];
				q.push(Node{i,dist[i]});
			}
		}
	}
}
inline void solve()
{
	sort(node+1,node+1+n,cmp);
	memset(vis,0,sizeof(vis));
	int c=0;
	for (int i=2;i<=n;i++)
	{
		//if (c==n-1) break;
		long long res=0;
		for (int j=1;j<i;j++)
		{
			if (node[i].dis==node[j].dis+d[node[i].pos][node[j].pos])
				res++;
		}
		if (res==0) continue;
		//c++;
		ans=(ans*res)%mod;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	memset(d,0x3f,sizeof(d));
	for (int i=1;i<=m;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		d[a][b]=d[b][a]=dis;
	}
	dijkstra();
	for (int i=1;i<=n;i++)
		node[i]=Node{i,dist[i]};
	solve();
	printf("%lld\n",ans%mod);
}
