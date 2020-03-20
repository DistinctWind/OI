#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=100010;
const int MAXM=100010;
const int MAXR=100010;
typedef long long ll;
int n,m,r;
ll sum,cow[MAXN],val[MAXR];
struct Store{
	ll p,maxv;
}store[MAXM];
bool cmp (Store a,Store b)
{
	return a.p>b.p;
}
bool icmp(int a,int b)
{
	return a>b;
}
ll calc(int x,int y)
{
	
}
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&r);
	for (int i=1;i<=n;i++)
		scanf("%lld",&cow[i]),sum+=cow[i];
	for (int i=1;i<=m;i++)
		scanf("%lld%lld",&store[i].maxv,&store[i].p);
	for (int i=1;i<=r;i++)
		scanf("%lld",&val[i]);
	sort(cow+1,cow+1+n,icmp);
	sort(store+1,store+1+m,cmp);
	sort(val+1,val+1+r,icmp);
	ll ans=0;
	int i=n,j=1,k=1;
	ll left=store[j].maxv;
	for (;i>=1;i--)
	{
		if (calc(i)<=val[k]&&k<=r)
		{
			ans+=val[k];
			k++;
		}
		else
		{
			sum-=cow[i];
			while (j<=m&&cow[i]>0)
			{
				if (cow[i]>=store[j].maxv)
				{
					ans+=store[j].p*store[j].maxv;
					cow[i]-=store[j].maxv;
					sum-=store[j].maxv;
					store[j].maxv=0;
					j++;
				}
				else
				{
					ans+=cow[i]*store[j].p;
					store[j].maxv-=cow[i];
					sum-=cow[i];
					cow[i]=0;
				}
			}
		}
	}
	printf("%lld\n",ans);
}
