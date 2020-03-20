#include <cstdio>
using namespace std;
long long d,n;
int main()
{
	long long a,b;
	scanf("%lld%lld%lld",&a,&b,&n);
	d=b-a;
	printf("%lld",n*a+n*(n-1)*d/2);
}
