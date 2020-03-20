#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int n,m,v[MAXN];
int cntEdge,head[MAXN],nxt[MAXN<<1],ver[MAXN<<1];
char tpe[2];
ll sum1,sum2,res,ans;
int state[MAXN];
bool vis[MAXN];
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
bool check(int x,int fa)
{
	bool tmp=true;
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (y==fa) continue;
		if (vis[x]==vis[y]&&vis[x]==false) return false;
		tmp=tmp&&check(y,x);
	}
	return tmp;
}
void dfs(int x)
{
	if (x==n+1)
	{
		if (check(1,0)) ans=min(ans,res);
		return;
	}
	if (res>ans) return;
	if (state[x]==1)
	{
		res+=v[x]; vis[x]=true;
		dfs(x+1);
		res-=v[x]; vis[x]=false;
	}
	else if (state[x]==2)
	{
		dfs(x+1);
	}
	else
	{
		dfs(x+1);
		res+=v[x]; vis[x]=true;
		dfs(x+1);
		res-=v[x]; vis[x]=false;
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d %s",&n,&m,tpe);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		if (i&1) sum1+=v[i];
		else sum2+=v[i];
	}
	for (int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (int i=1,a,x,b,y;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&x,&b,&y);
		if (tpe[0]=='A')
		{
			if (x==0&&y==0)
			{
				if ((a&1)==(b&1))
				{
					if (a&1) printf("%lld\n",sum2);
					else printf("%lld\n",sum1);
				}
				else printf("-1\n");
			}
			else if (x==0&&y==1)
			{
				if ((a&1)==(b&1)) printf("-1\n");
				else
				{
					if (b&1) printf("%lld\n",sum1);
					else printf("%lld\n",sum2);
				}
			}
			else if (x==1&&y==0)
			{
				if ((a&1)==(b&1)) printf("-1\n");
				else
				{
					if (a&1) printf("%lld\n",sum1);
					else printf("%lld\n",sum2);
				}
			}
			else
			{
				if ((a&1)==(b&1))
				{
					if (a&1) printf("%lld\n",sum1);
					else printf("%lld\n",sum2);
				}
				else printf("-1\n");
			}
		}
		else
		{
			res=0;
			ans=0x3f3f3f3f;
			state[a]=(x?1:2);
			state[b]=(y?1:2);
			dfs(1);
			state[a]=state[b]=0;
			if (ans==0x3f3f3f3f) printf("-1\n");
			else printf("%lld\n",ans);
		}
	}
}
