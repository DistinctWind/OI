#include <cstdio>
using namespace std;
const int MAXN=1001;
int n,m,q;
int a[MAXN][MAXN],b[(int)3e5+10];
int read()
{
	int x=0; char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
int main()
{
	freopen("phalanx.in","r",stdin);
	freopen("phalanx.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	if (n==1)
	{
		for (int i=1;i<=m;i++)
			b[i]=i;
		for (int i=1,x,y;i<=q;i++)
		{
			x=read(); y=read();
			printf("%d\n",b[y]);
			int tmp=b[y];
			for (int i=y;i<m;i++)
				b[i]=b[i+1];
			b[m]=tmp;
		}
	}
	else
	{
		int num=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				a[i][j]=++num;
		for (int i=1,x,y;i<=q;i++)
		{
			x=read(); y=read();
			printf("%d\n",a[x][y]);
			int tmp=a[x][y];
			for (int j=y;j<m;j++)
				a[x][j]=a[x][j+1];
			for (int j=x;j<n;j++)
				a[j][m]=a[j+1][m];
			a[n][m]=tmp;
		}
	}
}
