#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=10001;
struct Edge{
	int a,b,dis;
	bool operator < (const Edge &a) const{
		return dis<a.dis;
	}
}edge[MAXN];
int t,n,fa[MAXN],s[MAXN],ans;
int find(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void solve()
{
	sort(edge+1,edge+n);
	for (int i=1;i<n;i++)
	{
		int x=find(edge[i].a); 
		int y=find(edge[i].b);
		if (x==y) continue;
		ans+=(s[x]*s[y]-1)*(edge[i].dis+1);
		fa[x]=y;
		s[y]+=s[x];
	}
}
inline void setup()
{
	ans=0;
	for (int i=1;i<=n;i++)
		fa[i]=i,s[i]=1;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		setup();
		for (int i=1;i<n;i++)
		{
			scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].dis);
		}
		solve();
		printf("%d\n",ans);
	}
}
