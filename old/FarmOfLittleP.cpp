#include <cstdio>
#include <limits.h>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=1e6+1;
int n,q[MAXN];
long long a[MAXN],b[MAXN],sb[MAXN],tsb[MAXN],f[MAXN];
inline void dp()
{
	int head=1,tail=1;
	for (int i=1;i<=n;i++)
	{
		while (head<tail&&(sb[q[head]]-sb[q[head+1]])*i<f[q[head]]+tsb[q[head]]-(f[q[head+1]]+tsb[q[head+1]])) head++;
		f[i]=f[q[head]]+i*(sb[i]-sb[q[head]])-(tsb[i]-tsb[q[head]])+a[i];
		while (head<tail&&(f[i]+tsb[i]-f[q[tail]]-tsb[q[tail]])*(sb[q[tail]]-sb[q[tail-1]])<(sb[i]-sb[q[tail]])*(f[q[tail]]+tsb[q[tail]]-f[q[tail-1]]-tsb[q[tail-1]])) tail--;
		q[++tail]=i;
	}
	printf("%lld",f[n]);
}
/*Orginal dp 20
inline void dp()
{
	memset(f,0x7f,sizeof(f));
	f[1]=a[1];
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			f[i]=min(f[i],f[j]+i*(sb[i]-sb[j])-(tsb[i]-tsb[j])+a[i]);
		}
	}
	printf("%lld",f[n]);
}*/
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%lld",&b[i]),sb[i]=sb[i-1]+b[i],tsb[i]=tsb[i-1]+i*b[i];
	dp();
}
//DHOJ http://47.104.154.247/problem.php?cid=1101&pid=5
