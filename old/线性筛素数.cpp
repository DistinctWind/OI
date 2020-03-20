#include <cstdio>
using namespace std;
const int MAXN=10000001;
int v[MAXN],prime[MAXN];
int n,m,cntPrime;
bool ip[MAXN];
inline void calc()
{
	for (int i=2;i<=n;i++)
	{
		if (!v[i])
		{
			v[i]=i;
			prime[++cntPrime]=i;
			ip[i]=true;
		}
		for (int j=1;j<=cntPrime;j++)
		{
			if (i*prime[j]>n||v[i]<prime[j]) break;
			v[i*prime[j]]=prime[j];
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	calc();
	for (int i=1,x;i<=m;i++)
	{
		scanf("%d",&x);
		if (!ip[x]) printf("No\n");
		else printf("Yes\n");
	}
}
