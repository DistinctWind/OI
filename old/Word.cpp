#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXL=1e6+1;
int end[MAXL];
char tmp[MAXL];
int n,t[MAXL][26],p[MAXL],tot=1;
int q[MAXL],wei[MAXL];
inline void insert(char *s,int x)
{
	int u=1,len=strlen(s);
	for (int i=0;i<len;i++)
	{
		int now=s[i]-'a';
		if (!t[u][now]) t[u][now]=++tot;
		u=t[u][now];
		wei[u]++;
	}
	end[x]=u;
}
inline void setup()
{
	for (int i=0;i<26;i++)
		t[0][i]=1;
	q[1]=1;
	for (int head=1,tail=1;head<=tail;head++)
	{
		int u=q[head];
		for (int i=0;i<26;i++)
		{
			if (!t[u][i]) t[u][i]=t[p[u]][i];
			else
			{
				q[++tail]=t[u][i];
				int v=p[u];
				while (v>0&&!t[v][i]) v=p[v];
				p[t[u][i]]=t[v][i];
			}
		}
	}
}
inline void bfs()
{
	for (int u=tot;u>=0;u--)
		wei[p[q[u]]]+=wei[q[u]];
	for (int i=1;i<=n;i++)
		printf("%d\n",wei[end[i]]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf(" %s",tmp);
		insert(tmp,i);
	}
	setup();
	bfs();
}
//LOJ https://loj.ac/problem/10060
//LGOJ https://www.luogu.org/problemnew/show/P3966
