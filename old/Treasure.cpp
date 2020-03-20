#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN=14;
const int MAXM=1010;
int n,m,ans=0x3f3f3f3f;
int dis[MAXN][MAXN],tran[MAXN],raw[MAXN],cnt;
int f[1<<MAXN];
bool vis[MAXN];
int dfs(int s,int x,int step,int start)
{
	if (x==start) return step;
	int res=0x3f3f3f3f;
	vis[x]=true;
	for (int i=1;i<=n;i++)
	{
		if (dis[x][i]>=0x3f3f3f3f) continue;
		if (!((s>>(i-1))&1)) continue;
		if (vis[i]) continue;
		res=min(res,dfs(s,i,step+1,start));
	}
	vis[x]=false;
	return res;
}
inline int calc(int s,int x,int start)
{
	if (s==0) return 0;
	int res=0x3f3f3f3f;
	for (int i=1;i<=n;i++)
	{
		if (!((s>>(i-1))&1)) continue;
		if (dis[raw[i]][raw[x]]>=0x3f3f3f3f) continue;
		int tmp=dfs(s,raw[i],0,start);
		if (tmp>=0x3f3f3f3f) continue;
		res=min(res,dis[raw[i]][raw[x]]*(tmp+1));
	}
	return res;
}
inline int solve(int start)
{
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for (int i=0;i<(1<<n);i++)
	{
		for (int j=1;j<=n;j++)
		{
			if ((i>>(j-1))&1) continue;
			int tmp=calc(i,j,start);
			if (tmp<0||tmp>=0x3f3f3f3f) continue;
			f[i|(1<<(j-1))]=min(f[i|(1<<(j-1))],f[i]+tmp);
		}
	}
	//printf("%d\n",f[(1<<n)-1]);
	return f[(1<<n)-1];
}
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=n;i++)
		dis[i][i]=0;
	for (int i=1,a,b,c;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		dis[a][b]=dis[b][a]=min(dis[a][b],c);
	}
	for (int i=1;i<=n;i++)
	{
		cnt=0;
		queue <int> q;
		q.push(i);
		memset(vis,0,sizeof(vis)); vis[i]=true;
		memset(tran,0,sizeof(tran));
		memset(raw,0,sizeof(raw));
		while (!q.empty())
		{
			int x=q.front(); q.pop();
			cnt++;
			tran[x]=cnt,raw[cnt]=x;
			for (int y=1;y<=n;y++)
			{
				if (dis[x][y]>=0x3f3f3f3f) continue;
				if (vis[y]) continue;
				vis[y]=true;
				q.push(y);
			}
		}
		memset(vis,0,sizeof(vis));
		ans=min(ans,solve(i));
	}
	printf("%d",ans);
}
