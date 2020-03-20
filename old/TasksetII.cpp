#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=3*1e5+1;
int n,s,t[MAXN],c[MAXN];
int head=1,tail=1;
long long sumt[MAXN],sumc[MAXN],f[MAXN],q[MAXN*2+1];
int find(int k)
{
	if (head==tail) return q[head];
	int l=head,r=tail;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (f[q[mid+1]]-f[q[mid]]<=k*(sumc[q[mid+1]]-sumc[q[mid]])) l=mid+1;
		else r=mid;
	}
	return q[l];
}
inline void dp()
{
	memset(f,0x3f,sizeof(f));
	memset(q,0,sizeof(q));
	f[0]=0;
	for (int i=1;i<=n;i++)
	{
		int p=find(s+sumt[i]);
		f[i]=f[p]-(s+sumt[i])*sumc[p]+sumt[i]*sumc[i]+s*sumc[n];
		while (head<tail&&(f[q[tail]]-f[q[tail-1]])*(sumc[i]-sumc[q[tail]])>=(f[i]-f[q[tail]])*(sumc[q[tail]]-sumc[q[tail-1]])) tail--;
		q[++tail]=i;
	}
	printf("%lld",f[n]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i],&c[i]);
		sumt[i]=sumt[i-1]+t[i];
		sumc[i]=sumc[i-1]+c[i];
	}
	dp();
}
//LOJ https://loj.ac/problem/10185
