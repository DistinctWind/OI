#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN=1001;
const int MAXM=21;
int n,m,c[MAXM],s,f[MAXN][MAXM];
struct state{
	int dep,pos;
};
bool vis[MAXN][MAXM];
int abs(int x)
{
	return x<0?-x:x;
}
inline void spfa()
{
	memset(f,0x3f,sizeof(f));
	queue <state> q;
	state start;
	start.dep=1,start.pos=s;
	f[1][s]=0;
	vis[1][s]=true;
	q.push(start);
	while (!q.empty())
	{
		state h=q.front(); q.pop();
		vis[h.dep][h.pos]=false;
		//printf("***At %d,%d\n",h.dep,h.pos);
		for (int i=1;i<=m;i++)
		{
			if (1<=h.dep+c[i]&&h.dep+c[i]<=n&&f[h.dep+c[i]][i]>f[h.dep][h.pos]+abs(c[i])*2+abs(i-h.pos))
			{
				f[h.dep+c[i]][i]=f[h.dep][h.pos]+abs(c[i])*2+abs(i-h.pos);
				//printf("vis %d,%d\n",h.dep+c[i],i);
				if (!vis[h.dep+c[i]][i])
				{
					q.push(state{h.dep+c[i],i});
					vis[h.dep+c[i]][i]=true;
				}
			}
			/*if (f[h.dep][i]>f[h.dep][h.pos]+abs(i-h.pos))
			{
				f[h.dep][i]=f[h.dep][h.pos]+abs(i-h.pos);
				if (!vis[h.dep][i])
				{
					vis[h.dep][i]=true;
					q.push(state{h.dep,i});
				}
			}*/
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&c[i]);
		if (c[i]==0) s=i;
	}
	spfa();
	int ans=0x3f3f3f3f;
	for (int i=1;i<=m;i++)
		ans=min(ans,f[n][i]);
	if (ans==0x3f3f3f3f) printf("-1");
	else printf("%d\n",ans);
}
