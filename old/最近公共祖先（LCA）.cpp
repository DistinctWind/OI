#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=500010;
const int MAXM=500010;
const int LOGN=21;
int n,m,s;
int cntEdge,head[MAXN],nxt[MAXN<<1],ver[MAXN<<1];
int f[MAXN][LOGN],dep[MAXN];
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
void dfs(int x,int fa,int depth)
{
	f[x][0]=fa;
	dep[x]=depth;
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (y==fa) continue;
		dfs(y,x,depth+1);
	}
}
inline void init()
{
	for (int j=1;j<LOGN;j++)
		for (int i=1;i<=n;i++)
			if (f[i][j-1]!=0)
				f[i][j]=f[f[i][j-1]][j-1];
}
int read()
{
	int x=0; char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
int lca(int a,int b)
{
	if (dep[a]>dep[b]) swap(a,b);
	for (int i=LOGN-1;i>=0;i--)
		if (dep[a]<=dep[f[b][i]])
			b=f[b][i];
	if (a==b) return a;
	for (int i=LOGN-1;i>=0;i--)
		if (f[a][i]!=f[b][i])
			a=f[a][i],b=f[b][i];
	return f[a][0];
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read(); m=read(); s=read();
	for (int i=1,x,y;i<n;i++)
	{
		x=read(); y=read();
		add(x,y); add(y,x);
	}
	dfs(s,0,1);
	init();
	for (int i=1,a,b;i<=m;i++)
	{
		a=read(); b=read();
		printf("%d\n",lca(a,b));
	}
}
