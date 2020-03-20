#include <cstdio> 
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
using namespace std;
const int MAXN=110;
const int MAXM=1010;
vector <int> op,g[MAXM<<3];
bool vis[MAXM<<3];
int n,m,v,match[MAXM<<3];
inline void add(int a,int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}
bool dfs(int x)
{
	for (int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if (vis[y]) continue;
		vis[y]=true;
		if (match[y]<0||dfs(match[y]))
		{
			match[x]=y;
			match[y]=x;
			return true;
		}
	}
	return false;
}
int solve()
{
	int ans=0;
	for (int i=0;i<v;i++)
	{
		if (match[i]<0)
		{
			memset(vis,0,sizeof(vis));
			if (dfs(i))
			{
				ans++;
			}
		}
	}
	return ans;
}
inline void setup()
{
	memset(match,-1,sizeof(match));
	for (int i=0;i<v;i++)
	{
		g[i].clear();
	}
	op.clear();
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		if (n==0&&m==0) break;
		setup();
		for (int i=1;i<=m;i++)
		{
			char a[MAXN];
			int tmp=0;
			scanf(" %s",a);
			for (int j=0;j<n;j++)
			{
				tmp<<=1;
				if (a[j]=='1')
				{
					tmp|=1;
				}
			}
			op.push_back(tmp);
			for (int j=0;j<n;j++)
			{
				if (a[j]=='*')
				{
					tmp=tmp|(1<<(n-j-1));
				}
			}
			op.push_back(tmp);
		}
		sort(op.begin(),op.end());
		op.erase(unique(op.begin(),op.end()),op.end());
		v=op.size();
		for (int i=0;i<v;i++)
			for (int j=i+1;j<v;j++)
			{
				bitset <32> tmp=op[i]^op[j];
				if (tmp.count()==1)
				{
					add(i,j);
				}
			}
		printf("%d\n",v-solve());
	}
}

