#include <cstdio>
using namespace std;
const int MAXL=5e5+1;
int n,k;
int c[MAXL];
int lowbit(int x)
{
	return x&(~x+1);
}
inline void update(int pos,int x)
{
	for (;pos<=n;pos+=lowbit(pos))
		c[pos]+=x;
}
int sum(int pos)
{
	int res=0;
	for (;pos>0;pos-=lowbit(pos))
		res+=c[pos];
	return res;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
	{
		char a; int b,c;
		scanf(" %c",&a);
		switch(a)
		{
			case 'A':
				scanf("%d",&b);
				printf("%d\n",sum(b));
				break;
			case 'B':
				scanf("%d%d",&b,&c);
				update(b,c);
				break;
			case 'C':
				scanf("%d%d",&b,&c);
				update(b,-c);
				break;
		}
	}
}
//LOJ https://loj.ac/problem/10116
//VISOJ https://vijos.org/p/1320
