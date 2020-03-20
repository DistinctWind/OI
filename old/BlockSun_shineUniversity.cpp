#include <cstdio>
#include <iostream>
#define MAXN 10001
#define MAXM 100001
using namespace std;
bool vis[MAXN];
int n,m,cnt_edge,ans;
int head[MAXN],sum[2],col[MAXN];
struct EDGE{
	int next,to;
}edge[MAXM*2];
void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].next=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
}
bool dfs(int node,int color)
{
	if (vis[node]==true)
	{
		if (col[node]==color) return true;
		return false;
	}
	vis[node]=true;
	sum[col[node]=color]++;
	bool tf=true;
	for (int i=head[node];i!=0&&tf;i=edge[i].next)
		tf=tf&&dfs(edge[i].to,1-color);
	return tf;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for (int i=1;i<=n;i++)
	{
		if (vis[i]==true) continue;
		sum[0]=sum[1]=0;
		if (dfs(i,0)==false)
		{
			printf("Impossible");
			return 0;
		}
		ans+=min(sum[0],sum[1]);
	}
	printf("%d",ans);
}
