#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1001
using namespace std;
int n,cnt,sum[MAXN],d[MAXN];
struct LAMP{
	int v,k,c,l;
}lamp[MAXN];
bool operator < (LAMP a,LAMP b)
{
	return a.v<b.v;
}
int min(int a,int b)
{
	return a>b?b:a;
}
inline void dp()
{
	memset(d,0x3f,sizeof(d));
	d[0]=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++)
			d[i]=min(d[i],d[j]+(sum[i]-sum[j])*lamp[i].c+lamp[i].k);
}
inline void setup()
{
	memset(sum,0,sizeof(sum));
	memset(d,0,sizeof(d));
	cnt=0;
}
int main()
{
	while (scanf("%d",&n),n!=0)
	{
		setup();
		for (int i=1;i<=n;i++)
		{
			cnt++;
			scanf("%d%d%d%d",&lamp[cnt].v,&lamp[cnt].k,&lamp[cnt].c,&lamp[cnt].l);
		}
		sort(lamp+1,lamp+1+n);
		for (int i=1;i<=n;i++)
			sum[i]=sum[i-1]+lamp[i].l;
		dp();
		printf("%d\n",d[n]);
	}
}
