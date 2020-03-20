#include <cstdio>
#include <cstring>
using namespace std;
const int MAXP=5e5+1;
const int MAXM=1e6+1;
const int MAXL=51;
int t,n,ans,tot=1,end[MAXP],p[MAXP*2],q[MAXP],tree[MAXP][26];
char tmp[MAXM];
inline void add()
{
	int len=strlen(tmp),u=1;
	for (int i=0;i<len;i++)
	{
		int now=tmp[i]-'a';
		if (!tree[u][now]) tree[u][now]=++tot;
		u=tree[u][now];
	}
	end[u]++;
}
inline void setup()
{
	for (int i=0;i<=25;i++)
		tree[0][i]=1;
	q[1]=1; p[1]=0;
	for (int q1=1,q2=1;q1<=q2;q1++)
	{
		int u=q[q1];
		for (int i=0;i<=25;i++)
		{
			if (!tree[u][i]) tree[u][i]=tree[p[u]][i];
			else 
			{
				q[++q2]=tree[u][i];
				int v=p[u];
				while (v>0&&!tree[v][i]) v=p[v];
				p[tree[u][i]]=tree[v][i];
			}
		}
	}
}
inline void find()
{
	int u=1,len=strlen(tmp);
	for (int i=0;i<len;i++)
	{
		int now=tmp[i]-'a';
		int v=tree[u][now];
		while (v>1)
		{
			ans+=end[v];
			end[v]=0;
			v=p[v];
		}
		u=tree[u][now];
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while (t--)
	{
		ans=0; memset(tree,0,sizeof(tree)); memset(end,0,sizeof(0));
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf(" %s",tmp);
			add();
		}
		setup();
		scanf(" %s",tmp);
		find();
		printf("%d\n",ans);
	}
}
