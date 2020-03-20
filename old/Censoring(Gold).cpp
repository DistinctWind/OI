#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL=1e5+1;
char s[MAXL],tmp[MAXL];
int n,tot=1,t[MAXL*26][26],q[MAXL*26],p[MAXL*26],top,stack[MAXL],f[MAXL*26];
int end[MAXL*26];
inline void insert(char *x)
{
	int len=strlen(x),u=1;
	for (int i=0;i<len;i++)
	{
		int now=x[i]-'a';
		if (!t[u][now]) t[u][now]=++tot;
		u=t[u][now];
	}
	end[u]=len;
}
inline void setup()
{
	for (int i=0;i<26;i++)
		t[0][i]=1;
	q[1]=1; p[1]=0;
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
			}
		}
	}
}
inline void solve()
{
	int len=strlen(s),u=1;
	for (int i=0;i<len;i++)
	{
		int now=s[i]-'a';
		stack[++top]=i;
		u=t[u][now];
		f[top]=u;
		if (end[u])
		{
			top-=end[u];
			if (top==0)
				u=top;
			else 
				u=f[top];
		}
	}
	for (int i=1;i<=top;i++)
		putchar(s[stack[i]]);
	putchar('\n');
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf(" %s",s);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf(" %s",tmp);
		insert(tmp);
	}
	setup();
	solve();
}
//LOJ https://loj.ac/problem/10059
//LGOJ https://www.luogu.org/problemnew/show/P3121
