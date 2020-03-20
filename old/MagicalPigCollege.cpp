#include <cstdio>
#include <queue>
#include <limits.h>
#define MAXN 5001
#define MAXM 200001
using namespace std;
int n,m,cnt_edge1,cnt_edge2,head1[MAXN],head2[MAXN],ans;
double max_e,dis[MAXN];
bool iq[MAXN];
struct EDGE{
	int next,to;
	double dis;
}edge1[MAXM],edge2[MAXM];
struct state{
	int node;
	double used;
	friend bool operator < (state a,state b)
	{
		return a.used+dis[a.node]>b.used+dis[b.node];
	}
};
void add1(int from,int to,double dis)
{
	cnt_edge1++;
	edge1[cnt_edge1].next=head1[from];
	head1[from]=cnt_edge1;
	edge1[cnt_edge1].to=to;
	edge1[cnt_edge1].dis=dis;
}
void add2(int from,int to,double dis)
{
	cnt_edge2++;
	edge2[cnt_edge2].next=head2[from];
	head2[from]=cnt_edge2;
	edge2[cnt_edge2].to=to;
	edge2[cnt_edge2].dis=dis;
}
void setup()
{
	for (int i=1;i<=n;i++)
		dis[i]=INT_MAX;
}
void spfa()//use map2
{
	setup();
	queue <int> q;
	dis[n]=0;
	q.push(n); iq[n]=true;
	while (!q.empty())
	{
		int front;
		front=q.front();
		q.pop(); iq[front]=false;
		for (int i=head2[front];i!=0;i=edge2[i].next)
		{
			int temp;
			temp=edge2[i].to;
			if (dis[temp]>dis[front]+edge2[i].dis)
			{
				dis[temp]=dis[front]+edge2[i].dis;
				if (iq[temp]==false)
				{
					q.push(temp); iq[temp]=true;
				}
			}
		}
	}
}
void A_star()//use map1
{
	spfa();
	priority_queue <state> q;
	state start;
	start.node=1; start.used=0;
	q.push(start);
	while (!q.empty())
	{
		state top;
		top=q.top();
		q.pop();
		if (top.node==n&&top.used<=max_e)
		{
			ans++;
			max_e-=top.used;
			continue;
		}
		if (top.used>max_e)
			return;
		for (int i=head1[top.node];i!=0;i=edge1[i].next)
		{
			state temp;
			temp.node=edge1[i].to; temp.used=top.used+edge1[i].dis;
			q.push(temp);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d%lf",&n,&m,&max_e);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		double d;
		scanf("%d%d%lf",&a,&b,&d);
		add1(a,b,d); add2(b,a,d);
	}
	/*spfa();
	for (int i=1;i<=n;i++)
		printf("To %d min_val=%lf\n",i,dis[i]);*/
	A_star();
	printf("%d",ans);
}
