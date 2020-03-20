#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXL=30001;
int n,tot=1,t[MAXL][2],p[MAXL];
char tmp[MAXL];
bool end[MAXL],vis[MAXL],his[MAXL];
inline void insert(char *s)
{
	int u=1,len=strlen(s);
	for (int i=0;i<len;i++)
	{
		int now=s[i]-'0';
		if (!t[u][now]) t[u][now]=++tot;
		u=t[u][now];
	}
	end[u]=true;
}
inline void setup()
{
	queue <int> q;
	for (int i=0;i<2;i++)
		t[0][i]=1;
	q.push(1);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (int i=0;i<2;i++)
		{
			if (!t[u][i]) t[u][i]=t[p[u]][i];
			else
			{
				q.push(t[u][i]);
				int v=p[u];
				while (v>0&&!t[v][i]) v=p[v];
				p[t[u][i]]=t[v][i];
				end[t[u][i]]|=end[t[v][i]];
			}
		}
	}
}
void dfs(int x)
{
	if (vis[x])
	{
		printf("TAK");
		exit(0);
	}
	if (his[x]||end[x]) return;
	vis[x]=his[x]=true;
	dfs(t[x][0]);
	dfs(t[x][1]);
	vis[x]=false;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf(" %s",tmp);
		insert(tmp);
	}
	setup();
	dfs(1);
	printf("NIE");
}
//LOJ https://loj.ac/problem/10062
//LGOJ https://www.luogu.org/problemnew/show/P2444
