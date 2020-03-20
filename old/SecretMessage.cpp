#include <cstdio>
#include <cstring>
using namespace std;
const int MAXM=5e4+1;
const int MAXN=5e4+1;
const int MAXB=1e4+1;
const int MAXC=1e4+1;
const int MAXP=5e5+1;
int m,n,l,tmp[MAXC];
int tot=1,tree[MAXP*2][2],ans[MAXM];
int end[MAXP],pass[MAXP];
inline void insert()
{
	int u=1;
	for (int i=1;i<=l;i++)
	{
		if (tree[u][tmp[i]]==0) tree[u][tmp[i]]=++tot;
		u=tree[u][tmp[i]];
		pass[u]++;
	}
	end[u]++;
}
inline void search()
{
	int u=1,ans=0;
	for (int i=1;i<=l;i++)
	{
		if (tree[u][tmp[i]]!=0) u=tree[u][tmp[i]],ans+=end[u];
		else
		{
			printf("%d\n",ans);
			return;
		}
	}
	ans=ans-end[u]+pass[u];
	printf("%d\n",ans);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		memset(tmp,0,sizeof(tmp));
		scanf("%d",&l);
		for (int j=1;j<=l;j++)
			scanf("%d",&tmp[j]);
		insert();
	}
	for (int i=1;i<=m;i++)
	{
		memset(tmp,0,sizeof(tmp));
		scanf("%d",&l);
		for (int j=1;j<=l;j++)
			scanf("%d",&tmp[j]);
		search();
	}
}
//LOJ https://loj.ac/problem/10054
