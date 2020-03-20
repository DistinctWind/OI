#include <cstdio>
#include <cstring> 
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN=501,MAXM=501;
const int mov_x[4]={-1,0,1,0};
const int mov_y[4]={0,1,0,-1};
struct Range{
	int l,r,pos;
	bool operator < (const Range &a) const{
		if (l==a.l) return (r-l+1)>(a.r-a.l+1);
		else return l<a.l;
	}
}range[MAXM];
struct state{
	int x,y;
};
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int h[MAXN][MAXM],l[MAXN][MAXM],r[MAXN][MAXM];
bool vis[MAXN][MAXM];
int n,m,cnt;
void dfs(int x,int y)
{
	vis[x][y]=true;
	for (int i=0;i<4;i++)
	{
		int now_x=x+mov_x[i];
		int now_y=y+mov_y[i];
		if (1<=now_x&&now_x<=n&&1<=now_y&&now_y<=m)
		{
			if (h[x][y]<=h[now_x][now_y]) continue;
			if (!vis[now_x][now_y]) dfs(now_x,now_y);
			l[x][y]=min(l[x][y],l[now_x][now_y]);
			r[x][y]=max(r[x][y],r[now_x][now_y]);
		}
	}
}
int main()
{
	//freopen("flow.in","r",stdin);
	//freopen("flow.out","w",stdout);
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&h[i][j]);
	memset(l,0x3f,sizeof(l));
	for (int i=1;i<=m;i++)
		l[n][i]=r[n][i]=i;
	for (int i=1;i<=m;i++)
		if (!vis[1][i])
			dfs(1,i);
	for (int i=1;i<=m;i++)
		if (!vis[n][i])
			cnt++;
	if (cnt>0)
	{
		printf("0\n%d\n",cnt);
		return 0;
	}
	int left=1;
	while (left<=m)
	{
		int maxr=0;
		for (int i=1;i<=m;i++)
			if (l[1][i]<=left)
				maxr=max(maxr,r[1][i]);
		cnt++;
		left=maxr+1;
	}
	printf("1\n%d\n",cnt);
}
