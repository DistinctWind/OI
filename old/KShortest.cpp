#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXM=100001;
const int MAXN=1001;
struct Edge{
	int nxt,to,dis;
}edge1[MAXM],edge2[MAXM];
int d[MAXN],cnt;
struct state{
	int pos,val;
	friend bool operator < (state a,state b)
	{
		return a.val+d[a.pos]>b.val+d[b.pos];
	}
};
int cnt_edge1,cnt_edge2,head1[MAXN],head2[MAXN],n,m,s,t,k;
bool iq[MAXN];
inline void add1(int from,int to,int dis)
{
	cnt_edge1++;
	edge1[cnt_edge1].nxt=head1[from];
	head1[from]=cnt_edge1;
	edge1[cnt_edge1].to=to;
	edge1[cnt_edge1].dis=dis;
}
inline void add2(int from,int to,int dis)
{
	cnt_edge2++;
	edge2[cnt_edge2].nxt=head2[from];
	head2[from]=cnt_edge2;
	edge2[cnt_edge2].to=to;
	edge2[cnt_edge2].dis=dis;
}
inline void spfa()
{
	queue <int> q;
	q.push(t); iq[t]=true;
	memset(d,0x3f,sizeof(d));
	d[t]=0;
	while (!q.empty())
	{
		int front=q.front(); q.pop(); iq[front]=false;
		for (int i=head2[front];i;i=edge2[i].nxt)
		{
			if (d[edge2[i].to]>d[front]+edge2[i].dis)
			{
				d[edge2[i].to]=d[front]+edge2[i].dis;
				if (!iq[edge2[i].to])
				{
					iq[edge2[i].to]=true;
					q.push(edge2[i].to);
				}
			}
		}
	}
}
int bfs()
{
	priority_queue <state> q;
	state start;
	start.pos=s;start.val=0;
	q.push(start);
	if (s==t) k++;
	while (!q.empty())
	{
		state h=q.top(); q.pop();
		//printf("***At%d:\n",h.pos);
		if (h.pos==t)
		{
			cnt++;
			//printf("ReachWith%d\n",h.val);
		}
		if (cnt==k)
			return h.val;
		for (int i=head1[h.pos];i;i=edge1[i].nxt)
		{
			state tmp;
			tmp.pos=edge1[i].to;
			//printf("%d\n",tmp.pos);
			tmp.val=h.val+edge1[i].dis;
			q.push(tmp);
		}
	}
	return -1;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		add1(a,b,dis); add2(b,a,dis);
	}
	scanf("%d%d%d",&s,&t,&k);
	spfa();
	printf("%d\n",bfs());
}
