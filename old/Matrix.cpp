#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
const int MAXM=1001,MAXN=1001;
const int p1=8229283,p2=2472627;
int m,n,a,b,q;
unsigned int hash[MAXN][MAXM],pow1[MAXN],pow2[MAXM];
unsigned int tmp[MAXN][MAXM];
set <unsigned int> s;
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&n,&m,&a,&b);
	pow1[0]=pow2[0]=1;
	for (int i=1;i<=1000;i++)
		pow1[i]=pow1[i-1]*p1,pow2[i]=pow2[i-1]*p2;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			char a;
			scanf(" %c",&a);
			hash[i][j]=a-'0';
			hash[i][j]=hash[i][j-1]*p2+hash[i][j];
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			hash[i][j]=hash[i-1][j]*p1+hash[i][j];
			if (i>=a&&j>=b)
				s.insert(hash[i][j]-hash[i-a][j]*pow1[a]-hash[i][j-b]*pow2[b]+hash[i-a][j-b]*pow1[a]*pow2[b]);
		}
	scanf("%d",&q);
	while (q--)
	{
		memset(tmp,0,sizeof(tmp));
		for (int i=1;i<=a;i++)
			for (int j=1;j<=b;j++)
			{
				char a;
				scanf(" %c",&a);
				tmp[i][j]=a-'0';
				tmp[i][j]=tmp[i][j-1]*p2+tmp[i][j];
			}
		for (int i=1;i<=a;i++)
			for (int j=1;j<=b;j++)
				tmp[i][j]=tmp[i-1][j]*p1+tmp[i][j];
		if (s.count(tmp[a][b])) printf("1\n");
		else printf("0\n");
	}
}
