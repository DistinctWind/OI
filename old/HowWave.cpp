#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=2501;
const int MAXC=6201;
struct Edge{
	int to,nxt,dis;
}edge[MAXC*2];
int t,c,ts,te,head[MAXN],cnt_edge,d[MAXN];
bool iq[MAXN];
inline void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
inline void spfa()
{
	queue <int> q;
	memset(d,0x3f,sizeof(d));
	d[ts]=0;
	iq[ts]=true;
	q.push(ts);
	while (!q.empty())
	{
		int front=q.front(); q.pop();
		iq[front]=false;
		for (int i=head[front];i;i=edge[i].nxt)
		{
			if (d[edge[i].to]>d[front]+edge[i].dis)
			{
				d[edge[i].to]=d[front]+edge[i].dis;
				if (!iq[edge[i].to])
				{
					iq[edge[i].to]=true;
					q.push(edge[i].to);
				}
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&t,&c,&ts,&te);
	for (int i=1;i<=c;i++)
	{
		int rs,re,ci;
		scanf("%d%d%d",&rs,&re,&ci);
		add(rs,re,ci); add(re,rs,ci);
	}
	spfa();
	printf("%d\n",d[te]);
}
