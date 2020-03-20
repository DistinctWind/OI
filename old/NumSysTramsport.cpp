#include <cstdio>
using namespace std;
int n,sys;
inline void transport()
{
	int a[32],i=0;
	while (n!=0)
	{
		a[i++]=n%sys;
		n/=sys;
	}
	while (i!=0)
	{
		int now=a[--i];
		if (now<10) printf("%d",now);
		else printf("%c",now+'A'-10);
	}
	putchar('\n');
}
int main()
{
	scanf("%d%d",&n,&sys);
	transport();
}
