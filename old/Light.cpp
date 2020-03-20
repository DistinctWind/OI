#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN=2000010;
bool l[MAXN];
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		double a; int t;
		scanf("%lf%d",&a,&t);
		for (int j=1;j<=t;j++)
			l[(int)floor(j*a)]=!l[(int)floor(j*a)];
	}
	for (int i=1;i<=MAXN-1;i++)
		if (l[i])
		{
			printf("%d",i);
			break;
		}
}
