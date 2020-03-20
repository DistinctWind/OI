#include <cstdio>
using namespace std;
const int MAXL=5e4+1;
int c1[MAXL],c2[MAXL];
int n,m;
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
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int k,a,b;
		scanf("%d%d%d",&k,&a,&b);
		if (k==1)
		{
			update1(a,1);
			update2(b,1);
		}
		else if (k==2)
		{
			printf("%d\n",sum1(b)-sum2(a-1));
		}
	}
}
//LOJ https://loj.ac/problem/10115
//VISOJ https://vijos.org/p/1448
