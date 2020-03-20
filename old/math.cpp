#include <cstdio>
using namespace std;
const int MAXN=30000;
bool vis[MAXN+1];
int a,b;
int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%d%d",&a,&b);
	for (int x=0;a*x<=MAXN;x++)
	{
		for (int y=0;a*x+b*y<=MAXN;y++)
			vis[a*x+b*y]=true;
	}
	for (int i=MAXN;i>=1;i--)
		if (!vis[i])
		{
			printf("%d\n",i);
			break;
		}
}
