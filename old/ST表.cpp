#include <cstdio>
using namespace std;
const int MAXN=1e5+10;
const int LOGN=18;
int n,m;
int num[MAXN],f[MAXN][LOGN],log[MAXN];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	scanf("%d%d",&n,&m); log[0]=-1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		log[i]=log[i>>1]+1;
		f[i][0]=num[i];
	}
	for (int j=1;j<=LOGN;j++)
		for (int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for (int i=1,l,r,k;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		k=log[r-l+1];
		printf("%d\n",max(f[l][k],f[r-(1<<k)+1][k]));
	}
}
