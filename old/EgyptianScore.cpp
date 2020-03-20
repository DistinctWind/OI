#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN=10001;
ll x,y,tmp[MAXN],ans[MAXN];
bool flag;
ll gcd(ll a,ll b)
{
	if (b==0) return a;
	else return gcd(b,a%b);
}
inline void copy(int n)
{
	sort(tmp+1,tmp+n);
	if (tmp[n-1]<ans[n-1])
		for (int i=1;i<n;i++)
			ans[i]=tmp[i];
}
void dfs(ll aa,ll bb,int pos,int limit)
{
	if (pos==limit-1)
	{
		if (aa==1)
		{
			for (int i=1;i<limit;i++)
				if (tmp[i]==bb)
					return;
			flag=true;
			tmp[pos]=bb;
			copy(limit);
		}
		return;
	}
	for (int i=tmp[pos-1]+1;;i++)
	{
		if (bb*(limit-pos+1)<=aa*i) break;
		ll ta=aa*i-bb;
		ll tb=bb*i;
		ll tg=gcd(ta,tb);
		if (ta<0||tb<0||ta>=tb) continue;
		tmp[pos]=i;
		dfs(ta/tg,tb/tg,pos+1,limit);
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%lld%lld",&x,&y);
	int i;
	memset(ans,0x3f,sizeof(ans));
	for (i=2;;i++)
	{
		dfs(x,y,1,i);
		if (flag) break;
	}
	for (int j=1;j<i;j++)
		printf("%d ",ans[j]);
}
