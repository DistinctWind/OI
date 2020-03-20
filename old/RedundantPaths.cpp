#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;
const int MAXF=5010;
const int MAXR=10010;
int f,r;
int head[MAXF],cnt_edge=1;
int dfn[MAXF],low[MAXF],t,b[MAXF],cnt_block;
int cnt[MAXF];
bool is[MAXF];
stack <int> s;
struct Edge{
	int from,nxt,to;
	bool able;
}edge[MAXR<<1];
inline void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].from=from;
	edge[cnt_edge].to=to;
	edge[cnt_edge].able=true;
}
void tarjan(int x,int pre)
{
	dfn[x]=low[x]=++t;
	is[x]=true;
	s.push(x);
	for (int i=head[x];i;i=edge[i].nxt)
	{
		if (edge[i].able==false) continue;
		if (!dfn[edge[i].to])
		{
			tarjan(edge[i].to,x);
			if (low[edge[i].to]<low[x])
				low[x]=low[edge[i].to];
			if (dfn[x]<low[edge[i].to]) edge[i].able=edge[i^1].able=false;
		}
		else if (edge[i].to!=pre)
			if (dfn[edge[i].to]<low[x])
				low[x]=dfn[edge[i].to];
	}
}
void dfs(int x)
{
	b[x]=cnt_block;
	for (int i=head[x];i;i=edge[i].nxt)
	{
		if (b[edge[i].to]) continue;
		if (edge[i].able)
			dfs(edge[i].to);
	}
}
inline void solve()
{
	tarjan(1,0);
	for (int i=1;i<=f;i++)
		if (!b[i])
		{
			cnt_block++;
			dfs(i);
		}
	int res=0;
	for (int i=2;i<=cnt_edge;i+=2)
	{
		if (b[edge[i].from]!=b[edge[i].to])
			cnt[b[edge[i].from]]++,cnt[b[edge[i].to]]++;
	}
	for (int i=1;i<=cnt_block;i++)
		if (cnt[i]==1)
			res++;
	printf("%d",res+1>>1);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&f,&r);
	for (int i=1;i<=r;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b); add(b,a);
	}
	solve();
}
