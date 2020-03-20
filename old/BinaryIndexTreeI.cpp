#include <cstdio>
using namespace std;
const int MAXN=1e6+1;
long long c[MAXN];
int n,p;
int lowbit(int x)
{
	return x&(-x);
}
inline void update(int x,int v)
{
	for (;x<=n;x+=lowbit(x))
		c[x]+=v;
}
long long sum(int x)
{
	long long res=0;
	for (;x>0;x-=lowbit(x))
		res+=c[x];
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		update(i,tmp);
	}
	for (int i=1;i<=p;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (x==1) update(y,z);
		else printf("%lld\n",sum(z)-sum(y-1));
	}
}
//LOJ https://loj.ac/problem/130
