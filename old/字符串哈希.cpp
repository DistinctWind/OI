#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
const ll b=1e6+9;
const ll mod=1e9+7;
const int MAXL=1510;
int n,ans;
char a[MAXL];
set <ll> s;
ll calc(char *x)
{
	int len=strlen(x);
	ll res=0;
	for (int i=0;i<len;i++)
		res=(res*b+x[i])%mod;
	return res;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf(" %s",a);
		ll res=calc(a);
		if (s.count(res)==0)
		{
			s.insert(res);
			ans++;
		}
	}
	printf("%d",ans);
}
