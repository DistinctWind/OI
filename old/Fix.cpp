#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
int T,r,c,cnt_edge,ans;
int head[300001],d[300001];
bool vis[300001];
struct EDGE{
	int to,nxt,dis;
}edge[1200001];
struct state{
	int num,step;
	friend bool operator < (state a,state b)
	{
		return a.step>b.step;
	}
};
inline void add(int from,int to,int v)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=v;
}
/*void spfa()
{
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[1]=0;
	queue <int> q;
	q.push(1); vis[1]=true;
	while (!q.empty())
	{
		int front=q.front(); q.pop();
		for (int i=head[front];i;i=edge[i].nxt)
		{
			if (d[edge[i].to]>d[front]+edge[i].dis)
			{
				d[edge[i].to]=d[front]+edge[i].dis;
				if (!vis[edge[i].to])
				{
					q.push(edge[i].to);
					vis[edge[i].to]=true;
				}
			}
		}
	}
}*/
void bfs()
{
	deque <state> q;
	memset(vis,0,sizeof(vis));
	state start;
	start.num=1,start.step=0;
	vis[1]=true;
	q.push_front(start);
	while (!q.empty())
	{
		state front=q.front();
		q.pop_front();
		vis[front.num]=true;
		if (front.num==r*(c+1)+c+1)
		{
			ans=front.step;
			return;
		}
		for (int i=head[front.num];i;i=edge[i].nxt)
		{
			if (!vis[edge[i].to])
			{
				state tmp;
				tmp.num=edge[i].to;
				tmp.step=front.step+edge[i].dis;
				if (edge[i].dis) q.push_back(tmp);
				else q.push_front(tmp);
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&T);
	while (T--)
	{
		memset(edge,0,sizeof(edge));
		memset(head,0,sizeof(head));
		cnt_edge=0; ans=-1;
		scanf("%d%d",&r,&c);
		for (int i=1;i<=r;i++)
			for (int j=1;j<=c;j++)
			{
				char tmp;
				scanf(" %c",&tmp);
				int lt,rt,ld,rd;
				lt=(i-1)*(c+1)+j;
				rt=((i+1)-1)*(c+1)+j;
				ld=(i-1)*(c+1)+(j+1);
				rd=((i+1)-1)*(c+1)+(j+1);
				if (tmp=='/')
				{
					add(lt,rd,1);
					add(rd,lt,1);
					add(rt,ld,0);
					add(ld,rt,0);
				}
				else 
				{
					add(lt,rd,0);
					add(rd,lt,0);
					add(rt,ld,1);
					add(ld,rt,1);
				}
			}
		bfs();
		if (ans==-1) printf("NO SOLUTION\n");
		else printf("%d\n",ans);
	}
}
//DHOJ http://47.104.154.247/problem.php?cid=1132&pid=2
