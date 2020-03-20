#include <cstdio>
using namespace std;
const int MAXN=50;
int n;
int num[MAXN][MAXN];
int main()
{
	//freopen("magic.in","r",stdin);
	//freopen("magic.out","w",stdout);
	scanf("%d",&n);
	num[1][n+1>>1]=1;
	for (int k=2,i=1,j=n+1>>1;k<=n*n;k++)
	{
		if (i==1&&j==n)
		{
			i++;
		}
		else
		{
			i--; j++;
			if (i==0) i=n;
			if (j==n+1) j=1;
		}
		if (num[i][j]!=0)
		{
			i++; j--;
			if (i==n+1) i=1;
			if (j==0) j=n;
			i++;
		}
		num[i][j]=k;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%d ",num[i][j]);
		putchar('\n');
	}
}
