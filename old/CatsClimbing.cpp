#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN=1001;
int c[MAXN],cab[MAXN],n,w,ans;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int now,int cnt)
{
	if (cnt>=ans) return;
	if (now==n+1)
	{
		ans=min(ans,cnt);
		return;
	}
	for (int i=1;i<=cnt;i++)
	{
		if (cab[i]+c[now]<=w)
		{
			cab[i]+=c[now];
			dfs(now+1,cnt);
			cab[i]-=c[now];
		}
	}
	cab[cnt+1]=c[now];
	dfs(now+1,cnt+1);
	cab[cnt+1]=0;
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&w);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	sort(c+1,c+1+n,cmp);
	ans=INT_MAX;
	dfs(1,0);
	printf("%d",ans);	
}
//JOYOI http://www.joyoi.cn/problem/codevs-4228
