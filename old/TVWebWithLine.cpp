#include <cstdio>
#include <cstring>
#define MAXN 3001
using namespace std;
int cnt_edge,head[MAXN];
int n,m,val[MAXN];
int f[MAXN][MAXN];
struct EDGE{
	int next,to,dis;
}edge[MAXN*2+5];
int max(int a,int b)
{
	return a>b?a:b;
}
void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].next=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
int dp(int x)
{
	if (x>n-m)
	{
		f[x][1]=val[x];
		return 1;
	}
	int sum=0,t;
	for (int i=head[x];i!=0;i=edge[i].next)
	{
		int son=edge[i].to,dis=edge[i].dis;
		t=dp(son);
		sum+=t;
		for (int j=sum;j>=1;j--)
		{
			for (int k=1;k<=t;k++)
				if (j>=k)
					f[x][j]=max(f[x][j],f[x][j-k]+f[son][k]-dis);
		}
	}
	return sum;
}
int main()
{
	memset(f,0xcf,sizeof(f));	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n-m;i++)
	{
		int k; scanf("%d",&k);
		for (int j=1;j<=k;j++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			add(i,a,b);
		}
	}
	for (int i=n-m+1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		val[i]=temp;
	}
	for (int i=1;i<=n;i++)
		f[i][0]=0;
	dp(1);
	for (int i=m;i>=1;i--)
		if (f[1][i]>=0)
		{
			printf("%d",i);
			return 0;
		}
}
//LGOJ https://www.luogu.org/problemnew/show/P1273
//DHOJ http://47.104.154.247/problem.php?cid=1091&pid=8
