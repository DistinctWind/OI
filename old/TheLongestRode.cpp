#include <cstdio>
#include <iostream>
#include <queue>
#include <stdlib.h>
#define MAXN 1501
#define MAXM 50001
using namespace std;
int n,m;
int dis[MAXN];
bool vis[MAXN];
int head[MAXN],cnt_edge;
struct EDGE{
	int next,to,dis;
}edge[MAXM];
struct state{
	int x,cost;
	friend bool operator < (state a,state b)
	{
		return a.cost>b.cost;
	}
};
void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].next=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
/*void bfs()
{
	priority_queue <state> q;
	state start;
	start.x=1; start.cost=0;
	q.push(start);
	while (!q.empty())
	{
		state top=q.top();
		q.pop();
		if (top.x==n)
		{
			printf("%d",top.cost);
			exit(0);
		}
		for (int i=head[top.x];i!=0;i=edge[i].next)
		{
			int son=edge[i].to;
			state temp;
			temp.x=son; temp.cost=edge[i].dis;
			q.push(temp);
		}
	}
}*/
/*int ms(int x)
{
	int temp=0;
	if (memory[x]>0)
		return memory[x];
	for (int i=head[x];i!=0;i=edge[i].next)
	{
		int son=edge[i].to;
		temp=max(temp,ms(son)+edge[i].dis);
	}
}*/
int fspfa()
{
	queue <int> q;
	q.push(1);
	while (!q.empty())
	{
		int front=q.front();
		q.pop();
		vis[front]=false;
		for (int i=head[front];i!=0;i=edge[i].next)
		{
			int son=edge[i].to;
			if (dis[front]+edge[i].dis>dis[son])
			{
				dis[son]=dis[front]+edge[i].dis;
				if (vis[son]==false)
				{
					q.push(son);
					vis[son]=true;
				}
			}
		}
	}
	if (dis[n]!=0)
		return dis[n];
	else return -1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	printf("%d",fspfa());
}
