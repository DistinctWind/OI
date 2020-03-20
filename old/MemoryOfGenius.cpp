#include <cstdio>
using namespace std;
const int MAXN=2e5+1;
const int LOGN=18;
int n,m,num[MAXN];
int log[MAXN],f[MAXN][LOGN+1];
int max(int a,int b)
{
	return a>b?a:b;
}
inline void setup()
{
	log[0]=-1;
	for (int i=1;i<=n;i++)
		f[i][0]=num[i],log[i]=log[i>>1]+1;
}
inline void dp()
{
	for (int j=1;j<=LOGN;j++)
	{
		for (int i=1;i+(1<<j)-1<=n;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	setup();
	dp();
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int k=log[b-a+1];
		printf("%d\n",max(f[a][k],f[b-(1<<k)+1][k]));
	}
}
//LOJ https://loj.ac/problem/10122
//JOYOI http://www.joyoi.cn/problem/tyvj-4341
//VIJOS https://vijos.org/p/1514
