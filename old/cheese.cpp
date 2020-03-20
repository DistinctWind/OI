#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN=1010;
typedef long long ll;
struct Point{
	ll x,y,z;
}poi[MAXN];
int T,n;
int cntEdge,head[MAXN],nxt[MAXN*MAXN*2],ver[MAXN*MAXN*2];
ll h,r;
bool t[MAXN],vis[MAXN],res;
vector <int> s;
inline void add(int from,int to)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
}
bool dfs(int x)
{
	if (t[x]) return true;
	vis[x]=true;
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (vis[y]) continue;
		if (dfs(y))
		{
			vis[x]=false;
			return true;
		}
	}
	vis[x]=false;
	return false;
}
ll sdist(int a,int b)
{
	return (poi[a].x-poi[b].x)*(poi[a].x-poi[b].x)+(poi[a].y-poi[b].y)*(poi[a].y-poi[b].y)+(poi[a].z-poi[b].z)*(poi[a].z-poi[b].z);
}
inline void setup()
{
	cntEdge=0;
	memset(head,0,sizeof(head));
	memset(nxt,0,sizeof(nxt));
	memset(ver,0,sizeof(ver));
	memset(t,0,sizeof(t));
	s.clear();
	res=false;
}
int main()
{
	//freopen("cheese.in","r",stdin);
	//freopen("cheese.out","w",stdout);
	freopen("in.txt","r",stdin);
	scanf("%d",&T);
	while (T--)
	{
		setup();
		scanf("%d%lld%lld",&n,&h,&r);
		for (int i=1;i<=n;i++)
			scanf("%lld%lld%lld",&poi[i].x,&poi[i].y,&poi[i].z);
		for (int i=1;i<=n;i++)
		{
			if (poi[i].z<=r) s.push_back(i);
			if (poi[i].z>=h-r) t[i]=true;
			for (int j=i+1;j<=n;j++)
				if (sdist(i,j)<=4*r*r)
				{
					add(i,j);
					add(j,i);
				}
		}
		for (vector<int>::iterator i=s.begin();i!=s.end()&&!res;i++)
			res|=dfs(*i);
		if (res) printf("Yes\n");
		else printf("No\n");
	}
}
