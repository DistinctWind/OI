#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int MAXM=10000;
const string p="Park";
int n,cnt=1,cnt_edge=1,head[1000],cnt_block,block[10000],maxb,d[10000],ans=0x7fffffff;
bool vis[10000],v[10000];
map <string,int> m;
vector <int> vec;
struct Edge{
	int nxt,to,dis;
	bool able;
}edge[MAXM*8];
struct Node{
	int pos,d;
	bool operator < (const Node &a) const{
		return d>a.d;
	}
};
void dfs(int pos)
{
	vis[pos]=true;
	block[pos]=cnt_block;
	for (int i=head[pos];i;i=edge[i].nxt)
	{
		if (!vis[edge[i].to]&&edge[i].able)
		{
			vis[edge[i].to]=true;
			dfs(edge[i].to);
		}
	}
}
inline void add(int from,int to,int dis,bool state)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
	edge[cnt_edge].able=state;
	if (!state) vec.push_back(cnt_edge);
}
void prim()
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[1]=0;
	priority_queue <Node> q;
	q.push(Node{1,0});
	for (int i=1;i<cnt;i++)
	{
		int x=q.top().pos; q.pop();
		while (v[x])
		{
			x=q.top().pos;
			q.pop();
		}
		v[x]=1;
		for (int j=head[x];j;j=edge[j].nxt)
		{
			if (!v[edge[j].to]&&edge[j].able)
			{
				if (d[edge[j].to]>d[x]+edge[j].dis)
				{
					d[edge[j].to]=d[x]+edge[j].dis;
				}
				q.push(Node{edge[j].to,d[edge[j].to]});
			}
		}
	}
	int res=0;
	for (int i=1;i<=cnt;i++)
		if (d[i]==0x3f3f3f3f) return;
		else res+=d[i];
	ans=min(res,ans);
}
void cdfs(int dep,int last,int maxd)
{
	if (dep==maxd+1)
	{
		prim();
		return;
	}
	for (int i=last;i<vec.size();i+=2)
	{
		if (!vis[vec[i]])
		{
			vis[vec[i]]=true; vis[vec[i]^1]=true;
			edge[vec[i]].able=true; edge[vec[i]^1].able=true;
			//printf("Set %d able\n",vec[i]);
			cdfs(dep+1,i+2,maxd);
			vis[vec[i]]=false; vis[vec[i]^1]=false;
			edge[vec[i]].able=false; edge[vec[i]^1].able=false;
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	m[p]=1;
	memset(edge,0,sizeof(edge));
	memset(vis,0,sizeof(vis));
	memset(head,0,sizeof(head));
	memset(block,0,sizeof(block));
	memset(v,0,sizeof(v));
	cnt_edge=1; cnt_block=0; ans=0x7fffffff;
	scanf("%d",&n);
	m[p]=1;
	for (int i=1;i<=n;i++)
	{
		string a,b;
		int dis;
		cin>>a>>b;
		scanf("%d",&dis);
		if (m.find(a)==m.end()) m[a]=++cnt;
		if (m.find(b)==m.end()) m[b]=++cnt;
		if (a==p||b==p)
		{
			add(m[a],m[b],dis,false); add(m[b],m[a],dis,false);
			continue;
		}
		add(m[a],m[b],dis,true); add(m[b],m[a],dis,true);
	}
	scanf("%d",&maxb);
	for (int i=2;i<=cnt;i++)
		if (!vis[i])
		{
			cnt_block++;
			dfs(i);
		}
	if (cnt_block>maxb) return -1;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=maxb;i++)
	{
		cdfs(1,0,i);
	}
	printf("Total miles driven: %d\n",ans);
}
