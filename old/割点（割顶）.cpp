#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=20010;
const int MAXM=100010;
int n,m,root;
int cntEdge,head[MAXN],nxt[MAXM<<1],ver[MAXM<<1];
int dfn[MAXN],low[MAXN],cnt;
bool vis[MAXN],flag[MAXN];
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
void dfs(int x)
{
	cnt++;
	dfn[x]=low[x]=cnt;
	vis[x]=true;
	int cntSon=0;
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (!vis[y])
		{
			dfs(y);
			cntSon++;
			low[x]=min(low[x],low[y]);
			if (x==root&&cntSon>=2)
				flag[x]=true;
			else if (x!=root&&low[y]>=dfn[x])
				flag[x]=true;
		}
		else if (x!=y)
		{
			low[x]=min(low[x],dfn[y]);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i])
			root=i,dfs(i);
	int tot=0;
	for (int i=1;i<=n;i++)
		if (flag[i])
			tot++;
	printf("%d\n",tot);
	for (int i=1;i<=n;i++)
		if (flag[i])
			printf("%d ",i);
}
