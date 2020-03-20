#include <cstdio>
using namespace std;
typedef long long ll;
ll b,p,k;
ll pow_plus(ll x,ll y,ll mod)
{
	ll res=1;
	x%=mod;
	while (y)
	{
		if (y&1) res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res%mod;
}
int main()
{
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld\n",b,p,k,pow_plus(b,p,k));
}
