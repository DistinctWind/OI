#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 1000001
using namespace std;
long long n,a[MAXN],sum[MAXN],t,ans,ave;
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ave+=a[i];
	}
	ave/=n;
	//for (int i=1;i<=n;i++)
	//	a[i]-=ave;
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i]-ave;
	sort(sum+1,sum+1+n);
	t=sum[(n+1)/2];
	for (int i=1;i<=n;i++)
		ans+=abs(t-sum[i]);
	printf("%lld",ans);
}
