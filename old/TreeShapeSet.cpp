#include <cstdio>
using namespace std;
const int MAXN=500000+1;
int n,m;
long long c[MAXN];
int lowbit(int x)
{
	return x&(~x+1);
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
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		update(i,tmp);
	}
	for (int i=1;i<=m;i++)
	{
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		if (k==1)
		{
			update(x,y);
		}
		else if (k==2)
		{
			printf("%lld\n",sum(y)-sum(x-1));
		}
	}
}
//DHOJ https://www.luogu.org/problemnew/show/P3374
