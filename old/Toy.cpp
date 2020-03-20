#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=5e4+10;
int n,l,c[MAXN],q[MAXN];
long long f[MAXN],s[MAXN];
double x(int j,int k)
{
	return (double)(1.0*f[j]-f[k]+(s[j]+l)*(s[j]+l)-(s[k]+l)*(s[k]+l))/(2.0*(s[j]-s[k]));
}
inline void dp()
{
	f[0]=0;
	int head=1,tail=1;
	q[head]=0;
	for (int i=1;i<=n;i++)
	{
		while (head<tail&&x(q[head+1],q[head])<=s[i]) head++;
		f[i]=f[q[head]]+(s[i]-s[q[head]]-l-1)*(s[i]-s[q[head]]-l-1);
		while (head<tail&&x(i,q[tail])<=x(q[tail],q[tail-1])) tail--;
		q[++tail]=i;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]),s[i]=s[i-1]+c[i];
	for (int i=1;i<=n;i++)
		s[i]+=i;
	dp();
	printf("%lld",f[n]);
}
//LOJ https://loj.ac/problem/10188
//DHOJ http://47.104.154.247/problem.php?cid=1101&pid=1
//LGOJ https://www.luogu.org/problemnew/show/P3195
