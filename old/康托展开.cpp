#include <cstdio>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=1e6+10;
int n;
int a[MAXN],c[MAXN];
ll ans,fact[MAXN];
int lowbit(int x)
{
	return x&(-x);
}
int query(int x)
{
	int res=0;
	for (;x>=1;x-=lowbit(x))
		res=(res+c[x])%mod;
	return res;
}
void update(int x,int val)
{
	for (;x<=n;x+=lowbit(x))
		c[x]+=val;
}
int main()
{
	//freopen("in.txt","r",stdin);
	fact[0]=1;
	for (int i=1;i<=1000000;i++)
		fact[i]=(fact[i-1]*i)%mod;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),update(i,1);
	ans=1;
	for (int i=1;i<=n;i++)
	{
		ans=(ans+(query(a[i])-1)*fact[n-i])%mod;
		update(a[i],-1);
	}
	printf("%lld\n",ans);
}
