#include <cstdio>
using namespace std;
const int MAXN=1e5+1;
int n,m,same[MAXN];
int c1[MAXN],c2[MAXN];
int lowbit(int x)
{
	return x&(~x+1);
}
inline void update1(int pos,int x)
{
	for (;pos<=n;pos+=lowbit(pos))
		c1[pos]+=x;
}
inline void update2(int pos,int x)
{
	for (;pos<=n;pos+=lowbit(pos))
		c2[pos]+=x;
}
int sum1(int pos)
{
	int res=0;
	for (;pos>0;pos-=lowbit(pos))
		res+=c1[pos];
	return res;
}
int sum2(int pos)
{
	int res=0;
	for (;pos>0;pos-=lowbit(pos))
		res+=c2[pos];
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if (l!=r)
			{
				update1(l,1);
				update2(r,1);
			}
			else
			{
				same[l]++;
			}
		}
		else if (t==2)
		{
			int pos;
			scanf("%d",&pos);
			int ts=sum1(pos)-sum2(pos-1);
			//printf("%d %d\n",sum1(pos),sum2(pos-1));
			printf("%d\n",(ts+same[pos])%2);
		}
	}
}
//LOJ https://loj.ac/problem/10117
//LGOJ https://www.luogu.org/problemnew/show/P5057
//JOYOI http://www.joyoi.cn/problem/codevs-2343
