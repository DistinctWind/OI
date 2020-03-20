#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL=1e7+1;
const int MAXM=1e5+1;
const int MAXTL=1e2+1;
char s[MAXL],tmp[MAXTL];
int n,m,tot=1,t[MAXL][4],f[MAXL],poi[MAXL],q[MAXL],re[MAXL],l[MAXM],p[MAXL];
int calc(char a)
{
	switch (a)
	{
		case 'E' : return 0; break;
		case 'S' : return 1; break;
		case 'W' : return 2; break;
		case 'N' : return 3; break;
	}
}
inline void insert(char *s,int x)
{
	int u=1,len=strlen(s);
	for (int i=0;i<len;i++)
	{
		int now=calc(s[i]);
		if (!t[u][now]) t[u][now]=++tot,f[tot]=u;
		u=t[u][now];
	}
	poi[x]=u;
}
inline void setup()
{
	q[1]=1;
	for (int q1=1,q2=1;q1<=q2;q1++)
	{
		int u=q[q1];
		for (int i=0;i<=3;i++)
		{
			if (!t[u][i]) t[u][i]=t[p[u]][i];
			else 
			{
				q[++q2]=t[u][i];
				int v=p[u];
				while (v>0&&!t[v][i]) v=p[v];
				p[t[u][i]]=t[v][i];
			}
		}
	}
}
inline void solve()
{
	int u=1;
	for (int i=0;i<n;i++)
	{
		int now=calc(s[i]);
		u=t[u][now];
		for (int j=u;j!=0;j=p[j])
		{
			if (re[j])
				break;
			else 
				re[j]=1;
		}
	}
}
int getans(int x)
{
	int u=poi[x],ans=l[x];
	for (int i=u;i!=0;i=f[i])
	{
		if (re[i]) return ans;
		else ans--;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	scanf(" %s",s);
	for (int i=1;i<=m;i++)
	{
		scanf(" %s",tmp);
		l[i]=strlen(tmp);
		insert(tmp,i);
	}
	for (int i=0;i<=3;i++)
		t[0][i]=1;
	setup();
	solve();
	for (int i=1;i<=m;i++)
	{
		printf("%d\n",getans(i));
	}
}
//LOJ https://loj.ac/problem/10058
//LGOJ https://www.luogu.org/problemnew/show/P5231
