#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=1e6+1;
const int MAXC=10;
string a[MAXN];
int tree[MAXN][MAXC];
bool end[MAXN];
int t,n,tot;
bool insert(string x)
{
	int len=x.size();
	int u=1;
	bool flag=false;
	for (int i=0;i<len;i++)
	{
		if (tree[u][x[i]-'0']==0)
			tree[u][x[i]-'0']=++tot;
		else if (i==len-1)
			flag=true;
		u=tree[u][x[i]-'0'];
		if (end[u]==true) flag=true;
	}
	end[u]=true;
	return flag;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	bool ans=false;
	for (int i=1;i<=t;i++)
	{
		memset(tree,0,sizeof(tree));
		memset(end,0,sizeof(end));
		ans=false;
		tot=1;
		scanf("%d",&n);
		for (int j=1;j<=n;j++)
		{
			cin>>a[i];
			if (insert(a[i]))
				ans=true;
		}
		if (ans) printf("NO\n");
		else printf("YES\n");
	}
}
//LOJ https://loj.ac/problem/10049
