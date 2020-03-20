#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=10010;
int n;
int h[MAXN],f[MAXN][2],fa[MAXN];
int cntEdge,head[MAXN],nxt[MAXN<<1],ver[MAXN<<1];
bool vis[MAXN];
inline void add(int from,int to){
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
inline int solve(int x){
	vis[x]=true;
	for (int i=head[x],y;i;i=nxt[i]){
		y=ver[i];
		if (vis[y]) continue;
		solve(y);
		f[x][0]+=max(f[y][0],f[y][1]);
		f[x][1]+=f[y][0];
	}
	f[x][1]+=h[x];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		fa[i]=i,scanf("%d",&h[i]);
	int a,b;
	while (scanf("%d%d",&a,&b),(a!=0&&b!=0))
	{
		fa[a]=b;
		add(a,b); add(b,a);
	}
	int start=n;
	while (fa[start]!=start)
		start=fa[start];
	solve(start);
	printf("%d",max(f[start][0],f[start][1]));
}
//DHOJ http://47.104.154.247/problem.php?cid=1091&pid=0
//LGOJ https://www.luogu.org/problemnew/show/P1352
