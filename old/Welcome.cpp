#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int MAXN=10010;
const int MAXM=50010;
int n,m;
int head[MAXN],cnt_edge;
int bhead[MAXN],cnt_bedge;
int dfn[MAXN],b[MAXN],low[MAXN],t,ans=-1;
int out[MAXN];
int cnt_block;
stack <int> s;
vector <int> block[MAXN];
bool is[MAXN];
struct Edge{
	int nxt,to;
}edge[MAXM],bedge[MAXM];
inline void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
}
inline void badd(int from,int to)
{
	cnt_bedge++;
	bedge[cnt_bedge].nxt=bhead[from];
	bhead[from]=cnt_bedge;
	bedge[cnt_bedge].to=to;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++t;
	is[x]=true;
	s.push(x);
	for (int i=head[x];i;i=edge[i].nxt)
		if (!dfn[edge[i].to])
		{
			tarjan(edge[i].to);
			if (low[edge[i].to]<low[x])
				low[x]=low[edge[i].to];
		}
		else if (is[edge[i].to]&&low[edge[i].to]<low[x])
		{
			low[x]=low[edge[i].to];
		}
	if (low[x]==dfn[x])
	{
		int i;
		cnt_block++;
		do
		{
			i=s.top(); s.pop();
			b[i]=cnt_block;
			is[i]=false;
			for (int j=head[i];j;j=edge[j].nxt)
				if (!is[edge[j].to]&&b[i]!=b[edge[j].to])
					out[b[i]]++;
			block[cnt_block].push_back(i);
		}
		while (low[i]!=dfn[i]);
	}
}
inline void solve()
{
	for (int i=1;i<=n;i++)
		if (!dfn[i])
			tarjan(i);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	solve();
	for (int i=1;i<=cnt_block;i++)
	{
		if (out[i]==0)
		{
			if (ans!=-1)
			{
				printf("0");
				return 0;
			}
			else ans=i;
		}
	}
	printf("%d\n",(int)block[ans].size());
}
//LGOJ https://www.luogu.org/problem/P2341
