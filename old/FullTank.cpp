#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN=1001;
const int MAXM=10001;
const int MAXC=101;
struct EDGE{
	int to,nxt,dis;
}edge[MAXM*2];
struct state{
	int pos,left,cost;
	friend bool operator < (state a,state b)
	{
		return a.cost>b.cost;
	}
};
int n,m,q,c,s,e,ans,cnt_edge;
int p[MAXN],head[MAXN];
bool vis[MAXN][MAXC];
inline void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
inline void bfs()
{
	priority_queue <state> q;
	state start;
	start.pos=s,start.left=0,start.cost=0;;
	q.push(start);
	memset(vis,0,sizeof(vis));
	while (!q.empty())
	{
		state h=q.top(); q.pop();
		vis[h.pos][h.left]=true;
		if (h.pos==e)
		{
			ans=h.cost;
			return;
		}
		if (h.left<c&&!vis[h.pos][h.left+1])
		{
			state tmp;
			tmp.pos=h.pos;
			tmp.left=h.left+1;
			tmp.cost=h.cost+p[h.pos];
			q.push(tmp);
		}
		for (int i=head[h.pos];i;i=edge[i].nxt)
		{
			if (h.left>=edge[i].dis&&!vis[edge[i].to][h.left-edge[i].dis])
			{
				state tmp;
				tmp.pos=edge[i].to;
				tmp.left=h.left-edge[i].dis;
				tmp.cost=h.cost;
				q.push(tmp);
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		scanf("%d",&p[i]);
	for (int i=1;i<=m;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		add(a,b,dis); add(b,a,dis);
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&c,&s,&e);
		ans=-1;
		bfs();
		if (ans!=-1) printf("%d\n",ans);
		else printf("impossible\n");
	}
}
