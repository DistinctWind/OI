#include <cstdio>
using namespace std;
const int MAXN=500010;
int n,m;
long long c[MAXN];
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,long long v)
{
	for (;x<=n;x+=lowbit(x))
		c[x]+=v;
}
long long query(int x)
{
	long long res=0;
	for (;x>=1;x-=lowbit(x))
		res+=c[x];
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		long long tmp;
		scanf("%lld",&tmp);
		update(i,tmp); update(i+1,-tmp);
	}
	for (int i=1;i<=m;i++)
	{
		int z,x,y; long long v;
		scanf("%d",&z);
		if (z==1)
		{
			scanf("%d%d%lld",&x,&y,&v);
			update(x,v); update(y+1,-v);
		}
		else
		{
			scanf("%d",&x);
			printf("%lld\n",query(x));
		}
	}
}
