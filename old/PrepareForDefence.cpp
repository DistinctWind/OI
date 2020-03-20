#include <cstdio>
#include <iostream>
#include <limits.h>
using namespace std;
const long long MAXN=1e6+10;
long long n;
long long f[MAXN],a[MAXN],q[MAXN];
long long k(long long pos1,long long pos2)
{
	long long y=2*f[pos1]+pos1*pos1+pos1-(2*f[pos2]+pos2*pos2+pos2);
	long long x=2*pos1-2*pos2;
	return y/x;
}
inline void dp()
{
	long long head=1,tail=1;
	q[1]=1;f[1]=a[1];
	for (long long i=2;i<=n;i++)
	{
		while (head<tail&&k(q[head],q[head+1])<i) head++;
		f[i]=f[q[head]]+(i-q[head])*(i-q[head]-1)/2+a[i];
		while (head<tail&&k(q[tail],q[tail-1])>k(q[tail],i)) tail--;
		q[++tail]=i;
	}
	for (long long i=1;i<n;i++)
	{
		f[n]=min(f[n],f[i]+(long long)(n-i+1)*(n-i)/2);
		//if (f[n]<0) printf("Error:%d\n",i);
	}
	printf("%lld",f[n]);
}
/*Force 0
inline void dp()
{
	f[1]=a[1];
	for (long long i=2;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
		for (long long j=1;j<i;j++)
		{
			f[i]=min(f[i],f[j]+(i-j)*(i-j-1)/2+a[i]);
		}
	}
	printf("%lld",f[n]);
}*/
main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%lld",&n);
	for (long long i=n;i>=1;i--)
		scanf("%lld",&a[i]);
	dp();
}
//DHOJ http://47.104.154.247/problem.php?cid=1101&pid=4
