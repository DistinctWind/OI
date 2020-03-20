#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXL=1e6+1;
int e[MAXL],t[MAXL][26],p[MAXL],tot=1,n,ans;
char tmp[MAXL];
inline void insert()
{
	int u=1,len=strlen(tmp);
	for (int i=0;i<len;i++)
	{
		int now=tmp[i]-'a';
		if (!t[u][now]) t[u][now]=++tot;
		u=t[u][now];
	}
	e[u]++;
}
inline void setup()
{
	for (int i=0;i<=25;i++)
		t[0][i]=1;
	queue <int> q;
	q.push(1);
	while (!q.empty())
	{
		int u=q.front(); q.pop();
		for (int i=0;i<26;i++)
		{
			if (!t[u][i]) t[u][i]=t[p[u]][i];
			else
			{
				q.push(t[u][i]);
				int v=p[u];
				while (v>0&&!t[v][i]) v=p[v];
				p[t[u][i]]=t[v][i];
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf(" %s",tmp);
		insert();
	}
	setup();
	scanf(" %s",tmp);
	int len=strlen(tmp),u=1;
	for (int i=0;i<len;i++)
	{
		int now=tmp[i]-'a';
		int k=t[u][now];
		while (k>1&&e[k]!=0)
		{
			ans+=e[k];
			e[k]=0;
			k=p[k];
		}
		u=t[u][now];
	}
	printf("%d",ans);
}
