#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=5010;
const int MAXM=50010;
int n,m;
int cntEdge,head[MAXN],nxt[MAXM<<1],ver[MAXM<<1];
int root,cnt,dfn[MAXN],low[MAXN];
bool vis[MAXN],mk[MAXN];
vector<int> ans;
stack<int> s;
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
inline void check(vector<int> now)
{
	if (ans.size()==0||ans.size()<now.size())
	{
		ans=now;
		return;
	}
	if (ans.size()>now.size()) return;
	vector<int>::iterator i=now.begin();
	vector<int>::iterator j=ans.begin();
	for (;i!=now.end()&&j!=ans.end();i++,j++)
		if (*i<*j)
		{
			ans=now;
			return;
		}
}
void tarjan(int x)
{
	cnt++;
	dfn[x]=low[x]=cnt;
	vis[x]=true;
	s.push(x);
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if (vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if (low[x]==dfn[x])
	{
		vector<int> tmp;
		do
		{
			vis[s.top()]=false;
			tmp.push_back(s.top());
			s.pop();
		}while (!s.empty()&&vis[x]);
		sort(tmp.begin(),tmp.end());
		check(tmp);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,a,b,t;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&t);
		add(a,b);
		if (t==2) add(b,a);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i])
			tarjan(i);
	printf("%d\n",ans.size());
	for (vector<int>::iterator i=ans.begin();i!=ans.end();i++)
		printf("%d ",*i);
}
