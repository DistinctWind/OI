#include <cstdio>
using namespace std;
int a[10001];
int n,m;
bool dfs(int limit,int len)
{
	if (len>limit) return false;
	if (len==limit&&a[len]==n) return true;
	for (int i=len;i>=1;i--)
		for (int j=i;j>=1;j--)
		{
			int next=a[i]+a[j];
			if (next>a[len])
			{
				a[len+1]=next;
				if (dfs(limit,len+1)==true) return true;
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
		for (int i=1;i<=10000;i++)
			a[i]=0;
		a[1]=1;
		int i;
		for (i=2;;i++)
		{
			if (dfs(i,1)==true)
				break;
		}
		for (int now=1;now<=i;now++)
			printf("%d ",a[now]);
		printf("\n");
	}
}
