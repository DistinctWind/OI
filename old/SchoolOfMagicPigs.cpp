#include <cstdio>
#include <queue>
using namespace std;
const int MAXN=5001;
const int MAXM=200001;
struct Edge{
	int nxt,to;
	double dis;
}edge1[MAXM],edge2[MAXM];
double d[MAXN];
struct state{
	int pos;
	double used;
	bool operator < (const state &a) const
	{
		return used+d[pos]>a.used+d[a.pos];
	}
};
int n,m,cnt_edge1,cnt_edge2,head1[MAXN],head2[MAXN],ans,cnt[MAXN];
double e;
bool iq[MAXN];
inline void add1(int from,int to,double dis)
{
	cnt_edge1++;
	edge1[cnt_edge1].nxt=head1[from];
	head1[from]=cnt_edge1;
	edge1[cnt_edge1].to=to;
	edge1[cnt_edge1].dis=dis;
}
inline void add2(int from,int to,double dis)
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
	iq[n]=true; q.push(n);
	for (int i=1;i<=n;i++)
		d[i]=0x7fffffff;
	d[n]=0;
	while (!q.empty())
	{
		int front=q.front(); q.pop();
		iq[front]=false;
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
void A_star()
{
    int k=e/d[1];
    priority_queue <state> q;
    state start;
    start.pos=1,start.used=0;
    q.push(start);
    while (!q.empty())
    {
    	state top;
    	top=q.top();
    	q.pop();
    	if (top.used>e) return;
    	cnt[top.pos]++;
    	if (top.pos==n)
    	{
    		e-=top.used;
    		ans++;
    		continue;
    	}
    	if (cnt[top.pos]>k) continue;
    	for (int i=head1[top.pos];i;i=edge1[i].nxt)
    	{
    		state tmp;
    		tmp.pos=edge1[i].to; tmp.used=top.used+edge1[i].dis;
    		q.push(tmp);
    	}
    }
}
int main()
{
	//freopen("in.txt","r",stdin);
	//clock_t start,end;
	//start=clock();
	scanf("%d%d%lf",&n,&m,&e);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		double dis;
		scanf("%d%d%lf",&a,&b,&dis);
		add1(a,b,dis); add2(b,a,dis);
	}
	spfa();
	A_star();
	//end=clock();
	printf("%d\n",ans);
	//printf("%.3lf",(double)(end-start)/CLOCKS_PER_SEC);
}
