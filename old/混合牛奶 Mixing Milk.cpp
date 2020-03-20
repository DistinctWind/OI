#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m;
const int MAXN=2000001;
struct Cow{
	ll a,p;
}cow[MAXN];
bool cmp(Cow a,Cow b)
{
	return a.p<b.p;
}
ll ans;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%lld%lld",&cow[i].p,&cow[i].a);
	sort(cow+1,cow+1+m,cmp);
	int i=1;
	while (i<=m&&n>0)
	{
		if (n>=cow[i].a)
		{
			n-=cow[i].a;
			ans+=cow[i].a*cow[i].p;
			i++;
		}
		else
		{
			ans+=n*cow[i].p;
			n=0;
		}
	}
	printf("%lld\n",ans);
}
