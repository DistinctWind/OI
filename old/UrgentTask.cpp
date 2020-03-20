#include <cstdio>
using namespace std;
int n,t,ans;
int map[10][10];
void dfs(int poi,int time)
{
	if (poi==n-1&&time==t)
		ans=(ans+1)%2009;
	if (time>t)
		return;
	for (int i=0;i<n;i++)
		if (map[poi][i]!=0)
			dfs(i,time+map[poi][i]);
}
int main()
{
	scanf("%d%d",&n,&t);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			char temp;
			scanf(" %c",&temp);
			map[i][j]=temp-'0';
		}
	dfs(0,0);
	printf("%d",ans);
}
