#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=110;
int n;
int son[MAXN][2],val[MAXN];
int f[MAXN],size[MAXN];
void dfs1(int x,int depth)
{
	f[1]+=val[x]*depth;
	size[x]=val[x];
	for (int i=0,y;i<=1;i++)
	{
		y=son[x][i];
		if (y==0) continue;
		dfs1(y,depth+1);
		size[x]+=size[y];
	}
}
void dfs2(int x)
{
	for (int i=0,y;i<=1;i++)
	{
		y=son[x][i];
		if (y==0) continue;
		f[y]=f[x]+size[1]-size[y]*2;
		dfs2(y);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&val[i],&son[i][0],&son[i][1]);
	dfs1(1,0);
	dfs2(1);
	int ans=0x3f3f3f3f;
	for (int i=1;i<=n;i++)
		ans=min(ans,f[i]);
	printf("%d",ans);
}
