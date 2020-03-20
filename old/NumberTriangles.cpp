#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=1e3+1;
int f[MAXN][MAXN];
int map[MAXN][MAXN];
int n,ans;
inline void dp()
{
	f[1][1]=map[1][1];
	for (int i=2;i<=n;i++)
		for (int j=1;j<=i;j++)
			f[i][j]=max(f[i-1][j]+map[i][j],f[i-1][j-1]+map[i][j]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			scanf("%d",&map[i][j]);
	dp();
	for (int i=1;i<=n;i++)
		ans=max(f[n][i],ans);
	printf("%d",ans);
}
