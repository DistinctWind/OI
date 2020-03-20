#include <cstdio>
using namespace std;
const int MAXN=2e6+1;
const int MAXC=1e4+1;
int n,k,p,now;
long long ans;
int last[MAXC],cnt[MAXC],sum[MAXC];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&k,&p);
	for (int i=1;i<=n;i++)
	{
		int color,price;
		scanf("%d%d",&color,&price);
		if (price<=p)
			now=i;
		if (now>=last[color])
			sum[color]=cnt[color];
		ans+=sum[color];
		cnt[color]++;
		last[color]=i;
	}
	printf("%lld",ans);
}
//LOJ https://loj.ac/problem/2597
//LGOJ https://www.luogu.org/problem/P1311
//JOYOI http://www.joyoi.cn/problem/tyvj-1693
//VIJOS https://vijos.org/p/1737
