#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=40;
const int MAXM=40;
const int inf=0x3f3f3f3f;
const int mov_x[4]={-1,0,1,0};
const int mov_y[4]={0,1,0,-1};
int n,m,q,map[MAXN][MAXM];
int ex,ey,sx,sy,tx,ty,d[50006];
bool ok[MAXN][MAXM][5],vis[MAXN][MAXM],v[50006];
int head[50006],cnt_edge;
struct Edge{
	int nxt,to,dis;
}edge[50006];
struct State{
	int x,y,step;
};
bool f;
bool judge(int x,int y)
{
	if (!(1<=x&&x<=n&&1<=y&&y<=m)) return false;
	return map[x][y];
}
int getnum(int x,int y,int dir)
{
	return 4*((x-1)*m+y)+dir;
}
inline void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].nxt=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
inline int bfs(int ei,int ej,int si,int sj,int ti,int tj)
{
	queue <State> q;
	State start;
	start.x=si,start.y=sj,start.step=0;
	memset(vis,0,sizeof(vis));
	vis[si][sj]=true;
	q.push(start);
	while (!q.empty())
	{
		State h=q.front(); q.pop();
		if (h.x==ti&&h.y==tj) return h.step;
		for (int i=0;i<4;i++)
		{
			if (!ok[h.x][h.y][i]) continue;
			int ni=h.x+mov_x[i],nj=h.y+mov_y[i];
			if (ni==ei&&nj==ej) continue;
			if (vis[ni][nj]) continue;
			vis[ni][nj]=true;
			State tmp;
			tmp.x=ni,tmp.y=nj,tmp.step=h.step+1;
			//if (tmp.x==ti&&tmp.y==tj) return tmp.step;
			q.push(tmp);
		}
	}
	return inf;
}
inline void init()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (!map[i][j]) continue;
			for (int k=0;k<4;k++)
			{
				int ni=i+mov_x[k],nj=j+mov_y[k];
				if (!judge(ni,nj)) continue;
				ok[i][j][k]=true;
			}
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=0;k<4;k++)
				for (int l=k+1;l<4;l++)
				{
					if (!(ok[i][j][k]&&ok[i][j][l])) continue;
					int a1=i+mov_x[k],b1=j+mov_y[k];
					int a2=i+mov_x[l],b2=j+mov_y[l];
					int w=bfs(i,j,a1,b1,a2,b2);
					if (w==inf) continue;
					int n1=getnum(i,j,k),n2=getnum(i,j,l);
					add(n1,n2,w); add(n2,n1,w);	
				}
	for (int i=1;i<=n;i++)
		for (int j=1;j<m;j++)
			if (ok[i][j][1]&&ok[i][j+1][3])
			{
				int n1=getnum(i,j,1),n2=getnum(i,j+1,3);
				add(n1,n2,1); add(n2,n1,1);
			}
	for (int i=1;i<n;i++)
		for (int j=1;j<=m;j++)
			if (ok[i][j][2]&&ok[i+1][j][0])
			{
				int n1=getnum(i,j,2),n2=getnum(i+1,j,0);
				add(n1,n2,1); add(n2,n1,1);
			}
}
queue <int> Q;
inline void solve()
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	for (int i=0;i<4;i++)
	{
		if (!ok[sx][sy][i]) continue;
		int tsx=sx+mov_x[i],tsy=sy+mov_y[i];
		int w=bfs(sx,sy,ex,ey,tsx,tsy);
		if (w==inf) continue;
		int num=getnum(sx,sy,i);
		d[num]=w;
		v[num]=true;
		Q.push(num);
	}
	while (!Q.empty())
	{
		int h=Q.front(); Q.pop();
		v[h]=false;
		for (int i=head[h];i;i=edge[i].nxt)
		{
			if (d[edge[i].to]>d[h]+edge[i].dis)
			{
				d[edge[i].to]=d[h]+edge[i].dis;
				if (!v[edge[i].to])
				{
					v[edge[i].to]=true;
					Q.push(edge[i].to);
				}
			}
		}
	}
	int ans=inf;
	for (int i=0;i<4;i++)
	{
		if (!ok[tx][ty][i]) continue;
		ans=min(ans,d[getnum(tx,ty,i)]);
	}
	if (ans==inf) printf("-1\n");
	else printf("%d\n",ans);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
	init();
	while (q--)
	{
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		if (!map[sx][sy]) {printf("-1\n");continue;}
		if (!map[tx][ty]) {printf("-1\n");continue;}
		if (sx==tx&&sy==ey) {printf("0\n");continue;}
		solve();
	}
}
