#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL=1e6+1;
int n,m,len,ans,tot=1,t[MAXL][26];
char tmp[MAXL];
int e[MAXL];
inline void insert()
{
	len=strlen(tmp);
	int u=1;
	for (int i=0;i<len;i++)
	{
		int now=tmp[i]-'a';
		if (t[u][now]==0)
		{
			t[u][now]=++tot;
		}
		u=t[u][now];
	}
	e[u]++;
}
inline void query()
{
	len=strlen(tmp);
	int u=1;
	for (int i=0;i<len;i++)
	{
		int now=tmp[i]-'a';
		if (t[u][now]!=0)
		{
			if (e[u])
				ans+=e[u];
			u=t[u][now];
		}
		else break;
	}
	if (e[u])
		ans+=e[u];
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf(" %s",tmp);
		insert();
	}
	for (int i=1;i<=m;i++)
	{
		ans=0;
		scanf(" %s",tmp);
		query();
		printf("%d\n",ans);
	}
}
//DHOJ http://47.104.154.247/problem.php?cid=1125&pid=1
