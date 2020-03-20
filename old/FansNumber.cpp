#include <cstdio>
using namespace std;
const long long mod=1000000007;
const int MAXN=1000010;
const int LOGN=19;
int cnt;
long long n;
long long f[MAXN],num[MAXN];
int main()
{
	scanf("%lld",&n);
	num[0]=1;
	for (int i=1;i<=LOGN;i++)
		num[i]=num[i-1]<<1;
	f[0]=1;
	for (int i=0;i<=LOGN&&num[i]<=n;i++)
		for (int j=num[i];j<=n;j++)
			f[j]=(f[j]+f[j-num[i]])%mod;
	printf("%lld",f[n]);
}
