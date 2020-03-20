#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
const int MAXN=210;
int e[MAXN][MAXN],pre[MAXN];
bool vis[MAXN];
int n,m,ans;
int min(int a,int b)
{
	return a<b?a:b;
}
int find()
{
	deque <int> q;
	memset(pre,0,sizeof(pre));
	memset(vis,0,sizeof(vis));
	vis[1]=true; pre[1]=0;
	q.push_back(1);
	bool findPath=false;
	while (!q.empty())
	{
		int h=q.front(); q.pop_front();
		for (int i=1;i<=n;i++)
		{
			if (e[h][i]>0&&!vis[i])
			{
				vis[i]=true;
				pre[i]=h;
				if (i==n)
				{
					findPath=true;
					q.clear();
					break;
				}
				else q.push_back(i);
			}
		}
	}
	if (!findPath)
		return 0;
	int minVal=INT_MAX;
	int v=n;
	while (pre[v])
	{
		minVal=min(minVal,e[pre[v]][v]);
		v=pre[v];
	}
	v=n;
	while (pre[v])
	{
		e[pre[v]][v]-=minVal;
		e[v][pre[v]]+=minVal;
		v=pre[v];
	}
	return minVal;
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d%d",&m,&n)!=EOF)
	{
		memset(e,0,sizeof(e));
		ans=0;
		for (int i=1;i<=m;i++)
		{
			int a,b,tmp;
			scanf("%d%d",&a,&b);
			scanf("%d",&tmp);
			e[a][b]+=tmp;
		}
		int tmp=0;
		while (tmp=find())
			ans+=tmp;
		printf("%d\n",ans);
	}
}
//LOJ http://poj.org/problem?id=1273
//LGOJ https://www.luogu.org/problem/P2740
