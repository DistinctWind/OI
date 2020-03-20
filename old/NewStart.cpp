#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=302;
int n;
int d[MAXN];
int a[MAXN][MAXN];
bool vis[MAXN];
int min(int a,int b)
{
	return a<b?a:b;
}
int max(int a,int b)
{
	return a>b?a:b;
}
inline void prim()
{
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	//for (int i=1;i<n;i++)
	//	d[i]=a[n][i];
	//a[n][n]=0x3f3f3f3f;
	d[n]=0;
	for (int i=1;i<n;i++)
	{
		int x=0;
		for (int j=1;j<=n;j++)
			if (!vis[j]&&(x==0||d[j]<d[x])) x=j;
		vis[x]=true;
		for (int y=1;y<=n;y++)
			if (!vis[y])
				d[y]=min(d[y],a[x][y]);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	n++;
	for (int i=1;i<n;i++)
	{
		scanf("%d",&a[i][n]);
		a[n][i]=a[i][n];
	}
	for (int i=1;i<n;i++)
		for (int j=1;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			a[j][i]=a[i][j];
		}
	prim();
	long long ans=0;
	for (int i=1;i<n;i++)
		ans+=d[i];
	printf("%lld\n",ans);
}
//VIJOS https://vijos.org/d/sssgzx/p/5b65c899d3d8a169f1b854a1
