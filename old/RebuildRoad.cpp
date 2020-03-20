#include <cstdio>
#include <cstring>
#include <limits.h>
#define MAXN 151
using namespace std;
int cnt_edge,head[MAXN];
int n,p,max_cut;
int f[MAXN][MAXN],cnt[MAXN];
bool GF[MAXN];
struct EDGE{
	int next,to;
}edge[MAXN*2+5];
int min(int a,int b)
{
	return a>b?b:a;
}
void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].next=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
}
void dp(int u,int root)
{
	f[u][1]=cnt[u];
	for (int i=head[u];i!=0;i=edge[i].next)
	{
		int son=edge[i].to;
		if (son!=root)
		{
			dp(son,u);
			for (int j=p;j>=1;j--)
				for (int k=1;k<j;k++)
					f[u][j]=min(f[u][j],f[u][k]+f[son][j-k]-2);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&p);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b); add(b,a);
		cnt[a]++; cnt[b]++;
	}
	memset(f,0x3f,sizeof(f));
	dp(1,0);
	int ans=INT_MAX;
	for (int i=1;i<=n;i++)
		ans=min(ans,f[i][p]);
	printf("%d",ans);
}
//LGOJ https://www.luogu.org/problemnew/show/P1272
//DHOJ http://47.104.154.247/problem.php?cid=1091&pid=7
