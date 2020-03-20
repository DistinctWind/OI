#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=1e5+1;
int n,tot=1,a[MAXN],d[32];
int tree[MAXN*100][2],ans;
inline void divide(int x)
{
	for (int i=0;i<=31;i++)
	{
		d[i]=x%2;
		x=x>>1;
	}
}
inline void insert()
{
	int u=1;
	for (int i=31;i>=0;i--)
	{
		if (tree[u][d[i]]==0) tree[u][d[i]]=++tot;
		u=tree[u][d[i]]; 
	}
}
void dfs(int pos,int num,int res)
{
	if (pos==-1)
		ans=max(ans,res);
	if (tree[num][!d[pos]]!=0)
		dfs(pos-1,tree[num][!d[pos]],(res<<1)+1);
	else if (tree[num][d[pos]]!=0)
		dfs(pos-1,tree[num][d[pos]],res<<1);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		divide(a[i]);
		insert();
		dfs(31,1,0);
	}
	printf("%d",ans);
}
//LOJ https://loj.ac/problem/10050
