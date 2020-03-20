#include <cstdio>
#include <cstring>
#define MAXN 51
#define MAXT 201
using namespace std;
const int INF=100000000;
int n,T,t[MAXN],m1,m2,a[MAXN],b[MAXN],dp[MAXT][MAXN],kind;
bool trainBegin[MAXT][MAXN][2];//0 right ; 1 left
int min(int a,int b)
{
	return a<b?a:b;
}
inline void GetTrain()
{
	int now_t=0;
	for (int i=1;i<=m1;i++)
	{
		now_t=a[i];
		for (int j=1;j<=n&&now_t<=T;j++)
		{
			trainBegin[now_t][j][0]=true;
			now_t+=t[j];
		}
	}
	for (int i=1;i<=m2;i++)
	{
		now_t=b[i];
		for (int j=n;j>=1&&now_t<=T;j--)
		{
			trainBegin[now_t][j][1]=true;
			now_t+=t[j-1];
		}
	}
	
}
inline void ndp()
{
	for (int i=1;i<=n-1;i++)
		dp[T][i]=INF;
	dp[T][n]=0;
	for (int i=T-1;i>=0;i--)
		for (int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i+1][j]+1;
			if (j<n&&trainBegin[i][j][0]&&i+t[j]<=T)
				dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
			if (j>1&&trainBegin[i][j][1]&&i+t[j-1]<=T)
				dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
		}
}
inline void setup()
{
	T=m1=m2=0;
	memset(t,0,sizeof(t));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(dp,0,sizeof(dp));
	memset(trainBegin,0,sizeof(trainBegin));
}
/*inline void print()
{
	for (int i=T-1;i>=0;i--)
	{
		for (int j=1;j<=n;j++)
			if (trainBegin[i][j][0])
				printf("T ");
			else
				printf("F ");
		putchar('\n');
	}
	for (int i=T-1;i>=0;i--)
	{
		for (int j=1;j<=n;j++)
			printf("%12d",dp[i][j]);
		putchar('\n');
	}
}*/
int main()
{
	while (scanf("%d",&n),n!=0)
	{
		setup();
		scanf("%d",&T);
		for (int i=1;i<=n-1;i++)
			scanf("%d",&t[i]);
		scanf("%d",&m1);
		for (int i=1;i<=m1;i++) scanf("%d",&a[i]);
		scanf("%d",&m2);
		for (int i=1;i<=m2;i++) scanf("%d",&b[i]);
		GetTrain();
		//print();
		ndp();
		if (dp[0][1]>=INF)
		{
			printf("Case Number %d: impossible\n",++kind);
			continue;
		}
		else
		{
			printf("Case Number %d: %d\n",++kind,dp[0][1]);
			continue;
		}
	}
}
//VOJ https://vjudge.net/contest/288229 Password:dhsty
//LGOJ https://www.luogu.org/problemnew/show/UVA1025
