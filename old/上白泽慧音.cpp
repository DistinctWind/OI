#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=5010;
const int MAXM=50010;
int n,m;
int cntEdge,head[MAXN],nxt[MAXM<<1],ver[MAXM<<1];
int cnt,dfn[MAXN],low[MAXN],cntBlock;
struct Block{
	int len;
	vector <int> v;
}b[MAXN];
bool vis[MAXN];
stack <int> s;
vector <int> ans;
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
void check(vector <int> now)
{
	if (ans.size()==0)
	{
		ans=now;
		return;
	}
	if (now.size()>ans.size())
	{
		for (vector<int>::iterator i=now.begin();i!=now.end();i++)
			for (vector<int>::iterator j=ans.begin();i!=ans.end();j++)
				if (*i<*j)
				{
					ans=now;
					return;
				}
	}
}
void tarjan(int x)
{
	cnt++;
	dfn[x]=cnt;
	low[x]=cnt;
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
		{
			low[x]=min(low[x],dfn[y]);
		}
	}
	if (low[x]==dfn[x])
	{
		vector <int> tmp;
		do
		{
			vis[s.top()]=false;
			tmp.push_back(s.top());
			s.pop();
		}while (!s.empty()&&vis[x]);
		/*for (vector<int>::iterator i=tmp.begin();i!=tmp.end();i++)
			printf("%d ",*i);
		putchar('\n');*/
		sort(tmp.begin(),tmp.end());
		check(tmp);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
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
	{
		printf("%d ",*i);
	}
}
