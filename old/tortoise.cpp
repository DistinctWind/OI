#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=360;
const int MAXM=125;
int n,m,sco[MAXN],car[MAXM];
int cnt[5];
int f[41][41][41][41];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	//freopen("tortoise.in","r",stdin);
	//freopen("tortoise.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&sco[i]);
	for (int i=1;i<=m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		cnt[tmp]++;
	}
	f[0][0][0][0]=sco[1];
	for (int i=0;i<=cnt[1];i++)
		for (int j=0;j<=cnt[2];j++)
			for (int k=0;k<=cnt[3];k++)
				for (int p=0;p<=cnt[4];p++)
				{
					if (i-1>=0) f[i][j][k][p]=max(f[i][j][k][p],f[i-1][j][k][p]+sco[1+i+2*j+3*k+4*p]);
					if (j-1>=0) f[i][j][k][p]=max(f[i][j][k][p],f[i][j-1][k][p]+sco[1+i+2*j+3*k+4*p]);
					if (k-1>=0) f[i][j][k][p]=max(f[i][j][k][p],f[i][j][k-1][p]+sco[1+i+2*j+3*k+4*p]);
					if (p-1>=0) f[i][j][k][p]=max(f[i][j][k][p],f[i][j][k][p-1]+sco[1+i+2*j+3*k+4*p]);
				}
	printf("%d\n",f[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);
}
