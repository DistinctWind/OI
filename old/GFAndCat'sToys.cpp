#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=101;
int n,m;
int d[MAXN][MAXN];
int max(int a,int b)
{
	return a>b?a:b;
}
inline void floyd()
{
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	memset(d,0x3f,sizeof(d));
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		d[a][b]=d[b][a]=1;
	}
	floyd();
	int ans=-1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			ans=max(ans,d[i][j]);
	printf("%d",ans);
}
