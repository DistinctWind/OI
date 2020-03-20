#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN=110;
const ll mod=1e9+7;
ll n,k;
struct Ran{
	ll num[MAXN][MAXN];
	Ran()
	{
		memset(num,0,sizeof(num));
	}
}a,ans;
Ran operator * (const Ran &x,const Ran &y)
{
	Ran res;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				res.num[i][j]=(res.num[i][j]+x.num[i][k]*y.num[k][j]%mod)%mod;
	return res;
}
void pow_plus()
{
	for (int i=1;i<=n;i++)
		ans.num[i][i]=1;
	while (k)
	{
		if (k&1) ans=ans*a;
		a=a*a;
		k>>=1;
	}
}
ll read()
{
	ll x=0; char a=getchar(); 
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	n=read(); k=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a.num[i][j]=read()%mod;
	pow_plus();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%lld ",ans.num[i][j]);
		putchar('\n');
	}
}
