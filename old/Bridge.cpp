#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=60;
char tmp;
int t,n,d;
int f[MAXN][MAXN];
int min(int a,int b)
{
	return a<b?a:b;
}
int max(int a,int b)
{
	return a>b?a:b;
}
inline void floyd()
{
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&d);
		memset(f,0x3f,sizeof(f));
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				scanf(" %c",&tmp);
				if (tmp=='Y') f[i][j]=1;
				if (i==j) f[i][j]=0;
			}
		floyd();
		int ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				ans=max(ans,f[i][j]);
		if (ans==0x3f3f3f3f) printf("-1\n");
		else printf("%d\n",ans*d);
	}
}
