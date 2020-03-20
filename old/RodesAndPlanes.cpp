#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int MAXE=100001;
const int MAXN=50001;
int t,r,p,s,cnt,cnt_edge;
struct Edge{
	int nxt,to,dis;
}edge[MAXE*2];
int block[MAXN],in[MAXN],d[MAXN],head[MAXN];
struct Node{
	int pos,dis;
};
bool operator < (const Node &a,const Node &b)
{
	return a.dis>b.dis;
}
vector <int> bl[MAXN];
bool vis[MAXN];
inline void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
void dfs(int pos)
{
	block[pos]=cnt;
	bl[cnt].push_back(pos);
	vis[pos]=true;
	for (int i=head[pos];i;i=edge[i].nxt)
	{
		if (!vis[edge[i].to])
			dfs(edge[i].to);
	}
}
queue <int> Q;
priority_queue <Node> q;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d%d%d",&t,&r,&p,&s);
	for (int i=1;i<=r;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		add(a,b,dis); add(b,a,dis);
	}
	for (int i=1;i<=t;i++)
		if (!vis[i])
		{
			cnt++;
			dfs(i);
		}
	for (int i=1;i<=p;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		add(a,b,dis); in[block[b]]++;
	}
	Q.push(block[s]);
	for (int i=1;i<=cnt;i++)
		if (!in[i]) Q.push(i);
	memset(vis,0,sizeof(vis));
	memset(d,0x7f,sizeof(d));
	d[s]=0;
	while (!Q.empty())
	{
		int nowblo=Q.front(); Q.pop();
		for (int i=0;i<bl[nowblo].size();i++)
		{
			Node tmp; tmp.pos=bl[nowblo][i]; tmp.dis=d[tmp.pos];
			q.push(tmp);
		}
		while (!q.empty())
		{
			Node front=q.top(); q.pop();
			if (vis[front.pos]) continue;
			vis[front.pos]=true;
			for (int i=head[front.pos];i;i=edge[i].nxt)
			{
				if (d[edge[i].to]>d[front.pos]+edge[i].dis)
				{
					d[edge[i].to]=d[front.pos]+edge[i].dis;
					if (block[edge[i].to]==block[front.pos])
					{
						Node tmp; tmp.pos=edge[i].to; tmp.dis=d[edge[i].to];
						q.push(tmp);
					}
				}
				if (block[edge[i].to]!=block[front.pos]&&(--in[block[edge[i].to]])==0)
					Q.push(block[edge[i].to]);
			}
		}
	}
	for (int i=1;i<=t;i++)
		if (d[i]>0x3f3f3f3f) printf("NO PATH\n");
		else printf("%d\n",d[i]);
}
