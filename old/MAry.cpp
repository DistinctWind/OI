#include <cstdio>
using namespace std;
const int MAXL=1e6;
int x,m,cnt;
char ans[MAXL];
int main()
{
	scanf("%d%d",&x,&m);
	while (x!=0)
	{
		int tmp=x%m;
		x/=m;
		if (tmp<10)
		{
			ans[++cnt]=tmp+'0';
		}
		else if (tmp>=10)
		{
			ans[++cnt]=tmp-10+'A';
		}
	}
	for (int i=cnt;i>=1;i--)
		putchar(ans[i]);
}
