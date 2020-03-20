#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=301;
const int MAXM=100001;
struct Edge{
	int u,v,dis;
	bool operator < (const Edge &a) const{
		return dis<a.dis;
	}
}a[MAXM];
int n,m,fa[MAXN],ans,k;
int find(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		a[i]=(Edge){u,v,c};
	}
	sort(a+1,a+1+m);
	for (int i=1;i<=n;i++)
		fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=find(a[i].u);
		int y=find(a[i].v);
		if (x!=y)
		{
			fa[x]=y;
			k++;
			ans=a[i].dis;
		}
		if (k==n-1) break;
	}
	printf("%d %d\n",n-1,ans);
}
