#include <cstdio>
#include <cstring>
#define MAXN 200005
using namespace std;
int n,cnt_edge,head[MAXN];
int d1[MAXN],d2[MAXN];
int max_poi;
bool vis[MAXN],out[MAXN];
struct EDGE{
	int next,to;
}edge[MAXN*2+5];
void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].next=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
}
void dp(int x)
{
	vis[x]=true;
	for (int i=head[x];i!=0;i=edge[i].next)
	{
		int son=edge[i].to;
		if (vis[son])
			continue;
		dp(son);
		if (d1[son]+1>d1[x])
			d2[x]=d1[x],d1[x]=d1[son]+1;
		else if (d1[son]+1>d2[x])
			d2[x]=d1[son]+1;
	}
}
int max(int a,int b)
{
	return a>b?a:b;
}
void dfs(int x)
{
	out[x]=true;
	for (int i=head[x];i!=0;i=edge[i].next)
	{
		int son=edge[i].to;
		if (d1[son]+1==d1[x])
		{
			dfs(son);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b); add(b,a);
	}
	dp(0);
	for (int i=0;i<n;i++)
		max_poi=max(max_poi,d1[i]+d2[i]+1);
	int start=0;
	for (int x=0;x<n;x++)
		if (d1[x]+d2[x]+1==max_poi)
		{
			start=x;
			out[start]=true;
			for (int i=head[start];i!=0;i=edge[i].next)
			{
				int son=edge[i].to;
				if ((d1[start]==d1[son]+1)||(d2[start]==d1[son]+1))
				{
					out[son]=true;
					dfs(son);
				}
			}
		}
	for (int i=0;i<n;i++)
		if (out[i])
			printf("%d\n",i);
}
