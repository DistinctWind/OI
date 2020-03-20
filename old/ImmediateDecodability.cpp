#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL=11;
const int MAXN=1000;
char a[MAXL];
int tree[MAXN][2],tot=1,t;
bool end[MAXN],ans=false;
bool insert()
{
	int len=strlen(a);
	int u=1;
	bool flag=false;
	for (int i=0;i<len;i++)
	{
		int now=a[i]-'0';
		if (tree[u][now]==0) tree[u][now]=++tot;
		else if (i==len-1) flag=true;
		u=tree[u][now];
		if (end[u]) flag=true;
	}
	end[u]=true;
	return flag;
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf(" %s",a)!=EOF)
	{
		t++;
		ans=false; tot=1;
		memset(tree,0,sizeof(tree));
		memset(end,false,sizeof(end));
		while (a[0]!='9')
		{
			ans=ans|insert();
			scanf(" %s",a);
		}
		if (ans) printf("Set %d is not immediately decodable\n",t);
		else printf("Set %d is immediately decodable\n",t);
	}
}
//LOJ https://loj.ac/problem/10052
