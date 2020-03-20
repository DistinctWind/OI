#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;
const int MAXN=10001;
int n,m,r[MAXN],h[MAXN],ans=INT_MAX;
int mins[MAXN],minv[MAXN];
void dfs(int dep,int v,int s)
{
	if (dep==0)
	{
		if (v!=n) return;
		ans=min(ans,s);
		return;
	}
	if (dep>1)
	{
		for (int i=min((int)sqrt(n-v),r[dep+1]-1);i>=dep;i--)
			for (int j=min((n-v)/(i*i),h[dep+1]-1);j>=dep;j--)
			{
				r[dep]=i;
				h[dep]=j;
				if (s+2*i*j+mins[dep-1]>ans) continue;
				if (v+i*i*j+minv[dep-1]>n) continue;
				if (s+2*i*j+2*(n-(v+i*i*j))/r[dep]>ans) continue;
				dfs(dep-1,v+i*i*j,s+2*i*j);
			}
	}
	else
	{
		for (int i=min((int)sqrt(n-v),r[dep+1]-1);i>=dep;i--)
		{
			r[dep]=i;
			h[dep]=(n-v)/(i*i);
			if (h[dep]<h[dep+1]&&h[dep]>0)
				dfs(dep-1,v+i*i*h[dep],s+2*i*h[dep]);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		mins[i]=mins[i-1]+2*i*i;
		minv[i]=minv[i-1]+i*i*i;
	}
	for (int i=(int)sqrt(n);i>=m;i--)//r
		for (int j=n/(i*i);j>=m;j--)//h
		{
			r[m]=i; h[m]=j;
			dfs(m-1,i*i*j,i*i+2*i*j);
		}
	if (ans==INT_MAX) printf("0");
	else printf("%d",ans);
}
