#include <cstdio>
using namespace std;
const int MAXN=13;
bool vis[MAXN];
int n,s,ans[MAXN],h[MAXN][MAXN];
bool dfs(int pos,int num,int sum)
{
	if (sum>s) return false;
	if (pos==n)
	{
		if (sum==s)
		{
			ans[pos]=num;
			return true;
		}
		else return false;
	}
	vis[num]=true;
	for (int i=1;i<=n;i++)
	{
		if (!vis[i]&&dfs(pos+1,i,sum+h[n-1][pos+1]*i))
		{
			ans[pos]=num;
			return true;
		}
	}
	vis[num]=false;
	return false;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&s);
	h[0][1]=h[1][1]=h[1][2]=1;
	for (int i=2;i<=MAXN;i++)
	{
		for (int j=1;j<=i+1;j++)
		{
			h[i][j]=h[i-1][j]+h[i-1][j-1];
			//printf("%d ",h[i][j]);
		}
		//putchar('\n');
	}
	if (dfs(0,0,0))
		for (int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	else return 0;
}
