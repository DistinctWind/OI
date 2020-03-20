#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXL=51;
const int MAXN=12;
int n,t[MAXL*MAXN][26],state[MAXL*MAXN],p[MAXL*MAXN],tot=1,q[MAXL*MAXN*2];
int f[MAXL*MAXN<<12],ans[MAXL*MAXN<<12],c[MAXL<<4];
bool vis[MAXL*MAXN][1<<MAXN];
char tmp[MAXL];
inline void setup()
{
	for (int i=0;i<26;i++)
		t[0][i]=1;
	q[1]=1;
	for (int q1=1,q2=1;q1<=q2;q1++)
	{
		int u=q[q1];
		for (int i=0;i<26;i++)
		{
			if (!t[u][i]) t[u][i]=t[p[u]][i];
			else
			{
				q[++q2]=t[u][i];
				int v=p[u];
				while (v>0&&!t[v][i]) v=p[v];
				p[t[u][i]]=t[v][i];
				state[t[u][i]]|=state[t[v][i]];
			}
		}
	}
}
inline void bfs()
{
	queue <int> q1,q2;
	q1.push(1); q2.push(0);
	vis[1][0]=true;
	int ti=0,cnt=0,nod=0;
	while (!q1.empty())
	{
		int u=q1.front(),s=q2.front();
		q1.pop(); q2.pop();
		if (s==((1<<n)-1))
		{
			while (ti!=0)
			{
				c[++nod]=ans[ti];
				ti=f[ti];
			}
			for (int i=nod;i>0;i--)
				putchar(c[i]+'A');
			return;
		}
		for (int i=0;i<26;i++)
		{
			if (!vis[t[u][i]][s|state[t[u][i]]])
			{
				vis[t[u][i]][s|state[t[u][i]]]=true;
				q1.push(t[u][i]);
				q2.push(s|state[t[u][i]]);
				f[++cnt]=ti;
				ans[cnt]=i;
			}
		}
		ti++;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	///freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf(" %s",tmp);
		int len=strlen(tmp),u=1;
		for (int j=0;j<len;j++)
		{
			int now=tmp[j]-'A';
			if (!t[u][now]) t[u][now]=++tot;
			u=t[u][now];
		}
		state[u]|=1<<(i-1);
	}
	setup();
	bfs();
}
//LOJ https://loj.ac/problem/10061
//LGOJ https://www.luogu.org/problemnew/show/P2322
