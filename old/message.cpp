#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=200010;
int n;
int linked[MAXN];
int d[MAXN],res[MAXN];
bool vis[MAXN];
int ans=0x7fffffff;
inline void add(int from,int to)
{
	linked[from]=to;
}
void dfs(int u,int depth)
{
	d[u]=depth;
	vis[u]=true;
	int v=linked[u];
	if (res[v]!=-1)
	{
		res[u]=res[v];
		return;
	}
	if (vis[v]) ans=min(ans,d[u]-d[v]+1);
	else dfs(v,depth+1);
	d[u]=0;
	vis[u]=false;
	res[u]=ans;
}
int main()
{
	//freopen("message.in","r",stdin);
	//freopen("message.out","w",stdout);
	scanf("%d",&n);
	for (int i=1,c;i<=n;i++)
	{
		scanf("%d",&c);
		add(i,c);
	}
	memset(res,0xff,sizeof(res));
	for (int i=1;i<=n;i++)
		if (res[i]==-1)
			dfs(i,1);
	printf("%d",ans);
}
