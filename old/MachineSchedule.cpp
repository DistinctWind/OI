#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=1100;
const int MAXM=1100;
const int MAXK=10100;
int n,m,k,ans;
int head[MAXN<<1],cnt_edge;
int match[MAXN<<1];
bool vis[MAXN<<1];
struct Edge{
	int nxt,to;
}edge[MAXK<<1];
inline void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
}
bool dfs(int x)
{
	for (int i=head[x];i;i=edge[i].nxt)
	{
		int y;
		if (!vis[y=edge[i].to])
		{
			vis[y]=true;
			if (!match[y]||dfs(match[y]))
			{
				match[y]=x;
				return true;
			}
		}
	}
	return false;
}
inline void setup()
{
	ans=0; cnt_edge=0;
	memset(head,0,sizeof(head));
	memset(edge,0,sizeof(edge));
	memset(match,0,sizeof(match));
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d",&n),n!=0)
	{
		setup();
		scanf("%d%d",&m,&k);
		for (int i=1;i<=k;i++)
		{
			int useless,a,b;
			scanf("%d%d%d",&useless,&a,&b);
			if(a==0||b==0)continue;
			add(a,b+n); add(b+n,a);
		}
		for (int i=0;i<n;i++)
		{
			memset(vis,0,sizeof(vis));
			if (dfs(i))
				ans++;
		}
		printf("%d\n",ans);
	}
}

