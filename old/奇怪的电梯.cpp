#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=210;
int n,s,t;
int dis[MAXN];
int cntEdge,head[MAXN],nxt[MAXN<<1],ver[MAXN<<1];
bool vis[MAXN];
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
inline void spfa()
{
	queue<int> q;
	q.push(s);
	vis[s]=true;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	while (!q.empty())
	{
		int x=q.front(); q.pop(); vis[x]=false;
		for (int i=head[x],y;i;i=nxt[i])
		{
			y=ver[i];
			if (dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				if (!vis[y])
				{
					vis[y]=true;
					q.push(y);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&s,&t);
	for (int i=1,k;i<=n;i++)
	{
		scanf("%d",&k);
		if (i-k>=1) add(i,i-k);
		if (i+k<=n) add(i,i+k);
	}
	spfa();
	if (dis[t]==0x3f3f3f3f) printf("-1");
	else printf("%d",dis[t]);
}
