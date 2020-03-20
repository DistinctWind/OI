#include <cstdio>
using namespace std;
const int MAXN=1e5+1;
const int LOGN=17;
int n,k,num[MAXN],log[MAXN];
int f[MAXN][LOGN+1],g[MAXN][LOGN+1];
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
inline void setup()
{
	log[0]=-1;
	for (int i=1;i<=n;i++)
		f[i][0]=g[i][0]=num[i],log[i]=log[i>>1]+1;
}
inline void dp()
{
	for (int j=1;j<=LOGN;j++)
	{
		for (int i=1;i+(1<<j)-1<=n;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
			g[i][j]=min(g[i][j-1],g[i+(1<<j-1)][j-1]);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("nout.txt","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	setup();
	dp();
	for (int i=1;i+k-1<=n;i++)
	{
		int l=i,r=i+k-1;
		int t=log[r-l+1];
		printf("%d %d\n",max(f[l][t],f[r-(1<<t)+1][t]),min(g[l][t],g[r-(1<<t)+1][t]));
	}
}
//LOJ https://loj.ac/problem/10120
