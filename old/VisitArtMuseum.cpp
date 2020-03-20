#include <cstdio>
#define MAXN 11
using namespace std;
int tot,cnt;
int f[105][666];
int max(int a,int b)
{
	return a>b?a:b;
}
int dfs(int x)
{
	int l,v;
	int son=++cnt;
	scanf("%d%d",&l,&v);
	l*=2;
	if (v==0)
	{
		int s1,s2;
		s1=dfs(son);
		s2=dfs(son);
		/*for (int i=0;i<=tot-l;i++)
			f[son][i+l]=max(f[s1][i],f[s2][i]);*/
		for (int i=0;i<=tot-l;i++)
			for (int j=0;j<=tot-l-i;j++)
				f[son][i+j+l]=max(f[son][i+j+l],f[s1][i]+f[s2][j]);
	}
	else
	{
		for (int i=0;i<=v;i++)
			f[son][l+5*i]=i;
	}
	return son;
}
int main()
{
	scanf("%d",&tot);
	tot--;
	dfs(0);
	int ans=0;
	for (int i=0;i<=tot;i++)
		if (f[1][i]>ans)
			ans=f[1][i];
	printf("%d",ans);
}
