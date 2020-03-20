#include <cstdio>
using namespace std;
const int MAXN=1e5+10;
int n,ans;
int a[MAXN];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=2;i<=n;i++)
		if (a[i]>a[i-1])
			ans+=a[i]-a[i-1];
	printf("%d",ans+a[1]);
}
