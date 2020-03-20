#include <cstdio>
using namespace std;
const int MAXN=5001;
int a[MAXN],b[MAXN];
int n,d,m,f[MAXN][MAXN],ans;
int max(int a,int b)
{
	return a>b?a:b;
}
inline void dp()
{
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++)
			f[i][j]=-1;
	ans=f[1][0]=a[1];
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			for (int k=i-1;k>=1;k--)
			{
				if (b[i]-b[k]>d) break;
				if (f[k][j-1]==-1) continue;
				f[i][j]=max(f[i][j],f[k][j-1]);
			}
			if (f[i][j]!=-1) f[i][j]+=a[i];
			ans=max(f[i][j],ans);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&d,&m);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	dp();
	printf("%d",ans);
}
//DHOJ http://47.104.154.247/problem.php?cid=1100&pid=5
