#include <cstdio>
#include <queue>
#include <limits.h>
#define MAXN 1001
#define MAXM 1001
using namespace std;
int n,m,cnt_edge,head[MAXN],dis[MAXM];
bool iq[MAXN];
struct EDGE{
	int next,to,dis;
}edge[MAXM];
void setup()
{
	for (int i=1;i<=MAXM;i++)
		dis[i]=INT_MAX;
}
void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].next=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
void spfa(int s)
{
	setup();
	queue <int> q;
	dis[s]=0;
	q.push(s); iq[s]=true;
	while (!q.empty())
	{
		int front;
		front=q.front();
		q.pop(); iq[front]=false;
		printf("Now at %d\n",front);
		for (int i=head[front];i!=0;i=edge[i].next)
		{
			if (dis[edge[i].to]>dis[front]+edge[i].dis)
			{
				dis[edge[i].to]=dis[front]+edge[i].dis;
				printf("Next point is %d,with val=%d\n",edge[i].to,dis[edge[i].to]);
				if (iq[edge[i].to]==false)
				{
					q.push(edge[i].to); iq[edge[i].to]=true;
					printf("This point is not in queue,put it in.\n");
				}
			}
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		add(a,b,dis); add(b,a,dis);
	}
	printf("Input the point begins at:");
	int s;
	scanf("%d",&s);
	spfa(s);
	for (int i=1;i<=n;i++)
		printf("From %d to %d dis=%d\n",s,i,dis[i]);
}
