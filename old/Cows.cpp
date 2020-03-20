#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=1001;
const int MAXM=100001;
struct Edge{
	int nxt,to,dis;
}edge1[MAXM],edge2[MAXM];
int head1[MAXN],head2[MAXN];
int d1[MAXN],d2[MAXN];
bool iq[MAXN];
int cnt_edge1,cnt_edge2;
int n,m,x;
int max(int a,int b)
{
	return a>b?a:b;
}
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
inline void spfa1()
{
	queue <int> q;
	q.push(x);
	memset(d1,0x3f,sizeof(d1));
	d1[x]=0;
	while (!q.empty())
	{
		int front=q.front(); q.pop();
		iq[front]=false;
		for (int i=head1[front];i;i=edge1[i].nxt)
		{
			if (d1[edge1[i].to]>d1[front]+edge1[i].dis)
			{
				d1[edge1[i].to]=d1[front]+edge1[i].dis;
				if (!iq[edge1[i].to])
				{
					iq[edge1[i].to]=true;
					q.push(edge1[i].to);
				}
			}
		}
	}
}
inline void spfa2()
{
	queue <int> q;
	q.push(x);
	memset(d2,0x3f,sizeof(d2));
	memset(iq,0,sizeof(iq));
	d2[x]=0;
	while (!q.empty())
	{
		int front=q.front(); q.pop();
		iq[front]=false;
		for (int i=head2[front];i;i=edge2[i].nxt)
		{
			if (d2[edge2[i].to]>d2[front]+edge2[i].dis)
			{
				d2[edge2[i].to]=d2[front]+edge2[i].dis;
				if (!iq[edge2[i].to])
				{
					iq[edge2[i].to]=true;
					q.push(edge2[i].to);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for (int i=1;i<=m;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		add1(a,b,dis); add2(b,a,dis);
	}
	spfa1(); spfa2();
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,d1[i]+d2[i]);
	}
	printf("%d",ans);
}
