#include <cstdio>
using namespace std;
const int MAXL=1e6+1;
int k,p[MAXL],s[MAXL];
long long ans;
char a[MAXL];
inline void setup()
{
	int j=0;
	p[1]=0;
	for (int i=1;i<k;i++)
	{
		while (j>0&&a[i+1]!=a[j+1]) j=p[j];
		if (a[i+1]==a[j+1]) j++;
		p[i+1]=j;
	}
}
inline void solve()
{
	for (int i=2,j=2;i<=k;i++,j=i)
	{
		while (p[j]!=0) j=p[j];
		if (p[i]!=0) p[i]=j;
		ans+=i-j;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&k);
	scanf(" %s",a+1);
	setup();
	solve();
	printf("%lld",ans);;
}
//LOJ https://loj.ac/problem/10046
//DHOJ https://www.luogu.org/problemnew/show/P3435
