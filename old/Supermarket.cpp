#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1e4+1;
struct Goods{
	int p,d;
	friend bool operator < (Goods a,Goods b)
	{
		return a.p>b.p;
	}
}g[MAXN];
int n,ans,fa[MAXN];
int find(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline void merge(int a,int b)
{
	fa[find(a)]=find(b);
}
inline void setup()
{
	ans=0;
	memset(g,0,sizeof(g));
	for (int i=1;i<MAXN;i++)
		fa[i]=i;
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d",&n)!=EOF)
	{
		setup();
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&g[i].p,&g[i].d);
		}
		sort(g+1,g+1+n);
		for (int i=1;i<=n;i++)
		{
			if (find(g[i].d)>0)
			{
				ans+=g[i].p;
				merge(find(g[i].d),find(g[i].d)-1);
			}
		}
		printf("%d\n",ans);
	}
}

