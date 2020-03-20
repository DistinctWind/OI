#include <cstdio>
#include <iostream>
#include <limits.h>
#define MAXN 200001
using namespace std;
int n,ans=INT_MAX;
int t[MAXN],fv[MAXN];//fv=first visited
bool vis[MAXN],novis[MAXN];
void dfs(int node,int num)
{
	if (novis[node]==true) return;
	if (vis[node]==true) ans=min(ans,num-fv[node]);
	else
	{
		vis[node]=true;
		fv[node]=num;
		dfs(t[node],num+1);
		novis[node]=true;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for (int i=1;i<=n;i++)
		dfs(i,0);
	printf("%d",ans);
}
