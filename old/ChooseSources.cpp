#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 301
using namespace std;
int f[MAXN][MAXN],s[MAXN];
int n,m;
vector <int> son[MAXN];
void dp(int x)
{
	f[x][0]=0;
	for (int i=0;i<son[x].size();i++)
	{
		int y=son[x][i];
		dp(y);
		for (int t=m;t>=0;t--)
			for (int j=t;j>=0;j--)
				f[x][t]=max(f[x][t],f[x][t-j]+f[y][j]);
	}
	if (x!=0)
		for (int t=m;t>0;t--)
			f[x][t]=f[x][t-1]+s[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		son[a].push_back(i);
		s[i]=b;
	}
	memset(f,0xcf,sizeof(f));
	dp(0);
	printf("%d",f[0][m]);
}
