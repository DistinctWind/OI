#include <cstdio>
#include <vector>
using namespace std;
const int MAXN=30001;
struct Edge{
	int nxt,to;
}edge[MAXN*2];
int n,head[MAXN],cnt_edge,cnt_query,vis[MAXN],fa[MAXN],depth[MAXN],lca[MAXN],m,res[MAXN];
vector <int> query[MAXN],query_id[MAXN];
inline void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
}
inline void setup()
{
	for (int i=1;i<=n;i++)
		fa[i]=i;
}
int find(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline void add_query(int a,int b)
{
	cnt_query++;
	query[a].push_back(b); query_id[a].push_back(cnt_query);
	query[b].push_back(a); query_id[b].push_back(cnt_query);
}
void tarjan(int x)
{
	vis[x]=1;
	for (int i=head[x];i;i=edge[i].nxt)
	{
		if (!vis[edge[i].to])
		{
			depth[edge[i].to]=depth[x]+1;
			tarjan(edge[i].to);
			fa[find(edge[i].to)]=find(x);
		}
	}
	//printf("***At %d\n",x);
	for (int i=0;i<query[x].size();i++)
	{
		//printf("Ask %d\n",query[x][i]);
		if (vis[query[x][i]]==2)
		{
			lca[query_id[x][i]]=find(query[x][i]);
			res[query_id[x][i]]=depth[x]+depth[query[x][i]]-depth[find(query[x][i])]*2;
		}
	}
	vis[x]=2;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b); add(b,a);
	}
	scanf("%d",&m);
	int a,b;
	scanf("%d",&a);
	for (int i=2;i<=m;i++)
	{
		scanf("%d",&b);
		add_query(a,b);
		a=b;
	}
	setup();
	tarjan(1);
	int ans=0;
	for (int i=1;i<m;i++)
		ans+=res[i];
	printf("%d",ans);
}
