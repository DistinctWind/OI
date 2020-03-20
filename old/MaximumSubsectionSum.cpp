#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=200000+1;
int n,a[MAXN];
long long ans=-0x7fffffff,sum;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
		if (sum>ans) ans=sum;
		if (sum<0) sum=0;
	}
	printf("%lld",ans);
}
//LGOJ https://www.luogu.org/problem/P1115
