#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=110;
const int MAXM=1e5+10;
bool f[MAXM];
int n,m;
int used[MAXM],a[MAXN],c[MAXN],ans;
inline void solve()
{
	f[0]=true;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=m;j++) used[j]=0;
		for (int j=a[i];j<=m;j++)
			if (!f[j]&&f[j-a[i]]&&used[j-a[i]]<c[i])
				f[j]=true,used[j]=used[j-a[i]]+1;
	}
	for (int i=1;i<=m;i++)
		if (f[i]) ans++;
}
int main()
{
	while (scanf("%d%d",&n,&m),n!=0&&m!=0)
	{
		memset(f,0,sizeof(f));
		memset(used,0,sizeof(used));
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		ans=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&c[i]);
		solve();
		printf("%d\n",ans);
	}
}
