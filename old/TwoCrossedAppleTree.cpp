#include <cstdio>
#define MAXN 105
using namespace std;
int n,q;
int map[MAXN][MAXN],a[MAXN],l[MAXN],r[MAXN],f[MAXN][MAXN];
void setup()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			map[i][j]=-1;
}
int max(int a,int b)
{
	return a>b?a:b;
}
void makeTree(int now)
{
	for (int i=1;i<=n;i++)
		if (map[now][i]>=0)
		{
			l[now]=i; a[i]=map[now][i];
			map[now][i]=map[i][now]=-1;
			makeTree(i);
			break;
		}
	for (int i=1;i<=n;i++)
		if (map[now][i]>=0)
		{
			r[now]=i; a[i]=map[now][i];
			map[now][i]=map[i][now]=-1;
			makeTree(i);
			break;
		}
}
int dp(int i,int j)
{
	if (j==0) return 0;
	if ((l[i]==0)&&(r[i]==0)) return a[i];
	if (f[i][j]>0) return f[i][j];
	for (int k=0;k<=j-1;k++)
		f[i][j]=max(f[i][j],dp(l[i],k)+dp(r[i],j-k-1)+a[i]);
	return f[i][j];
}
int main()
{
	scanf("%d%d",&n,&q);
	setup();
	for (int i=1;i<=n-1;i++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		map[a][b]=map[b][a]=dis;
	}
	makeTree(1);
	int ans=dp(1,q+1);
	printf("%d",ans);
}
