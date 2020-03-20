#include <cstdio>
#include <cstring>
using namespace std;
int a[10001],n;
bool dfs(int limit,int pos)
{
	if (pos>limit) return false;
	if (limit==pos&&a[pos]==n) return true;
	for (int i=pos;i>=1;i--)
		for (int j=i;j>=1;j--)
		{
			int nxt=a[i]+a[j];
			if (nxt>a[pos])
			{
				a[pos+1]=nxt;
				if (dfs(limit,pos+1)) return true;
				else continue;
			}
		}
	return false;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%d",&n),n!=0)
	{
		if (n==1)
		{
			printf("1\n");
			continue;
		}
		memset(a,0,sizeof(a));
		a[1]=1;
		int i;
		for (i=2;;i++)
			if (dfs(i,1))
				break;
		for (int j=1;j<=i;j++)
			printf("%d ",a[j]);
		putchar('\n');
	}
}
