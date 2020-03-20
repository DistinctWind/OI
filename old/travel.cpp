#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#define rint register int 
using namespace std;
const int MAXN=5010;
int n,m,cnt;
int xx[MAXN],yy[MAXN];
int pth[MAXN],tmp[MAXN];
int b[MAXN][MAXN];
bool vis[MAXN],jud[MAXN][MAXN];
set <int> s[MAXN];
inline void change()
{
	for (rint i=1;i<=n;i++)
		pth[i]=tmp[i];
}
void check()
{
	if (pth[1]==0) change();
	for (rint i=1;i<=n;i++)
		if (pth[i]>tmp[i])
		{
			change();
			break;
		}
		else if (pth[i]<tmp[i])
			break;
}
void dfs(int x,int fa)
{
	tmp[++cnt]=x;
	if (cnt==n)
	{
		check();
		return;
	}
	int y;
	for (set<int>::iterator i=s[x].begin();i!=s[x].end();i++)
	{
		y=*i;
		if (vis[y]||y==fa) continue;
		vis[y]=true;
		dfs(y,x);
	}
}
int read()
{
	int x=0; char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	n=read(); m=read();
	for (rint i=1;i<=m;i++)
	{
		xx[i]=read(); yy[i]=read();
		s[xx[i]].insert(yy[i]); s[yy[i]].insert(xx[i]);
	}
	if (m==n-1)
	{
		cnt=0;
		vis[1]=true;
		dfs(1,0);
	}
	else
	{
		for (rint i=1;i<=m;i++)
		{
			s[xx[i]].erase(s[xx[i]].lower_bound(yy[i]));
			s[yy[i]].erase(s[yy[i]].lower_bound(xx[i]));
			cnt=0;
			memset(vis,0,sizeof(vis));
			vis[1]=true;
			dfs(1,0);
			s[xx[i]].insert(yy[i]);
			s[yy[i]].insert(xx[i]);
		}
	}
	for (rint i=1;i<=n;i++)
		printf("%d ",pth[i]);
}
