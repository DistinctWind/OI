#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN=30;
char tmp[3][MAXN];
int n,list[MAXN],num[MAXN],f[3][MAXN],cnt;
bool vis[MAXN];
void check()
{
	int d=0;
	for (int i=1;i<=n;i++)
	{
		if ((num[f[0][i]]+num[f[1][i]]+d)%n!=num[f[2][i]]) return;
		d=(num[f[0][i]]+num[f[1][i]]+d)/n;
	}
	if (d!=0) return;
	for (int i=1;i<=n;i++)
		printf("%d ",num[i]);
	exit(0);
}
bool ok()
{
	if (num[f[0][n]]!=-1&&num[f[1][n]]!=-1)
		if (num[f[0][n]]+num[f[1][n]]>=n) return false;
	for (int i=1;i<=n;i++)
	{
		if (num[f[0][i]]==-1||num[f[1][i]]==-1||num[f[2][i]]==-1) continue;
		if ((num[f[0][i]]+num[f[1][i]])%n!=num[f[2][i]])
			if ((num[f[0][i]]+num[f[1][i]]+1)%n!=num[f[2][i]])
				return false;
	}
	return true;
}
void dfs(int pos)
{
	if (pos==n+1)
	{
		check();
		return;
	}
	for (int i=n-1;i>=0;i--)
	{
		if (!vis[i])
		{
			vis[i]=true;
			num[list[pos]]=i;
			if (ok())
				dfs(pos+1);
			num[list[pos]]=-1;
			vis[i]=false;
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=0;i<3;i++)
		scanf(" %s",tmp[i]+1);
	for (int i=0;i<3;i++)
	{
		for (int j=n;j>=1;j--)
		{
			f[i][j]=tmp[i][n-j+1]-'A'+1;
		}
	}
	for (int j=1;j<=n;j++)
		for (int i=0;i<3;i++)
			if (!vis[f[i][j]])
				{
					list[++cnt]=f[i][j];
					vis[f[i][j]]=true;
				}
	memset(vis,0,sizeof(vis));
	memset(num,0xff,sizeof(num));
	dfs(1);
}
//DHOJ http://47.104.154.247/problem.php?cid=1131&pid=5
//LGOJ https://www.luogu.org/problem/P1092
//VIJOS https://vijos.org/p/1099
//JOYOI http://www.joyoi.cn/problem/tyvj-1131
