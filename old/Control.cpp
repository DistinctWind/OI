#include <cstdio>
#include <vector>
#include <set>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN=50010;
const int MAXM=50010;
const int LOGN=18;
int n,m,cnt,head[MAXN],cnt_edge;
int f[MAXN][LOGN],g[MAXN][LOGN];
int block[MAXN],calc[MAXN];
int fa[MAXN];
ll ans;
struct Edge{
	int nxt,to;
	ll dis;
}edge[MAXM<<1];
struct state{
	int pos;
	ll used;
	state(){
		pos=used=0;
	}
};
struct City{
	int pos;
	ll dis;
};
vector <int> army;
vector <state> mov;
set <int> son;
priority_queue <City> q;
inline void add(int from,int to,ll dis)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
void dfs(int u,int pre)
{
	block[u]=cnt;
	f[u][0]=pre;
	for (int j=1;j<LOGN;j++)
		{
			if (f[u][j-1]!=0)
			{
				f[u][j]=f[f[u][j-1]][j-1];
				g[u][j]=g[u][j-1]+g[f[u][j-1]][j-1];
			}
		}
	for (int i=head[u];i;i=edge[i].nxt)
	{
		if (edge[i].to!=pre)
		{
			g[edge[i].to][0]=edge[i].dis;
			dfs(edge[i].to,u);
			if (u==1)
			{
				cnt++;
				son.insert(edge[i].to);
				fa[cnt]=edge[i].to;
			}
		}
	}
}
bool check(ll limit)
{
	for (vector<int>::iterator i=army.begin();i!=army.end();i++)
	{
		int now=*i;
		ll used=0;
		for (int j=LOGN-1;i>=0;i--)
		{
			if (now!=1&&used+g[now][j]<=limit)
			{
				now=f[now][j];
				used+=g[now][j];
			}
		}
		
	}
}
inline void solve()
{
	if (cnt>m)
	{
		printf("-1");
		return;
	}
	ll l=0,r=LLONG_MAX;
	while (l<=r)
	{
		ll mid=l+r>>1;
		if (check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%lld",ans);
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	dfs(1,0);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int p;
		scanf("%d",&p);
		army.push_back(p);
		calc[block[p]]++;
	}
	solve();
}
