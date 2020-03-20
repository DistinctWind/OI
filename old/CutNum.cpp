#include <cstdio>
using namespace std;
const int MAXN=201;
int n,m,a[MAXN];
long long ans;
void dfs(int k)
{
	if (n==0) return;
	if (k==m)
	{
		if (n>=a[k-1]) ans++;
		return;
	}
	for (int i=a[k-1];i<=n/(m-k+1);i++)
	{
		a[k]=i;
		n-=i;
		dfs(k+1);
		n+=i;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	a[0]=1;
	dfs(1);
	printf("%lld\n",ans);
}
