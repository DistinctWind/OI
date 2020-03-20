#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int mod=10007;
const int MAXN=60;
const int MAXL=101;
const int MAXP=MAXN*MAXL;
int n,m,tot=1,t[MAXP][26],p[MAXP],f[MAXP][MAXP],ans;
char tmp[MAXL];
bool end[MAXP];
inline void insert(char *s)
{
	int u=1,len=strlen(s);
	for (int i=0;i<len;i++)
	{
		int now=s[i]-'A';
		if (!t[u][now]) t[u][now]=++tot;
		u=t[u][now];
	}
	end[u]=true;
}
inline void setup()
{
	for (int i=0;i<26;i++)
		t[0][i]=1;
	queue <int> q;
	q.push(1);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (int i=0;i<26;i++)
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
int pow_plus(int a,int b,int c)
{
    int res=1;
    a%=c;
    while (b)
    {
        if (b&1)
            res=(res*a)%c;
        b>>=1;
        a=(a*a)%c;
    }
    return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf(" %s",tmp);
		insert(tmp);
	}
	setup();
	f[0][1]=1;
	for (int i=0;i<m;i++)
	{
		for (int j=1;j<=tot;j++)
		{
			for (int k=0;k<26;k++)
			{
				if (!end[t[j][k]]) 
					f[i+1][t[j][k]]=(f[i+1][t[j][k]]+f[i][j])%mod;
			}
		}
	}
	ans=pow_plus(26,m,mod);
	for (int i=1;i<=tot;i++)
		ans=(ans-f[m][i]+mod)%mod;
	printf("%d",ans);
}
//LOJ https://loj.ac/problem/10063
//LGOJ https://www.luogu.org/problemnew/show/P4052
