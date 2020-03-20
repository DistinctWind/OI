#include <cstdio>
#include <limits.h>
#include <algorithm>
#define ll long long
#define MAXN 1000
using namespace std;
ll a,b;
ll ans[MAXN],now[MAXN];
bool flag;
ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
void copy(int n)
{
	sort(now+1,now+n);
	if (now[n-1]<ans[n-1])
		for (int i=1;i<n;i++)
			ans[i]=now[i];
}
void dfs(ll aa,ll bb,ll len,ll limit)
{
	if (len==limit-1)
	{
		if (aa==1)
		{
			for (int i=1;i<limit;i++)
				if (now[i]==bb)
					return;
			now[len]=bb;
			flag=true;
			copy(limit);
		}
		return;
	}
	for (int i=now[len-1]+1;;i++)
	{
		if (bb*(limit-len+1)<=aa*i==true) return;
		ll ta=aa*i-bb;
		ll tb=bb*i;
		ll tg=gcd(ta,tb);
		if (ta<0||tb<0||ta>=tb) continue;
		now[len]=i;
		dfs(ta/tg,tb/tg,len+1,limit);
	}
}
int main()
{
	for (int i=1;i<MAXN;i++)
		ans[i]=INT_MAX;
	scanf("%ld%ld",&a,&b);
	//ans[0][0]=1;
	int i,t,m=INT_MAX;
	for (i=2;;i++)
	{
		dfs(a,b,1,i);
		if (flag==true)
			break;
	}
	for (int x=1;x<=i-1;x++)
		printf("%ld ",ans[x]);
}
