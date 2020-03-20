#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=3900;
int n,b,u[MAXN],ans;
int f[MAXN][MAXN][2];
inline void solve()
{
	memset(f,0xcf,sizeof(f));
	f[1][0][0]=f[1][1][1]=0;
	for (int i=2;i<=n;i++)
		for (int j=1;j<=min(i,b);j++)
		{
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
			f[i][j][1]=max(f[i-1][j-1][0],f[i-1][j-1][1]+u[i]);
		}
	ans=max(f[n][b][0],f[n][b][1]);
	memset(f,0xcf,sizeof(f));
	f[1][1][1]=u[1];
	for (int i=2;i<=n;i++)
		for (int j=1;j<=min(i,b);j++)
		{
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
			f[i][j][1]=max(f[i-1][j-1][0],f[i-1][j-1][1]+u[i]);
		}
	ans=max(ans,f[n][b][1]);
	printf("%d",ans);
}
int main()
{
	
}
