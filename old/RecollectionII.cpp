#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=20010;
const int MAXM=100010;
int n,m;
int cntEdge,head[MAXN],nxt[MAXM<<1],ver[MAXM<<1];
int root,cnt,dfn[MAXN],low[MAXN];
bool mk[MAXN];
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
void tarjan(int x)
{
	cnt++;
	dfn[x]=low[x]=cnt;
	int cntSon=0;
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (!dfn[y])
		{
			cntSon++;
			tarjan(y);
			low[x]=min(low[x],low[y]);
			if (x==root&&cntSon>=2)
				mk[x]=true;
			if (x!=root&&low[y]>=dfn[x])
				mk[x]=true;
		}
		else
			low[x]=min(low[x],dfn[y]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i])
			root=i,tarjan(i);
	int tot=0;
	for (int i=1;i<=n;i++)
		if (mk[i])
			tot++;
	printf("%d\n",tot);
	for (int i=1;i<=n;i++)
		if (mk[i])
			printf("%d ",i);
}
