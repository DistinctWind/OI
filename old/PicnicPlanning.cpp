#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;
const string p="Park";
const int MAXM=100001;
int s,n,cnt,c,blo,fa[MAXM],ans=0x7fffffff;
int vec[MAXM];
struct Edge{
	int u,v,dis;
	bool able;
}edge[MAXM];
map <string,int> m;
int find(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline void setup()
{
	for (int i=1;i<=cnt;i++)
		fa[i]=i;
}
bool cmp(Edge a,Edge b)
{
	return a.dis<b.dis;
}
int min(int a,int b)
{
	return a<b?a:b;
}
inline void kruskal()
{
	int res=0;
	setup();
	for (int i=1;i<=n;i++)
	{
		if (!edge[i].able) continue;
		int x=find(edge[i].u);
		int y=find(edge[i].v);
		if (x==y) continue;
		fa[x]=y;
		res+=edge[i].dis;
	}
	int f=find(1);
	for (int i=1;i<=cnt;i++)
		if (f!=find(i))
			return;
	ans=min(ans,res);
}
/*inline void kruskal(int limit)
{
    int vis[MAXM*2];
    int sum=0,C=0;
    for (int i=1;i<=cnt;++i) fa[i]=i,vis[i]=0;
    for (int i=1;i<=n;++i)
    {
        if (!edge[i].able) continue;
        int r1=find(edge[i].u);
        int r2=find(edge[i].v);
        C+=(vis[edge[i].u]==0); C+=(vis[edge[i].v]==0);
        vis[edge[i].u]=vis[edge[i].v]=1;
        if (r1==r2) continue;
        fa[r2]=r1;
        sum+=edge[i].dis;
    }
    if (C!=cnt) return;
    ans=min(ans,sum);
    return;
}*/
int limit;
void dfs(int dep,int last)
{
	if (dep==c-limit)
	{
		kruskal();
		return;
	}
	for (int i=last;i<=c;i++)
	{
		edge[vec[i]].able=false;
		dfs(dep+1,i+1);
		edge[vec[i]].able=true;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//clock_t start,end;
	scanf("%d",&n);
	m[p]=1; cnt=1;
	for (int i=1;i<=n;i++)
	{
		string a,b;
		int dis;
		cin>>a>>b>>dis;
		if (m.find(a)==m.end()) m[a]=++cnt;
		if (m.find(b)==m.end()) m[b]=++cnt;
		if (a==p||b==p)
			edge[i].u=m[a],edge[i].v=m[b],edge[i].dis=dis,edge[i].able=false;
		else
			edge[i].u=m[a],edge[i].v=m[b],edge[i].dis=dis,edge[i].able=true;
	}
	setup();
	int maxb;
	scanf("%d",&maxb);
	sort(edge+1,edge+1+n,cmp);
	for (int i=1;i<=n;i++)
		if (edge[i].able==false)
			vec[++c]=i,edge[i].able=true;
	//start=clock();
	limit=min(c,maxb);
	dfs(0,1);
	//end=clock();
	printf("Total miles driven: %d\n",ans);
	//printf("%.3lf",(double)(end-start)/CLOCKS_PER_SEC);
}
