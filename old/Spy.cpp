#include <cstdio>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
const int MAXN=3010;
const int MAXM=10010;
int n,p,r,ans,val[MAXN];
int cnt_edge,head[MAXN];
int dfn[MAXN],low[MAXN],in[MAXN],b[MAXN],t,cnt_block;
bool is[MAXN],vis[MAXN];
stack <int> s;
vector <int> vec[MAXN];
struct Edge{
	int nxt,to;
}edge[MAXM];
inline void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
}
void tanjan(int x)
{
	dfn[x]=low[x]=++t;
	is[x]=true;
	s.push(x);
	for (int i=head[x];i;i=edge[i].nxt)
	{
		if (!dfn[edge[i].to])
		{
			tanjan(edge[i].to);
			if (low[edge[i].to]<low[x])
				low[x]=low[edge[i].to];
		}
		else if (is[edge[i].to]&&low[edge[i].to]<low[x])
			low[x]=low[edge[i].to];
	}
	if (dfn[x]==low[x])
	{
		int i;
		cnt_block++;
		do
		{
			i=s.top(); s.pop();
			is[i]=false;
			b[i]=cnt_block;
			for (int j=head[i];j;j=edge[j].nxt)
				if (b[i]!=b[edge[j].to])
					in[b[edge[j].to]]++;
			vec[b[i]].push_back(i);
		}
		while (low[i]!=dfn[i]);
	}
}
void dfs(int x)
{
	vis[x]=true;
	for (int i=head[x];i;i=edge[i].nxt)
	{
		if (!vis[edge[i].to])
		{
			dfs(edge[i].to);
		}
	}
}
inline void solve()
{
	for (int i=1;i<=n;i++)
		if (!dfn[i])
			tanjan(i);
	for (int i=1;i<=cnt_block;i++)
	{
		if (in[i]==0)
		{
			int res=0x7fffffff;
			for (vector<int>::iterator j=vec[i].begin();j!=vec[i].end();j++)
			{
				if (val[*j]==-1) continue;
				else
				{
					res=min(res,val[*j]);
					dfs(*j);
				}
			}
			if (res==0x7fffffff)
			{
				continue;
			}
			ans+=res;
		}
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			printf("NO\n%d\n",i);
			exit(0);
		}
	printf("YES\n%d\n",ans);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&p);
	memset(val,0xff,sizeof(val));
	for (int i=1;i<=p;i++)
	{
		int x;
		scanf("%d",&x);
		scanf("%d",&val[x]);
	}
	scanf("%d",&r);
	for (int i=1;i<=r;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	solve();
}
//LOJ https://loj.ac/problem/10095#submit_code
//LGOJ https://www.luogu.org/problem/P1262
