#include <cstdio>
#include <limits.h>
#include <queue>
#define MAXK 10001
#define MAXN 100001
#define MAXM 1000001
using namespace std;
int n,m,k,cnt_edge1,cnt_edge2,cnt_ans,ans[101];
int dis[MAXN],head1[MAXN],head2[MAXN];
bool iq[MAXN];//In queue;
struct EDGE{
	int next,to,dis;
}edge1[MAXM],edge2[MAXM];
struct poi{
	int node,weight,used;
	poi(){
		node=weight=used=0;
	}
	friend bool operator < (poi a,poi b)
	{
		return a.weight>b.weight;
	}
};
void setup()
{
	for (int i=1;i<MAXN;i++)
		dis[i]=INT_MAX;
}
void spfa(int s)
{
	setup();
	queue <int> q;
	q.push(s); iq[s]=true;
	dis[s]=0;
	while (!q.empty())
	{
		int front;
		front=q.front();
		q.pop(); iq[front]=false;
		for (int i=head1[front];i!=0;i=edge1[i].next)
			if (dis[edge1[i].to]>dis[front]+edge1[i].dis)
			{
				dis[edge1[i].to]=dis[front]+edge1[i].dis;
				if (iq[edge1[i].to]==false)
				{
					q.push(edge1[i].to); iq[edge1[i].to]=true;
				}
			}
	}
}
void add1(int from,int to,int dis)
{
	cnt_edge1++;
	edge1[cnt_edge1].next=head1[from];
	head1[from]=cnt_edge1;
	edge1[cnt_edge1].to=to;
	edge1[cnt_edge1].dis=dis;
}
void add2(int from,int to,int dis)
{
	cnt_edge2++;
	edge2[cnt_edge2].next=head2[from];
	head2[from]=cnt_edge2;
	edge2[cnt_edge2].to=to;
	edge2[cnt_edge2].dis=dis;
}
void A_star()
{
	priority_queue <poi> q;
	poi start;
	start.node=n; start.weight=dis[n]; start.used=0;
	q.push(start);
	while (!q.empty())
	{
		poi top;
		top=q.top();
		q.pop();
		if (top.node==1)
		{
			ans[++cnt_ans]=top.used;
			if (cnt_ans+1>k) return;
			continue;
		}
		for (int i=head2[top.node];i!=0;i=edge2[i].next)
		{
			poi temp;
			temp.node=edge2[i].to; temp.used=top.used+edge2[i].dis; temp.weight=dis[edge2[i].to]+temp.used;
			q.push(temp);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin); 
	//freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		int from,to,d;
		scanf("%d%d%d",&from,&to,&d);
		add2(from,to,d); add1(to,from,d);
	}
	spfa(1);
	A_star();
	for (int i=1;i<=k;i++)
		if (i<=cnt_ans) printf("%d\n",ans[i]);
		else printf("-1\n");
	/*for (int i=1;i<=n;i++)
		printf("From 1 to %d val=%d\n",i,dis[i]);*/
}
