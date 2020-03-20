#include <cstdio>
using namespace std;
const int MAXN=1e6+1;
int n,a,b,c,q[2*MAXN];
long long s[MAXN],f[MAXN];
long long pow(long long x)
{
	return x*x;
}
double k(int pos1,int pos2)
{
	long long y=f[pos1]+a*pow(s[pos1])-b*s[pos1]-(f[pos2]+a*pow(s[pos2])-b*s[pos2]);
	long long x=s[pos1]-s[pos2];
	if (x==0) return -0x3f3f3f3f;
	return (double)y/x;
}
inline void dp()
{
	int head=1,tail=1;
	for (int i=1;i<=n;i++)
	{
		while (head<tail&&k(q[head],q[head+1])>2*a*s[i]) head++;
		f[i]=f[q[head]]+a*(s[i]-s[q[head]])*(s[i]-s[q[head]])+b*(s[i]-s[q[head]])+c;
		while (head<tail&&k(i,q[tail])>k(q[tail],q[tail-1])) tail--;
		q[++tail]=i;
	}
	printf("%lld",f[n]);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&n,&a,&b,&c);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
		s[i]+=s[i-1];
	}
	dp();
}
//DHOJ http://47.104.154.247/problem.php?cid=1101&pid=3
