#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL=1.5e4+1;
char a[MAXL];
int k,p[MAXL];
long long ans;
inline void solve()
{
	int len=strlen(a+1);
	for (int l=1;l<=len-(k<<1);l++)
	{
		for (int i=1;i<=l;i++)
			p[i]=l-1;
		for (int i=l,j=l-1;i<len;i++)
		{
			while (j>l-1&&a[i+1]!=a[j+1]) j=p[j];
			if (a[i+1]==a[j+1]) j++;
			p[i+1]=j;
		}
		for (int r=l+1,j=l-1;r<=len;r++)
		{
			while (j>l-1&&a[r]!=a[j+1]) j=p[j];
			if (a[r]==a[j+1]) j++;
			while (j-l+1>=r-j) j=p[j];
			if (j-l+1>=k) ans++;
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf(" %s",a+1);
	scanf("%d",&k);
	solve();
	printf("%lld",ans);
}
//LOJ https://loj.ac/problem/10047
//JOYOI http://www.joyoi.cn/problem/bzoj-3620
