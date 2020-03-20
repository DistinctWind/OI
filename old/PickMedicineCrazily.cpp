#include <cstdio>
#include <time.h>
#define MAXM 10001
#define MAXT 100001
using namespace std;
int t,m,cnt_m,f[MAXT];
struct MEDICINE{
	int t,v;
}med[MAXM];
int max(int a,int b)
{
	return a>b?a:b;
}
inline void dp()
{
	for (int i=1;i<=m;i++)
		for (int j=med[i].t;j<=t;j++)
			f[j]=max(f[j],f[j-med[i].t]+med[i].v);
}
int main()
{
	scanf("%d%d",&t,&m);
	for (int i=1;i<=m;i++)
	{
		cnt_m++;
		scanf("%d%d",&med[cnt_m].t,&med[cnt_m].v);
	}
	dp();
	printf("%d",f[t]);
}
