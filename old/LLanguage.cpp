#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=1024*1024+10;
int n,m,tot=1,ans;
int tree[MAXN][26],len;
bool end[MAXN],v[MAXN];
char a[MAXN];
inline void insert()
{
	int len=strlen(a);
	int u=1;
	for (int i=0;i<len;i++)
	{
		int now=a[i]-'a';
		if (tree[u][now]==0) tree[u][now]=++tot;
		u=tree[u][now];
	}
	end[u]=true;
}
void dfs(int pos)
{
	if (v[pos]) return;
	v[pos]=true;
	if (pos>ans) ans=pos; 
	int i=pos,u=1;
	while (i<len)
	{
		if (tree[u][a[i]-'a']!=0)
		{
			u=tree[u][a[i]-'a'],i++;
			if (end[u]) dfs(i);
		}
		else break;
	}
}
/*bool dfs(int pos,bool start)
{
	int u=1;
	for (int i=pos;i<len;i++)
	{
		int now=a[i]-'a';
		if (tree[u][now]!=0) u=tree[u][now];
		else
		{
			if (start==false) return false;
			if (dfs(i,false)) return true;
			else return false;
		}
		if (end[u]) ans=max(ans,i);
	}
	return true;
}*/
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf(" %s",a);
		insert();
	}
	for (int i=1;i<=m;i++)
	{
		ans=0; memset(v,0,sizeof(v));
		scanf(" %s",a);
		len=strlen(a);
		dfs(0);
		printf("%d\n",ans);
	}
}
//LOJ https://loj.ac/problem/10053
