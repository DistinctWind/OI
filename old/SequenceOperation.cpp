#include <cstdio>
using namespace std;
const int MAXN=100001;
long long c[MAXN];
int n,m;
int lowbit(int x)
{
	return x&(-x);
}
inline void update(int pos,int x)
{
	for (;pos<=n;pos+=lowbit(pos))
		c[pos]+=x;
}
long long sum(int pos)
{
	long long res=0;
	for (;pos>0;pos-=lowbit(pos))
		res+=c[pos];
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		long long tmp;
		scanf("%lld",&tmp);
		update(i,tmp);
	}
	for (int i=1;i<=m;i++)
	{
		int swi,x,y;
		scanf("%d%d%d",&swi,&x,&y);
		if (swi==0)
		{
			printf("%lld\n",sum(y)-sum(x-1));
			continue;
		}
		if (swi==1)
		{
			update(x,y);
			continue;
		}
	}
}
